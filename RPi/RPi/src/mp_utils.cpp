/*
#include <thread>
#include <chrono>
*/
#include <unistd.h>

void sleep_secs(int seconds) {
	//std::this_thread::sleep_for(std::chrono::seconds(seconds));
	usleep(seconds * 1e6);
}

