#include <stdint.h>

#define I2C_BUS 1			// the /dev/i2c-1 bus
#define MC_I2C_ADDR 0x40	// the PCA9685 is configured to use i2c address 0x40
#define DEF_PWM_FREQ 1000	// default PWM frequency is max frequency, 1 KHz

#define PULSES_PER_RPS 1	// TODO actually calculate this

class Motor {
public:
	Motor(int port);
	void setVel(double vel_rps);
private:
	PCA9685 pwm;
	int port;
};