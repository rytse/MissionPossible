#include <stdint.h>
#include <algorithm>
#include "../include/motor.h"
#include "../include/PCA9685.h"
#include "../include/mp_utils.h"

Motor::Motor(int _port) {
	port = _port;
	pwm.init(I2C_BUS, MC_I2C_ADDR);
	sleep_secs(0.1);
	pwm.setPWMFreq(DEF_PWM_FREQ);
}

/*! Set the motor to a specific velocity in rotations per second */
void Motor::setVel(double vel_rps) {
	pwm.setPWM(port, vel_rps * PULSES_PER_RPS);
	sleep_secs(0.01);
}