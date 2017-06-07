#include "../include/io.h"
#include "../include/main.h"
#include <iostream> 
#include <fstream>
#include <string>

void read_file(teleop_input *ti) {
	std::ifstream _file (IN_FILE_NAME);
	std::string _line;

	_file >> ti->left_vel;
	_file >> ti->right_vel;
	_file >> ti->turret_start;
	_file >> ti->arm_up_start;
	_file >> ti->arm_down_start;
	_file >> ti->stop;

	_file.close();
}
