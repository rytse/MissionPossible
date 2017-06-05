#include "../include/io.h"
#include "../include/main.h"
#include <iostream> 
#include <fstream>
#include <string>

void read_file(teleop_input *ti) {
	std::ifstream _file (IN_FILE_NAME);
	std::string _line;

	getline(_file, _line);
	ti->left_vel = stod(_line);
	getline(_file, _line);
	ti->right_vel = stod(_line);
	getline(_file, _line);
	ti->turret_start = stoi(_line);
	getline(_file, _line);
	ti->arm_up_start = stoi(_line);
	getline(_file, _line);
	ti->arm_down_start = stoi(_line);
	getline(_file, _line);
	ti->stop = stoi(_line);
	_file.close();
}
