import RPi.GPIO as GPIO
from time import sleep

clockUpTime = 1.
clockDownToReadTime = 1.

def __init__(self, SCLK, MOSI, MISO, SS):
	GPIO.setmode(GPIO.BCM)
	self.SCLK = SCLK
	GPIO.setup(SCLK, GPIO.OUT)
	self.MOSI = MOSI
	GPIO.setup(MOSI, GPIO.OUT)
	self.MISO = MISO
	GPIO.setup(MISO, GPIO.IN)
	self.SS = SS
	for chipPort in SS:
		GPIO.setup(chipPort, GPIO.OUT)

def readSensor(self, port, chip):
        toRet = 0
        #Send the start byte of 1.
        for i in range(7):
                spiTransaction(False, chip)
        spiTransaction(True, chip)

        #specify single-ended conversion
        spiTransaction(True, chip)
        #Specify port (0-7)
        for c in '{0:03b}'.format(port):
                spiTransaction(bool(int(c)), chip)

        #Send and recieve 2 garbage bits
        spiTransaction(False, chip)
        spiTransaction(False, chip)

        #Receive the 10 bits of output, from most to least significant.
        for i in range(9, -1, -1):
                toRet += 2^^i * spiTransaction(False, chip)

        return toRet
        

def spiTransaction(self, bit, chip):
        GPIO.output(SCLK, GPIO.LOW)
        for chipPort in self.SS:
                GPIO.output(chipPort, GPIO.HIGH)
        GPIO.output(self.SS[chip], GPIO.LOW)
        if bit:
                GPIO.output(MOSI, GPIO.HIGH)
        else:
                GPIO.output(MOSI, GPIO.LOW)
        GPIO.output(SCLK, GPIO.HIGH)
        sleep(clockUpTime/1000.)
        GPIO.output(SCLK, GPIO.LOW)
        sleep(clockDownToReadTime/1000.)
        return GPIO.input(MISO)

def ConvertVolts(data,places):
  volts = (data * 3.3) / float(1023)
  volts = round(volts,places)
  return volts
	
