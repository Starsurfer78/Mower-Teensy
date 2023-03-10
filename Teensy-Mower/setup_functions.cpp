#include "setup_functions.h"

void initializePins() {
  // Set up pins for sensors and actuators
  pinMode(LEFT_BUMPER_PIN, INPUT_PULLUP);
  pinMode(RIGHT_BUMPER_PIN, INPUT_PULLUP);
  pinMode(ULTRASONIC_TRIGGER_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  pinMode(CUTTER_MOTOR_PIN, OUTPUT);
  pinMode(DRIVE_MOTOR_LEFT_PIN, OUTPUT);
  pinMode(DRIVE_MOTOR_RIGHT_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PERIMETER_PIN, INPUT_PULLUP);
}

void initializeSerial() {
  // Set up serial communication with the computer
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void initializeINA226() {
  // Set up INA226 sensor for current and power measurement
  if (!ina226.begin()) {
    Serial.println("Failed to find INA226 chip");
    while (1) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
      delay(100);
    }
  }
  ina226.setCalibration_32V_2A();
}

void setupFunctions() {
  initializePins();
  initializeSerial();
  initializeINA226();
}
