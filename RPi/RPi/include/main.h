#pragma once

/* Struct representing the robot's desired state
(wheel speeds, currently activated probe, etc.)*/
struct robot_state {
  int temp_sensor_reading;
  int left_light_reading;
  int right_light_reading;
};

int main(void);
void setup(struct robot_state *);
void teardown(void);
void update_hw(struct robot_state *);
