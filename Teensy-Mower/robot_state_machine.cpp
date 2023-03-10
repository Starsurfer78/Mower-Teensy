#include "robot_state_machine.h"

// Constructor
RobotStateMachine::RobotStateMachine() {
  state_ = ROBOT_IDLE;
  charging_threshold_ = 0;
  mowing_mode_ = MODE_RANDOM;
  lane_track_.reset();
  spiral_track_.reset();
}

// Setters
void RobotStateMachine::setChargingThreshold(int threshold) {
  charging_threshold_ = threshold;
}

void RobotStateMachine::setMowingMode(MowingMode mode) {
  mowing_mode_ = mode;
}

// State machine update function
void RobotStateMachine::update(int battery_level, bool docked) {
  switch(state_) {
    case ROBOT_IDLE:
      if (!docked && battery_level <= charging_threshold_) {
        state_ = ROBOT_CHARGING;
      } else if (!docked && battery_level > charging_threshold_) {
        state_ = ROBOT_MOWING;
      }
      break;
    case ROBOT_CHARGING:
      if (docked) {
        state_ = ROBOT_IDLE;
      }
      break;
    case ROBOT_MOWING:
      switch (mowing_mode_) {
        case MODE_RANDOM:
          // Code for random mowing mode
          break;
        case MODE_LANE:
          // Code for lane mowing mode
          break;
        case MODE_SPIRAL:
          // Code for spiral mowing mode
          break;
        default:
          break;
      }
      if (docked || battery_level <= charging_threshold_) {
        state_ = ROBOT_LEAVING_STATION;
      }
      break;
    case ROBOT_LEAVING_STATION:
      // Code for leaving station
      state_ = ROBOT_PERIMETER_TRACK;
      break;
    case ROBOT_PERIMETER_TRACK:
      // Code for perimeter tracking
      state_ = ROBOT_MOWING;
      break;
    default:
      break;
  }
}
