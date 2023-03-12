#include "RobotControl.h"

RobotControl::RobotControl() {
  // initialize the motors
  motor_left = new Motor(PIN_MOTOR_LEFT_PWM, PIN_MOTOR_LEFT_DIR);
  motor_right = new Motor(PIN_MOTOR_RIGHT_PWM, PIN_MOTOR_RIGHT_DIR);
}

void RobotControl::init() {
  // initialize the motors
  motor_left->init();
  motor_right->init();

  // initialize the encoders
  encoder_left = new Encoder(PIN_ENCODER_LEFT_A, PIN_ENCODER_LEFT_B);
  encoder_right = new Encoder(PIN_ENCODER_RIGHT_A, PIN_ENCODER_RIGHT_B);

  // initialize the bumpers
  bumper_front_left = new Bumper(PIN_BUMPER_FRONT_LEFT);
  bumper_front_right = new Bumper(PIN_BUMPER_FRONT_RIGHT);
  bumper_rear_left = new Bumper(PIN_BUMPER_REAR_LEFT);
  bumper_rear_right = new Bumper(PIN_BUMPER_REAR_RIGHT);

  // initialize the sonars
  sonar_left = new Sonar(PIN_SONAR_LEFT_TRIGGER, PIN_SONAR_LEFT_ECHO);
  sonar_right = new Sonar(PIN_SONAR_RIGHT_TRIGGER, PIN_SONAR_RIGHT_ECHO);

  // initialize the perimeter sensor
  perimeter_sensor = new PerimeterSensor(PIN_PERIMETER_LEFT, PIN_PERIMETER_RIGHT);

  // initialize the button
  button = new Button(PIN_BUTTON);

  // initialize the buzzer
  buzzer = new Buzzer(PIN_BUZZER);

  // initialize the rain sensor
  rain_sensor = new RainSensor(PIN_RAIN);
}

void RobotControl::move(int speed_left, int speed_right) {
  motor_left->set_speed(speed_left);
  motor_right->set_speed(speed_right);
}

void RobotControl::forward(int speed) {
  move(speed, speed);
}

void RobotControl::backward(int speed) {
  move(-speed, -speed);
}

void RobotControl::turn_left(int speed) {
  move(-speed, speed);
}

void RobotControl::turn_right(int speed) {
  move(speed, -speed);
}

void RobotControl::stop() {
  move(0, 0);
}

long RobotControl::get_encoder_left() {
  return encoder_left->get_ticks();
}

long RobotControl::get_encoder_right() {
  return encoder_right->get_ticks();
}

void RobotControl::reset_encoders() {
  encoder_left->reset();
  encoder_right->reset();
}

bool RobotControl::get_bumper_front_left() {
  return bumper_front_left->is_pressed();
}

bool RobotControl::get_bumper_front_right() {
  return bumper_front_right->is_pressed();
}

bool RobotControl::get_bumper_rear_left() {
  return bumper_rear_left->is_pressed();
}

bool RobotControl::get_bumper_rear_right() {
  return bumper_rear_right->is_pressed();
}

float RobotControl::get_sonar_left_distance() {
  return sonar_left->get_distance();
}

float RobotControl::get_sonar_right_distance() {
  return sonar_right->get_distance();
}

bool RobotControl::is_perimeter_detected() {
  return perimeter_sensor->is_detected();
}

bool RobotControl::is_button_pressed() {
  return button->is_pressed();
}

void RobotControl::buzz(int frequency, int duration) {
  buzzer->buzz(frequency, duration);
}

bool RobotControl::is_rain_detected() {
  return rain_sensor->is_rain_detected();
}
