#include "Robot.h"

#define KP 2.0
#define KI 0.02
#define KD 0.0

Robot::Robot() : mpu(), motor_left(pinMotorLeftEnable, pinMotorLeftDir, pinMotorLeftPWM), motor_right(pinMotorRightEnable, pinMotorRightDir, pinMotorRightPWM) {}

void Robot::initialize() {
  mpu.initialize();
  //Stop the Motors at Start
  motor_left.stop();
  motor_right.stop();
  bumper.init();
  Ultrasonic leftSonar(pinSonarLeftTrigger, pinSonarLeftEcho);
  Ultrasonic rightSonar(pinSonarRightTrigger, pinSonarRightEcho);
}

void Robot::driveForward(float distance) {
  const float target_angle = 0.0;
  float error = 0.0;
  float prev_error = 0.0;
  float error_sum = 0.0;
  float error_diff = 0.0;
  float output = 0.0;
  const float speed = 0.5;
  const float stop_distance = 1.0;

  motor_left.setSpeed(speed);
  motor_right.setSpeed(speed);

  while (error < stop_distance) {
    error = mpu.getRotationZ();
    error_sum += error;
    error_diff = error - prev_error;
    output = KP * error + KI * error_sum + KD * error_diff;
    motor_left.setSpeed(speed + output);
    motor_right.setSpeed(speed - output);
    delay(10);
    prev_error = error;
  }

  motor_left.stop();
  motor_right.stop();
}

void Robot::rotate(float angle) {
  const float target_angle = angle;
  float error = 0.0;
  float prev_error = 0.0;
  float error_sum = 0.0;
  float error_diff = 0.0;
  float output = 0.0;
  const float speed = 0.5;

  motor_left.setSpeed(speed);
  motor_right.setSpeed(-speed);

  while (abs(error) < abs(target_angle)) {
    error = mpu.getRotationZ() - target_angle;
    error_sum += error;
    error_diff = error - prev_error;
    output = KP * error + KI * error_sum + KD * error_diff;
    motor_left.setSpeed(speed + output);
    motor_right.setSpeed(-speed - output);
    delay(10);
    prev_error = error;
  }

  motor_left.stop();
  motor_right.stop();
}

void Robot::driveStraight(float speed) {
  // Set both motors to the same speed to drive straight
  motor_left.setSpeed(speed);
  motor_right.setSpeed(speed);
}