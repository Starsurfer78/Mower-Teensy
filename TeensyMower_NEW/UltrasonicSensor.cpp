#include <Arduino.h>
#include "src/NewPing.h"
#include "pin_definations.h"
#include "config.h"
#include "UltrasonicSensor.h"

NewPing sonar_left(pinSonarLeftTrigger, pinSonarLeftEcho, MAX_DISTANCE);
NewPing sonar_right(pinSonarRightTrigger, pinSonarRightEcho, MAX_DISTANCE);

int distance;

void readSonarDistances() {
  int leftDistance = sonar_left.ping_cm();
  int rightDistance = sonar_right.ping_cm();

  // Speichern Sie den kleineren der beiden Abstände
  if (leftDistance < rightDistance) {
    distance = leftDistance;
  } else {
    distance = rightDistance;
  }
}

