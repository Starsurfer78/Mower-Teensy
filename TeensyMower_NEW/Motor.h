#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include "pin_definations.h"
#include "config.h"

class Motor {
public:
  public:
    Motor(int left_motor_pwm_pin, int left_motor_dir_pin, int right_motor_pwm_pin, int right_motor_dir_pin);
    void forward(int speed);
    void backward(int speed);
    void turn_left(int speed);
    void turn_right(int speed);
    void stop();
  private:
    int _left_motor_pwm_pin;
    int _left_motor_dir_pin;
    int _right_motor_pwm_pin;
    int _right_motor_dir_pin;
    int _speed;
};
    void setSpeed(int speed);

#endif
