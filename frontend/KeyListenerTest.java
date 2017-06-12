package frontend;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class KeyListenerTester extends JFrame implements KeyListener {
	
	public static final String FILENAME = "out.txt";
	public static final String[] COMMAND = new String[]{"rsync", "-ave", "ssh", 
			"./"+FILENAME, "pi@192.168.42.1:~/"+FILENAME};
	
	private boolean wPressed, aPressed, sPressed, dPressed, qPressed, ePressed, escPressed;

    JLabel label;

    public KeyListenerTester(String s) {
        super(s);
        JPanel p = new JPanel();
        label = new JLabel("Key Listener!");
        p.add(label);
        add(p);
        addKeyListener(this);
        setSize(200, 100);
        setVisible(true);
        wPressed = false;
        aPressed = false;
        sPressed = false;
        dPressed = false;
        ePressed = false;
        qPressed = false;
        escPressed = false;
    }

    @Override
    public void keyTyped(KeyEvent e) {
    	//Do nothing
    }

    @Override
	public void keyPressed(KeyEvent arg0) {
		switch (arg0.getKeyCode()) {
			case KeyEvent.VK_W:
				wPressed = true;
				break;
			case KeyEvent.VK_A:
				aPressed = true;
				break;
			case KeyEvent.VK_S:
				sPressed = true;
				break;
			case KeyEvent.VK_D:
				dPressed = true;
				break;
			case KeyEvent.VK_Q:
				qPressed = true;
				break;
			case KeyEvent.VK_E:
				ePressed = true;
				break;
			case KeyEvent.VK_ESCAPE:
				escPressed = true;
				break;
		}
	}

	@Override
	public void keyReleased(KeyEvent e) {
		switch (e.getKeyCode()) {
			case KeyEvent.VK_W:
				wPressed = false;
				break;
			case KeyEvent.VK_A:
				aPressed = false;
				break;
			case KeyEvent.VK_S:
				sPressed = false;
				break;
			case KeyEvent.VK_D:
				dPressed = false;
				break;
			case KeyEvent.VK_Q:
				qPressed = false;
				break;
			case KeyEvent.VK_E:
				ePressed = false;
				break;
		}
	}

    public boolean isWPressed() {
		return wPressed;
	}

	public boolean isAPressed() {
		return aPressed;
	}

	public boolean isSPressed() {
		return sPressed;
	}

	public boolean isDPressed() {
		return dPressed;
	}

	public boolean isQPressed() {
		return qPressed;
	}

	public boolean isEPressed() {
		return ePressed;
	}

	public boolean isEscPressed() {
		return escPressed;
	}

	public static void main(String[] args) throws Exception {
        KeyListenerTester listener = new KeyListenerTester("Key Listener Tester");
        FileWriter fw = new FileWriter(KeyListenerTester.FILENAME);
        ProcessBuilder pb = new ProcessBuilder(COMMAND);
        String outString;
        String lastString = "";
        while(!listener.isEscPressed()){
        	outString = listener.isWPressed()+","+listener.isAPressed()+","+listener.isSPressed()+","+listener.isDPressed()+","+listener.isQPressed()+","+listener.isEPressed();
        	if (!outString.equals(lastString)){
        		fw.write(outString);
        		fw.close();
        		Process p = pb.start();
        		int val = p.waitFor();
                if (val != 0) {
                    throw new Exception("Exception during RSync; return code = " + val);
                }
        	}
        	lastString = outString;
        }
    }
}
