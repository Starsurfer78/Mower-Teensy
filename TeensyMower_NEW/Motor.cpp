#include "Motor.h"
#include <Arduino.h>
#include "config.h"
#include "pin_definations.h"

Motor::Motor(uint8_t _in1_pin, uint8_t _in2_pin, uint8_t _pwm_pin, float _ticks_per_meter)
{
  in1_pin = _in1_pin;
  in2_pin = _in2_pin;
  pwm_pin = _pwm_pin;
  ticks_per_meter = _ticks_per_meter;
  pinMode(in1_pin, OUTPUT);
  pinMode(in2_pin, OUTPUT);
  pinMode(pwm_pin, OUTPUT);
}

void Motor::setSpeed(float linear_speed)
{
  updateSpeed(linear_speed);
  int pwm_value = map(current_speed, 0, max_linear_speed, MIN_PWM, MAX_PWM);
  analogWrite(pwm_pin, pwm_value);
}

void Motor::stop()
{
  analogWrite(pwm_pin, 0);
}

float Motor::getCurrentSpeed()
{
  return current_speed;
}

void Motor::updateSpeed(float linear_speed)
{
  float target_speed = linear_speed / wheel_circumference * ticks_per_meter * 60.0;
  target_speed = constrain(target_speed, -MAX_SPEED, MAX_SPEED);
  float error = target_speed - current_speed;
  current_speed += constrain(error, -maxAcceleration, maxAcceleration);
}
