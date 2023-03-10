#include "robot_state_machine.h"

RobotStateMachine::RobotStateMachine(SensorController& sensor_controller,
  MotorController& motor_controller, BatteryController& battery_controller, PerimeterController& perimeter_controller, SetupFunctions& setup_functions)
  : _sensor_controller(sensor_controller), _motor_controller(motor_controller), _battery_controller(battery_controller), _perimeter_controller(perimeter_controller), _setup_functions(setup_functions) {
  _mowing_time_ms = 0;
  _mowing_end_time_ms = 0;
  _start_time_ms = 0;
  _stop_time_ms = 0;
  _state = RobotState::IDLE;
}

void RobotStateMachine::set_mowing_time(unsigned long time_ms) {
  _mowing_time_ms = time_ms;
}

void RobotStateMachine::set_mowing_end_time(unsigned long time_ms) {
  _mowing_end_time_ms = time_ms;
}

void RobotStateMachine::set_start_time(unsigned long time_ms) {
  _start_time_ms = time_ms;
}

void RobotStateMachine::set_stop_time(unsigned long time_ms) {
  _stop_time_ms = time_ms;
}

RobotState RobotStateMachine::get_state() {
  return _state;
}

void RobotStateMachine::set_state(RobotState state) {
  _state = state;
}

void RobotStateMachine::run() {
  switch (_state) {
    case RobotState::IDLE:
      if (_setup_functions.start_requested()) {
        _state = RobotState::LEAVE_STATION;
        _setup_functions.set_cutter_motor(true);
      }
      break;

    case RobotState::LEAVE_STATION:
      if (_perimeter_controller.perimeter_signal_detected()) {
        _motor_controller.drive_distance(-50, -50, 200);
        _motor_controller.drive_distance(0, 90, 200);
        _state = RobotState::MOWING;
      } else {
        _setup_functions.buzzer_on();
        _state = RobotState::ERROR;
      }
      break;

      case RobotState::MOWING:
      if (battery.getBatteryPercentage() <= BATTERY_LOW_PERCENTAGE) {
      nextState = RobotState::CHARGING;
      } else if (bumperSensor.isObstacleDetected()) {
      nextState = RobotState::OBSTACLE_AVOIDANCE;
      } else if (ultrasonicSensor.isObstacleDetected()) {
      nextState = RobotState::OBSTACLE_AVOIDANCE;
      } else if (perimeterSensor.isOnPerimeter()) {
      nextState = RobotState::LEAVE_PERIMETER;
      }
      break;

      case RobotState::LEAVE_PERIMETER:
      motorController.driveBackward(50);
      delay(500);
      motorController.stopMotors();
      motorController.turnRight(90);
      delay(500);
      nextState = RobotState::MOWING
      break;

      case RobotState::OBSTACLE_AVOIDANCE:
      motorController.stopMotors();
      delay(500);
      motorController.driveBackward(50);
      delay(500);
      motorController.turnRight(90);
      delay(500);
      nextState = RobotState::MOWING;
      break;

      case RobotState::SEARCH_PERIMETER:
      if (perimeterSensor.isOnPerimeter()) {
      motorController.stopMotors();
      nextState = RobotState::FOLLOW_PERIMETER;
      } else {
      motorController.driveForward(SEARCH_PERIMETER_SPEED);
      }
      break;

      case RobotState::FOLLOW_PERIMETER:
      if (perimeterSensor.isOnPerimeter()) {
      motorController.driveForward(FOLLOW_PERIMETER_SPEED);
      } else {
      motorController.turnLeft(FOLLOW_PERIMETER_TURN_ANGLE);
      delay(FOLLOW_PERIMETER_TURN_DELAY);
      }
      if (perimeterSensor.isAtDockingStation()) {
      motorController.stopMotors();
      nextState = RobotState::CHARGING;
      }
      break;

      case RobotState::CHARGING:
      if (battery.getBatteryPercentage() >= BATTERY_CHARGED_PERCENTAGE) {
      nextState = RobotState::IDLE;
      } else {
      motorController.stopMotors();
      charger.chargeBattery();
      }
      break;

      case RobotState::ERROR:
      buzzer.playTone(ERROR_TONE_FREQUENCY, ERROR_TONE_DURATION);
      nextState = RobotState::IDLE;
      break;
      }
