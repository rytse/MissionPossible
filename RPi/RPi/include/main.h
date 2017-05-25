#pragma once

/* Struct representing the robot's desired state
(wheel speeds, currently activated probe, etc.)*/
struct robot_state {
	double left_m_vel;
	double right_m_vel;

	bool turret_turn;
	double turret_dist_turned;
	
	bool arm_go_up;
	bool arm_go_down;
	bool arm_stay_up;
	bool arm_stay_down;

	bool stop;
};

int main(void);
void setup(struct robot_state *);
void teardown(void);
void update_hw(struct robot_state *);
