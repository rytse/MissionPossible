#include "../include/main.h"
#include "../include/mcp3008Spi.h"

const int TEMP_SENSOR_PORT = 0;
const int LEFT_LIGHT_PORT = 1;
const int RIGHT_LIGHT_PORT = 2;
mcp3008Spi adc;


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
	adc = ()
}

/* Post-program tear down */
void teardown(void) {
}

/* Run every loop to actuate the hardware based on the current robot state machine */
void update_hw(struct robot_state *rs) {
}
