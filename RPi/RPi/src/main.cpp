#include "../include/main.h"
#include "../include/mcp3008Spi.h"

const int TEMP_SENSOR_PORT = 0;
const int LEFT_LIGHT_PORT = 1;
const int RIGHT_LIGHT_PORT = 2;
mcp3008Spi adc("/dev/spidev0.0", SPI_MODE_0, 1000000, 8);


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
	rs->temp_sensor_reading = adc.spiRead(TEMP_SENSOR_PORT);
	rs->left_light_reading = adc.spiRead(LEFT_LIGHT_PORT);
	rs->right_light_reading = adc.spiRead(RIGHT_LIGHT_PORT);
	std::cout << "temp: " << rs->temp_sensor_reading << std::endl;
	std::cout << "temp in volts: " << rs->temp_sensor_reading/1023.0*3.3 << std::endl;
	std::cout << "left light: " << rs->left_light_reading << std::endl;
	std::cout << "right light: " << rs->right_light_reading << std::endl;
}
