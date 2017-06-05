#include "../include/io.h"
#include <iostream> 
#include <fstream>
#include <string>

void read_file(teleop_input pair) {
	ifstream _file = (IN_FILE_NAME);
	string _line;

	getline(_file, _line);
	pair.left_vel = stod(_line);
	getline(_file, _line);
	pair.right_vel = stod(_line);
	getline(_file, _line);
	pair.turret_start = stoi(_line);
	getline(_file, _line);
	pair.arm_up_start = stoi(_line);
	getline(_file, _line);
	pair.arm_down_start = stoi(_line);
	_file.close();
}