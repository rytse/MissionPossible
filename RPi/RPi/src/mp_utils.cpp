#include <thread>
#include <chrono>

void sleep_secs(int seconds) {
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

