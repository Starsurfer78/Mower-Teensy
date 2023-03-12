#include <Arduino.h>
#include <math.h>
#include "pin_definations.h"
#include "config.h"
#include "RobotControl.h"
#include "Motor.h"


void setup_robot() {
  Encoder encoder_left(pinOdometryLeft, TICKS_PER_REV);
  Encoder encoder_right(pinOdometryRight, TICKS_PER_REV);
  //encoder_left.setup();
  //encoder_right.setup();
  //motor_left.setup();
  //motor_right.setup();
}

void drive_forward(float distance) {
  int ticks = distance / (2 * PI * WHEEL_RADIUS) * TICKS_PER_REVOLUTION;
  int target_left = encoder_left.read() + ticks;
  int target_right = encoder_right.read() + ticks;
  while (encoder_left.read() < target_left && encoder_right.read() < target_right) {
    float speed = calculate_speed();
    motor_left.set_speed(speed);
    motor_right.set_speed(speed);
  }
  motor_left.stop();
  motor_right.stop();
}

void turn(float angle) {
  int ticks = angle / 360 * PI * WHEEL_DISTANCE / WHEEL_RADIUS * TICKS_PER_REVOLUTION;
  int target_left = encoder_left.read() + ticks;
  int target_right = encoder_right.read() - ticks;
  while (encoder_left.read() < target_left && encoder_right.read() > target_right) {
    float speed = calculate_speed();
    motor_left.set_speed(speed);
    motor_right.set_speed(-speed);
  }
  motor_left.stop();
  motor_right.stop();
}

float calculate_speed() {
  // calculate and return motor speed based on PID algorithm
}
