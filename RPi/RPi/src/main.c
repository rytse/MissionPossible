#include "../include/main.h"
#include "../include/bcm/bcm2835.h"
#include "../include/motorcontroller.h"

int main(void) {
	struct robot_state rs;

	setup(&rs);

	while (1) {
		/*update_hw(&rs);*/
		setPin(11, 1026, 0);
	}

	teardown();
}

/* Initial setup before main loop runs */
void setup(struct robot_state *rs) {
	bcm2835_init();
}

/* Post-program tear down */
void teardown(void) {
	bcm2835_close();
}

/* Run every loop to actuate the hardware based on the current robot state machine */
void update_hw(struct robot_state *rs) {
}