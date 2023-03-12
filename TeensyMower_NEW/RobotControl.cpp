#include "RobotControl.h"
#include "Encoder.h"
#include "Motor.h"

Encoder encoder_left(pinOdometryLeft);
Encoder encoder_right(pinOdometryRight);
Motor motor_left(6, 7, 9);
Motor motor_right(8, 10, 11);

void setup_robot() {
  encoder_left.setup();
  encoder_right.setup();
  motor_left.setup();
  motor_right.setup();
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
