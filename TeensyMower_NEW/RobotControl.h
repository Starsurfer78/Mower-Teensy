#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H

#include "Arduino.h"
#include "config.h"
#include "Motor.h"
#include "Encoder.h"
#include "UltrasonicSensor.h"
#include "Bumper.h"
#include "PerimeterSensor.h"

class RobotControl {
  public:
    RobotControl();
    void init();
    void start();
    void stop();
    void loop();

  private:
    Motor _motor_left;
    Motor _motor_right;
    Encoder _encoder_left;
    Encoder _encoder_right;
    UltrasonicSensor _sonar_left;
    UltrasonicSensor _sonar_right;
    Bumper _bumper_front_left;
    Bumper _bumper_front_right;
    Bumper _bumper_rear_left;
    Bumper _bumper_rear_right;
    PerimeterSensor _perimeter_left;
    PerimeterSensor _perimeter_right;

    void _move_forward(int speed);
    void _move_backward(int speed);
    void _turn_left(int speed);
    void _turn_right(int speed);
    void _stop();
    void _check_bumpers();
    void _check_ultrasonic();
    void _check_perimeter();
    void _update_odometry();
};

#endif
