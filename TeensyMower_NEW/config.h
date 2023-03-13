#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include "pin_definations.h"
#include <math.h>

// Global Configuration Variables
extern const float WHEEL_BASE;     // Wheel distance in Meter
extern const float ROBOT_LENGTH; // Length of the mower robot in meters
extern const float TICKS_PER_REV;
extern const float WHEEL_DIAMETER;
extern const int MAX_SPEED;         // in RPM
extern const int MIN_SPEED;          // in RPM
extern const int MAX_PWM;          // Maximum Speed in PWM
extern const int MIN_PWM;          // Minimum Speed in PWM
extern const float maxAcceleration;  // Maximum acceleration in metres per second^2
extern const int pwmFrequency; // PWM-Frequenz
extern const float batFull;                  // How many volts does the battery have when it is full?
extern const float batGoHomeIfBelow;         // At how many volts should it drive back to the station?
extern const float batSwitchOffIfBelow;      // At how many volts should the robot be switched off?
extern const bool usestation;        // true/false Did the Roboter use a Charging Station?
extern const bool leavestationdirection; // true/false In which direction should the robot turn after it has left the station?
extern const bool usesonar;        // true/false Did the Robot use Ultrasonic Sensors?
extern const float MAX_DISTANCE_SONAR;    // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
extern const int OBSTACLE_DISTANCE;   // Standard distance to obstacle
extern const bool usesbumper;       // true/false Did the Robot use Ultrasonic Sensors?
extern const bool sonarfront;       // Use Bumper Left and Right on Front?
extern const bool sonarrear;        // Use Bumper Left and Right on Rear?
extern const bool usesgps;        // true/false Did the Robot use GPS?
extern const bool usestimer;       // true/false Timer to set the mowing times
extern const int Teensy_BAUDRATE;
extern const HardwareSerial& ESP32Port;  // Teensymower default OK for ESP32
extern const int ESP32_BAUDRATE;
extern const HardwareSerial& GpsPort;  // GPS 
extern const int inaMotorLeftAddr;
extern const int inaMotorRightAddr;
extern const int inaCutterAddr;
extern const int inaBattAddr;

extern const float ticks_per_meter;
extern const float max_ticks_per_second;
extern const float max_linear_speed;
extern const float wheel_circumference;

#endif

