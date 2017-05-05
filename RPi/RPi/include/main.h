#pragma once

/* Struct representing the robot's desired state
(wheel speeds, currently activated probe, etc.)*/
struct robot_state {
};

int main(void);
void setup(struct robot_state *);
void teardown(void);
void update_hw(struct robot_state *);
