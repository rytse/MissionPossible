#include "../include/io.h"
#include <iostream> 
#include <fstream>
#include <string>

void read_file(teleop_input pair) {
	ifstream _file = (IN_FILE_NAME);
	string _line;

	pair.left_vel = stod(getline(_file, _line));
	pair.right_vel = stod(getline(_file, _line));
	_file.close();
}