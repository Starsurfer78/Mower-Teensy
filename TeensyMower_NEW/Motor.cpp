#include "Motor.h"

Motor::Motor(int left_motor_pwm_pin, int left_motor_dir_pin, int right_motor_pwm_pin, int right_motor_dir_pin) {
  _left_motor_pwm_pin = left_motor_pwm_pin;
  _left_motor_pin_2 = left_motor_dir_pin;
  _right_motor_pwm_pin = right_motor_pwm_pin;
  _right_motor_pin_2 = right_motor_dir_pin;
}

void Motor::init() {
    pinMode(_pwm_pin, OUTPUT);
    pinMode(_dir_pin, OUTPUT);
}

void Motor::setSpeed(int speed) {
    _speed = constrain(speed, MIN_SPEED, MAX_SPEED);
    analogWrite(_pwm_pin, _speed);
}


void Motor::forward(int speed) {
  analogWrite(_left_motor_pwm_pin, speed);
  analogWrite(_left_motor_dir_pin, 0);
  analogWrite(_right_motor_pwm_pin, speed);
  analogWrite(_right_motor_dir_pin, 0);
}

void Motor::backward(int speed) {
  analogWrite(_left_motor_dir_pin, 0);
  analogWrite(_left_motor_pwm_pin, speed);
  analogWrite(_right_motor_dir_pin, 0);
  analogWrite(_right_motor_pwm_pin, speed);
}

void Motor::turn_left(int speed) {
  analogWrite(_left_motor_dir_pin, 0);
  analogWrite(_left_motor_pwm_pin, speed);
  analogWrite(_right_motor_pwm_pin, speed);
  analogWrite(_right_motor_dir_pin, 0);
}

void Motor::turn_right(int speed) {
  analogWrite(_left_motor_pwm_pin, speed);
  analogWrite(_left_motor_dir_pin, 0);
  analogWrite(_right_motor_dir_pin, 0);
  analogWrite(_right_motor_pwm_pin, speed);
}

void Motor::stop() {
  analogWrite(_left_motor_dir_pin, 0);
  analogWrite(_left_motor_pwm_pin, 0);
  analogWrite(_right_motor_dir_pin, 0);
  analogWrite(_right_motor_pwm_pin, 0);
}
