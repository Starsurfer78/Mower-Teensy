#include <Arduino.h>
#include "config.h"
#include "pin_definations.h"
#include "Motor.h"
#include "Encoder.h"

Motor::Motor(int left_motor_pwm_pin, int left_motor_dir_pin, int right_motor_pwm_pin, int right_motor_dir_pin) :
    _left_motor_pwm_pin(left_motor_pwm_pin), _left_motor_dir_pin(left_motor_dir_pin),
    _right_motor_pwm_pin(right_motor_pwm_pin), _right_motor_dir_pin(right_motor_dir_pin) {
}

void Motor::init() {
    pinMode(_left_motor_pwm_pin, OUTPUT);
    pinMode(_left_motor_dir_pin, OUTPUT);
    pinMode(_right_motor_pwm_pin, OUTPUT);
    pinMode(_right_motor_dir_pin, OUTPUT);
    stop();
}

void Motor::setSpeed(int speed) {
    _speed = speed;
    analogWrite(_left_motor_pwm_pin, _speed);
    analogWrite(_right_motor_pwm_pin, _speed);
}

void Motor::forward(int speed) {
    digitalWrite(_left_motor_dir_pin, LOW);
    digitalWrite(_right_motor_dir_pin, LOW);
    setSpeed(speed);
}

void Motor::backward(int speed) {
    digitalWrite(_left_motor_dir_pin, HIGH);
    digitalWrite(_right_motor_dir_pin, HIGH);
    setSpeed(speed);
}

void Motor::turn_left(int speed) {
    digitalWrite(_left_motor_dir_pin, HIGH);
    digitalWrite(_right_motor_dir_pin, LOW);
    setSpeed(speed);
}

void Motor::turn_right(int speed) {
    digitalWrite(_left_motor_dir_pin, LOW);
    digitalWrite(_right_motor_dir_pin, HIGH);
    setSpeed(speed);
}

void Motor::stop() {
    digitalWrite(_left_motor_dir_pin, LOW);
    digitalWrite(_right_motor_dir_pin, LOW);
    analogWrite(_left_motor_pwm_pin, 0);
    analogWrite(_right_motor_pwm_pin, 0);
}
