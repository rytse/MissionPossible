#pragma once

#define IN_FILE_NAME "exchange.txt"

struct teleop_input {
	double left_vel;
	double right_vel;
};

void read_file(teleop_input pair);