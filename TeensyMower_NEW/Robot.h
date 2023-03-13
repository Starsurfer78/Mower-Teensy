#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>
#include "Motor.h"
#include "src/MPU6050.h"
#include "config.h"

class Robot {
  public:
    Robot();
    void initialize();
    void driveForward(float distance);
    void rotate(float angle);
    void driveStraight(float speed);
  private:
    MPU6050 mpu;
    Motor motor_left;
    Motor motor_right;
};

#endif

