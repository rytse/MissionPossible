#include <bcm2835.h>
#include <stdint.h>
#include <algorithm>
#include "../include/motorcontroller.h"

using namespace std;

char *u16_2_c(uint16_t u16) {
	return (char *) &u16;
}

/* write8 function translated from the Adafruit PWM Servo Driver library
*/
void write8(uint8_t addr, uint8_t d) {
	char db = (char) d;
	bcm2835_i2c_begin();
	bcm2835_i2c_setSlaveAddress(addr);
	bcm2835_i2c_write(&db, 1);
	bcm2835_i2c_end();
}

/* read8 function translated from the Adafruit PWM Servo Driver library
*/
uint8_t read8(uint8_t addr) {
	char db;
	bcm2835_i2c_begin();
	bcm2835_i2c_setSlaveAddress(addr);
	bcm2835_i2c_read(&db, 1);
	return (uint8_t) db;
}

/* setPWM function translated from the Adafruit PWM Servo Driver library
*/
void setPWM(uint8_t addr, uint8_t num, uint16_t on, uint16_t off) {
	char *cp_on = (char *) &on;
	char *cp_off = (char *) &off;


	bcm2835_i2c_begin();
	bcm2835_i2c_setSlaveAddress(addr);
	bcm2835_i2c_write(u16_2_c(4 * num + LED0_ON_L), 2);
	bcm2835_i2c_write(u16_2_c(on), 2);
	bcm2835_i2c_write(u16_2_c(on >> 8), 2);
	bcm2835_i2c_write(u16_2_c(off), 2);
	bcm2835_i2c_write(u16_2_c(off >> 8), 2);
	bcm2835_i2c_end();
}

/*
void setPin(uint8_t num, uint16_t val, bool invert) {
	// Clamp value between 0 and 4095 inclusive.
	val = val <= 4096 ? val : 4096;
	if (invert) {
		if (val == 0) {
			// Special value for signal fully on.
			setPWM(num, 4096, 0);
		}
		else if (val == 4095) {
			// Special value for signal fully off.
			setPWM(num, 0, 4096);
		}
		else {
			setPWM(num, 0, 4095 - val);
		}
	}
	else {
		if (val == 4095) {
			// Special value for signal fully on.
			setPWM(num, 4096, 0);
		}
		else if (val == 0) {
			// Special value for signal fully off.
			setPWM(num, 0, 4096);
		}
		else {
			setPWM(num, 0, val);
		}
	}
}
*/