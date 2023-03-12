#ifndef MOTORS_H
#define MOTORS_H

#include "pin_definations.h"
#include "config.h"

// Variablen
int left_ticks = 0;
int right_ticks = 0;
int last_left_ticks = 0;
int last_right_ticks = 0;
float distance = 0.0;

// PID-Regler
float error = 0;
float last_error = 0;
float total_error = 0;
float speed = 0;
float last_speed = 0;


// Funktionen
void resetEncoders() {
  left_ticks = 0;
  right_ticks = 0;
}

float calculateDistance() {
  float revolutions = (left_ticks + right_ticks) / 2.0 / TICKS_PER_REVOLUTION;
  return revolutions * WHEEL_CIRCUMFERENCE;
}

// PID-Regelungsfunktion
void adjust_speed(float error) {
  total_error += error;
  speed = KP * error + KI * total_error + KD * (error - last_error);
  last_error = error;
  if (speed < 0) speed = 0;
  if (speed > 255) speed = 255;
}

// Drive a certain distance
// Usage: moveForward(3.0, MAX_PWM); // 3 metres at full speed
void moveForward(float target_distance, int motor_speed) {
  resetEncoders();
  while (distance < target_distance) {
    // Motorsteuerung
    analogWrite(pinMotorLeftPWM, motor_speed);
    analogWrite(pinMotorRightPWM, motor_speed);

    // Tick-Zähler-Updates
    left_ticks += digitalRead(pinOdometryLeft);
    right_ticks += digitalRead(pinOdometryRight);

    // Distanz-Update
    distance = calculateDistance();
  }
  // Motor stoppen
  analogWrite(pinMotorLeftPWM, 0);
  analogWrite(pinMotorRightPWM, 0);
}

// Function to calculate the speed
float calculate_speed(int left_ticks, int left_ticks, float target_speed) {
  unsigned long current_time = millis();
  float delta_t = (current_time - previous_time) / 1000.0;
  
  if (delta_t == 0) {
    // avoid division by zero
    Serial.println("Error: Delta t is zero");
    return 0;
  }
  
  float delta_ticks_left = left_ticks - previous_ticks_left;
  float delta_ticks_right = right_ticks - previous_ticks_right;
  
  float distance_left = (delta_ticks_left / TICKS_PER_REV) * WHEEL_CIRCUMFERENCE;
  float distance_right = (delta_ticks_right / TICKS_PER_REV) * WHEEL_CIRCUMFERENCE;
  
  float speed_left = distance_left / delta_t;
  float speed_right = distance_right / delta_t;
  
  float speed = (speed_left + speed_right) / 2.0;
  
  previous_time = current_time;
  previous_ticks_left = left_ticks;
  previous_ticks_right = right_ticks;
  
  return speed;
}


#endif