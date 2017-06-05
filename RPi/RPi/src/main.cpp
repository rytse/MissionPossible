#include "../include/main.h"
#include "../include/motor.h"
#include "../include/constants.h"
#include "../include/io.h"

static Motor left_m (13);	// left drive motor
static Motor right_m (15);	// right drive motor
static Motor arm_m (2);		// flag / temperature sensor arm motor
static Motor turret_m (3);	// light sensor turret motor

int main(void) {
	struct robot_state _rs;

	setup(&_rs);

	while (!_rs.stop) {
		update_rs(&_rs);
		update_hw(&_rs);
	}

	teardown();
}

/* Initial setup before main loop runs */
void setup(struct robot_state *rs) {
	/*
	left_m = Motor(1);
	right_m = Motor(2);
	arm_m = Motor(3);
	turret_m = Motor(0);
	*/

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

/*! Post-program tear down */
void teardown(void) {
}

/*! Runs every loop to read input and update the robot state machine in software.
	Encapsulated from actual harware modifications.
*/
void update_rs(struct robot_state *rs) {
	static teleop_input _ip;
	read_file(_ip);
	rs->left_m_vel = _ip.left_vel;
	rs->right_m_vel = _ip.right_vel;
}
/*! Run every loop to actuate the hardware based on the current robot state machine */
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