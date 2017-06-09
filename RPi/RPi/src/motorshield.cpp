#include "../include/motorshield.h"
#include "../include/wiringPi.h"

Motorshield::Motorshield(int _fwd, int _rev, int _e) {
	fwd = _fwd;
	rev = _rev;
	e = _e;

	wiringPiSetupGpio();
	
	pinMode(_fwd, OUTPUT);
	pinMode(_rev, OUTPUT);
	pinMode(_e, PWM_OUTPUT);

	pwmSetClock(50);	// TODO make this not wrong
}

Motorshield::~Motorshield(void) {
	digitalWrite(fwd, LOW);
	digitalWrite(rev, LOW);
	pwmWrite(e, 0);
}

void Motorshield::set_vel(double vel) {
	if (vel >= 0) {
		digitalWrite(fwd, HIGH);
		digitalWrite(rev, LOW);
		pwmWrite(e, vel);
	} else {
		digitalWrite(fwd, LOW);
		digitalWrite(rev, HIGH);
		pwmWrite(e, -vel);
	}
}