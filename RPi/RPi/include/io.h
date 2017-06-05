#pragma once

#define IN_FILE_NAME "exchange.txt"

struct teleop_input {
	double left_vel;
	double right_vel;

	bool turret_start;

	bool arm_up_start;
	bool arm_down_start;
};

void read_file(teleop_input pair);