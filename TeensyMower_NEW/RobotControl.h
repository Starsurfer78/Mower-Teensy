#ifndef ROBOT_CONTROL_H
#define ROBOT_CONTROL_H

#include "Arduino.h"
#include "config.h"
#include "Motor.h"
#include "Bumpers.h"
#include "Encoder.h"

class RobotControl {
  public:
    RobotControl();
    void init();
    void set_speed(int left_speed, int right_speed);
    void stop_motors();
    void check_bumpers();
    bool bumper_left_pressed();
    bool bumper_right_pressed();
    long left_wheel_distance();
    long right_wheel_distance();
    long distance();
    float orientation();
  private:
    Motor _left_motor;
    Motor _right_motor;
    Bumpers _bumpers;
    Encoder _encoder_left;
    Encoder _encoder_right;
    volatile long _left_encoder_ticks = 0;
    volatile long _right_encoder_ticks = 0;
    float _x = 0.0;
    float _y = 0.0;
    float _theta = 0.0;
    void update_position();
};

#endif
