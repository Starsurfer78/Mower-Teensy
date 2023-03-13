#include "Ultrasonic.h"
#include <Arduino.h>
#include "config.h"
#include "pin_definations.h"

Ultrasonic::Ultrasonic(uint8_t triggerPin, uint8_t echoPin)
  : triggerPin(triggerPin), echoPin(echoPin), sonar(triggerPin, echoPin, 300) {}

uint16_t Ultrasonic::getDistance() {
  return sonar.ping_cm();
}
