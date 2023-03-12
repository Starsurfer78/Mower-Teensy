#include <Arduino.h>
#include "config.h"
#include "pin_definations.h"
#include "RobotControl.h"

RobotControl::RobotControl() :
    _left_motor(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_DIR_PIN, RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_DIR_PIN),
    _right_motor(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_DIR_PIN, LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_DIR_PIN),
    _bumpers(BUMPER1_PIN, BUMPER2_PIN),
    _left_encoder_ticks(0),
    _right_encoder_ticks(0)
{}

void RobotControl::init() {
  _left_motor.init();
  _right_motor.init();
  _bumpers.init();
  _encoder_left.init();
  _encoder_right.init();
}

void RobotControl::set_speed(int left_speed, int right_speed) {
  // Set motor speed
  _left_motor.set_speed(left_speed);
  _right_motor.set_speed(right_speed);
}

void RobotControl::stop_motors() {
  // Stop both motors
  _left_motor.stop();
  _right_motor.stop();
}

void RobotControl::check_bumpers() {
  // Check if bumpers are pressed and stop motors if so
  if (_bumpers.left_pressed() || _bumpers.right_pressed()) {
    stop_motors();
  }
}

bool RobotControl::bumper_left_pressed() {
  // Check if left bumper is pressed
  return _bumpers.left_pressed();
}

bool RobotControl::bumper_right_pressed() {
  // Check if right bumper is pressed
  return _bumpers.right_pressed();
}

void RobotControl::update_position() {
  // calculate distance travelled by each wheel
  long left_ticks = _encoder_left.get_ticks();
  long right_ticks = _encoder_right.get_ticks();
  long left_delta = left_ticks - _left_encoder_ticks;
  long right_delta = right_ticks - _right_encoder_ticks;
  _left_encoder_ticks = left_ticks;
  _right_encoder_ticks = right_ticks;

  float left_distance = left_delta * TICK_TO_DIST;
  float right_distance = right_delta * TICK_TO_DIST;

  // calculate orientation
  float delta_theta = (right_distance - left_distance) / WHEEL_BASE;
  _theta += delta_theta;

  // calculate distance travelled by the robot
  float distance_travelled = (left_distance + right_distance) / 2.0;

  // update position
  float delta_x = distance_travelled * cos(_theta);
  float delta_y = distance_travelled * sin(_theta);
  _x += delta_x;
  _y += delta_y;
}

// Get the left wheel distance in millimeters
long RobotControl::left_wheel_distance() {
  return _encoder_left.get_ticks() * TICK_TO_MM;
}

// Get the right wheel distance in millimeters
long RobotControl::right_wheel_distance() {
  return _encoder_right.get_ticks() * TICK_TO_MM;
}

// Get the distance travelled by the robot in millimeters
long RobotControl::distance() {
  return (left_wheel_distance() + right_wheel_distance()) / 2;
}

// Get the orientation of the robot in radians
float RobotControl::orientation() {
  float orientation = _theta;
  while (orientation > PI) {
    orientation -= 2 * PI;
  }
  while (orientation <= -PI) {
    orientation += 2 * PI;
  }
  return orientation;
}
