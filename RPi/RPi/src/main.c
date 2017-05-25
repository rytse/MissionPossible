#include "../include/main.h"

int main(void) {
	struct robot_state rs;

	setup(&rs);

	while (1) {
		update_hw(&rs);
	}

	teardown();
}

/* Initial setup before main loop runs */
void setup(struct robot_state *rs) {
}

/* Post-program tear down */
void teardown(void) {
}

/* Run every loop to actuate the hardware based on the current robot state machine */
void update_hw(struct robot_state *rs) {
}