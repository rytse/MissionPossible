#include "../include/main.h"
#include "../include/motor.h"
#include "../include/motorshield.h"
#include "../include/constants.h"
#include "../include/io.h"

/*
static Motor left_m (13);	// left drive motor
static Motor right_m (15);	// right drive motor
static Motor arm_m (2);		// flag / temperature sensor arm motor
static Motor turret_m (3);	// light sensor turret motor
*/

static Motorshield ms(15, 13, 11);


int main(void) {
	struct robot_state _rs;

	setup(&_rs);

	while (!_rs.stop) {
		
		update_rs(&_rs);
		update_hw(&_rs);
	}

	teardown();
}

/*! Initial setup before main loop runs */
void setup(struct robot_state *rs) {
	/*
	left_m = Motor(1);
	right_m = Motor(2);
	arm_m = Motor(3);
	turret_m = Motor(0);
	*/

	rs->left_m_enc_inc = 0;
	rs->right_m_enc_inc = 0;
	rs->turret_enc_inc = 0;
	rs->arm_enc_inc = 0;

	rs->left_m_vel = 0;
	rs->right_m_vel = 0;

	rs->turret_turn = 0;

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
	static teleop_input ip;
	static double turret_pos = 0;
	static double arm_pos = 0;

	read_file(&ip);

	rs->left_m_vel = ip.left_vel;
	rs->right_m_vel = ip.right_vel;

	// Turret turn
	rs->turret_turn = ip.turret_start;
	turret_pos += rs->turret_enc_inc;
	if (turret_pos >= TURRET_DIST) {
		rs->turret_turn = false;
	}

	// Arm turn
	rs->arm_go_up = ip.arm_up_start;
	rs->arm_go_down = ip.arm_down_start;
	if (arm_pos > ARM_UP_POS) {
		rs->arm_go_up = false;
	}
	else if (arm_pos < ARM_DOWN_POS) {
		rs->arm_go_down = false;
	}

	rs->stop = ip.stop;
}

/*! Run every loop to actuate the hardware based on the current robot state machine */
void update_hw(struct robot_state *rs) {
	/*
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
	*/

	ms.set_vel(rs->left_m_vel);

	// TODO read encoders
}