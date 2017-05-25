#include "../include/main.h"
#include "../include/motor.h"
#include "../include/constants.h"

static Motor left_m;	// left drive motor
static Motor right_m;	// right drive motor
static Motor arm_m;		// flag / temperature sensor arm motor
static Motor turret_m;	// light sensor turret motor

int main(void) {
	struct robot_state rs;

	setup(&rs);

	while (!rs.stop) {
		update_hw(&rs);
	}

	teardown();
}

/* Initial setup before main loop runs */
void setup(struct robot_state *rs) {
	left_m = Motor(1);
	right_m = Motor(2);
	arm_m = Motor(3);
	turret_m = Motor(4);

	rs->left_m_vel = 0;
	rs->right_m_vel = 0;
	rs->turret_turn = 0;
	rs->turret_dist_turned = 0;
	rs->arm_go_up = 0;
	rs->arm_go_down = 0;
	rs->arm_stay_up = 1;
	rs->arm_stay_down = 0;
	rs->stop = 0;
}

/* Post-program tear down */
void teardown(void) {
}

/* Run every loop to actuate the hardware based on the current robot state machine */
void update_hw(struct robot_state *rs) {
	left_m.setVel(rs->left_m_vel);
	right_m.setVel(rs->right_m_vel);

	if (rs->turret_turn) {
		turret_m.setVel(TURRET_VEL);
	}

	if (rs->arm_go_up) {
		arm_m.setVel(ARM_VEL);
	} else if (rs->arm_go_down) {
		arm_m.setVel(ARM_VEL * -1);
	}

	// TODO read encoders
}