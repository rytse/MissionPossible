import RPi.GPIO as GPIO
from time import sleep

clockUpTime = 1.
clockDownToReadTime = 1.
class mcp3008:

	def __init__(self, SCLK, MOSI, MISO, SS):
		GPIO.setmode(GPIO.BOARD)
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
			self.spiTransaction(False, chip)
		self.spiTransaction(True, chip)

		#specify single-ended conversion
		self.spiTransaction(True, chip)
		#Specify port (0-7)
		for c in '{0:03b}'.format(port):
			self.spiTransaction(bool(int(c)), chip)

		#Send and recieve 2 garbage bits
		self.spiTransaction(False, chip)
		self.spiTransaction(False, chip)

		#Receive the 10 bits of output, from most to least significant.
		for i in range(9, -1, -1):
			toRet += 2^^i * self.spiTransaction(False, chip)

		return toRet


	def spiTransaction(self, bit, chip):
		#Clock off
		GPIO.output(self.SCLK, GPIO.LOW)

		#Deselect all chips
		for chipPort in self.SS:
			GPIO.output(self.chipPort, GPIO.HIGH)

		#Select the given chip
		GPIO.output(self.SS[chip], GPIO.LOW)

		#Send the bit
		if bit:
			GPIO.output(self.MOSI, GPIO.HIGH)
		else:
			GPIO.output(self.MOSI, GPIO.LOW)

		#Clock rising edge, so chip reads in the GPIO output
		GPIO.output(self.SCLK, GPIO.HIGH)

		#Give the chip time to process
		sleep(clockUpTime/1000.)

		#Clock falling edge, so chip sends the bit back
		GPIO.output(self.SCLK, GPIO.LOW)

		#Give the chip time to send signal
		sleep(clockDownToReadTime/1000.)

		#Read the input pin
		return GPIO.input(self.MISO)

	def convertVolts(data,places):
		volts = (data * 3.3) / float(1023)
		volts = round(volts,places)
		return volts

chip = mcp3008(37,35,33,[31])
while True:
	print(chip.convertVolts(chip.readSensor(0, 0), 2))
