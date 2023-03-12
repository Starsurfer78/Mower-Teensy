#ifndef ROBOT_CONTROL_H
#define ROBOT_CONTROL_H

#include <Arduino.h>
#include "config.h"
#include "pin_definations.h"
#include "Motor.h"
#include "Bumpers.h"
#include "Encoder.h"

class RobotControl {
  public:
    // Constructor
    RobotControl();

    // Initialize motors, bumpers, and encoders
    void init();

    // Set left and right motor speed
    void set_speed(int left_speed, int right_speed);

    // Stop both motors
    void stop_motors();

    // Check if bumpers are pressed
    void check_bumpers();

    // Check if left bumper is pressed
    bool bumper_left_pressed();

    // Check if right bumper is pressed
    bool bumper_right_pressed();

    // Get left wheel distance in ticks
    long left_wheel_distance();

    // Get right wheel distance in ticks
    long right_wheel_distance();

    // Get total distance traveled by robot in ticks
    long distance();

    // Get robot orientation in degrees
    float orientation();

  private:
    Motor _left_motor;              // Left motor object
    Motor _right_motor;             // Right motor object
    Bumpers _bumpers;               // Bumpers object
    Encoder _encoder_left;          // Left encoder object
    Encoder _encoder_right;         // Right encoder object
    volatile long _left_encoder_ticks = 0;    // Number of ticks recorded by left encoder
    volatile long _right_encoder_ticks = 0;   // Number of ticks recorded by right encoder
    float _x = 0.0;                 // X position of robot in cm
    float _y = 0.0;                 // Y position of robot in cm
    float _theta = 0.0;             // Orientation of robot in degrees

    // Update robot position based on encoder ticks
    void update_position();
};

#endif
