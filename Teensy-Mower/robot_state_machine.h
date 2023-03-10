// States des Roboters
enum class RobotState {
  IDLE,
  CHARGING,
  MOWING,
  LEAVING_STATION,
  PERIMETER_TRACKING
};

// Mögliche Mähmodi
enum class MowMode {
  RANDOM,
  LANE,
  SPIRAL
};

// Initialer Zustand des Roboters
RobotState robotState = RobotState::IDLE;

// Initialer Mähmodus
MowMode mowMode = MowMode::RANDOM;

// Zustandsübergänge des Roboters
void updateRobotState() {
  switch (robotState) {
    case RobotState::IDLE:
      // Wenn der Akku unter einen bestimmten Wert fällt, wechsle in CHARGING State
      if (batteryLevel < 20) {
        robotState = RobotState::CHARGING;
      }
      // Wenn ein Mähmodus ausgewählt wurde, wechsle in MOWING State
      else if (mowMode != MowMode::RANDOM) {
        robotState = RobotState::MOWING;
      }
      break;

    case RobotState::CHARGING:
      // Wenn der Akku voll aufgeladen ist, wechsle in IDLE State
      if (batteryLevel == 100) {
        robotState = RobotState::IDLE;
      }
      break;

    case RobotState::MOWING:
      // Wenn der Akku unter einen bestimmten Wert fällt, wechsle in LEAVING_STATION State
      if (batteryLevel < 20) {
        robotState = RobotState::LEAVING_STATION;
      }
      break;

    case RobotState::LEAVING_STATION:
      // Wenn der Roboter die Ladestation verlassen hat, wechsle in PERIMETER_TRACKING State
      if (!isOnCharger()) {
        robotState = RobotState::PERIMETER_TRACKING;
      }
      break;

    case RobotState::PERIMETER_TRACKING:
      // Wenn der Akku voll aufgeladen ist, wechsle in CHARGING State
      if (batteryLevel == 100) {
        robotState = RobotState::CHARGING;
      }
      // Wenn ein Mähmodus ausgewählt wurde, wechsle in MOWING State
      else if (mowMode != MowMode::RANDOM) {
        robotState = RobotState::MOWING;
      }
      break;
  }
}
