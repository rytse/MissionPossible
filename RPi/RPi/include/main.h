#pragma once

/* Struct representing the robot's desired state
(wheel speeds, currently activated probe, etc.)*/
struct robot_state {
	double left_m_enc_inc;
	double right_m_enc_inc;
	double turret_enc_inc;
	double arm_enc_inc;

	double left_m_vel;
	double right_m_vel;

	bool turret_turn;
	
	bool arm_go_up;
	bool arm_go_down;
	bool arm_stay_up;
	bool arm_stay_down;

	bool stop;
};

int main(void);
void setup(struct robot_state *);
void teardown(void);
void update_rs(struct robot_state *rs);
void update_hw(struct robot_state *rs);
