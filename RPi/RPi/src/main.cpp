#include "../include/main.h"
#include "../include/motor.h"

int main(void) {
	struct robot_state rs;

	setup(&rs);

	Motor m0 = Motor(1);

	while (1) {
		m0.setVel(4095);
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