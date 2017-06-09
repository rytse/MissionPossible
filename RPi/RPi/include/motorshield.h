#pragma once

#define MOTOR1_

class Motorshield {
public:
	Motorshield(int _fwd, int _rev, int _e);
	~Motorshield(void);
	void set_vel(double vel);
private:
	int fwd;
	int rev;
	int e;
};
