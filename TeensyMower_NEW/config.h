#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include "config.h"
#include "pin_definations.h"
#include <math.h>

#define MowerName "MatrixMOW"
#define PCB_V103 true


const int TICKS_PER_REV = 1300;    // Encoder-Impulse 1200   // WHEEL Pulses per wheel revolution
const float WHEEL_RADIUS = 0.05;   // Wheel Radius in Meter
const float WHEEL_BASE = 0.25;     // Wheel distance in Meter
const float ROBOT_LENGTH = 0.5; // Length of the mower robot in meters

const int MAX_SPEED = 200;         // in RPM
const int MIN_SPEED = 50;          // in RPM

const int MAX_PWM = 180;          // Maximum Speed in PWM
const int MIN_PWM = 180;          // Minimum Speed in PWM

const float maxAcceleration = 0.5;  // Maximum acceleration in metres per second^2

const int pwmFrequency = 3200; // PWM-Frequenz


// motor wheel PID controller
#define motorLeftPID_Kp 1.0
#define motorLeftPID_Ki 0.4
#define motorLeftPID_Kd 0.0

#define motorRightPID_Kp 1.0
#define motorRightPID_Ki 0.4
#define motorRightPID_Kd 0.0


// Akku
const float batFull = 29.0;                  // How many volts does the battery have when it is full?
const float batGoHomeIfBelow = 24.0;         // At how many volts should it drive back to the station?
const float batSwitchOffIfBelow = 20.0;      // At how many volts should the robot be switched off?

//Station
#define usestation true        // true/false Did the Roboter use a Charging Station?
#define leavestationdirection right // true/false In which direction should the robot turn after it has left the station?

//Sonar
#define usessonar true        // true/false Did the Robot use Ultrasonic Sensors?
//#define sonarleftright true   // Use Sonar Left and Right?
//#define sonarcenter true      // Use Sonar Center?
const float MAX_DISTANCE_SONAR = 200;    // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
const int OBSTACLE_DISTANCE = 30;   // Standard distance to obstacle

//Bumper
#define usesbumper true       // true/false Did the Robot use Ultrasonic Sensors?
#define sonarfront true       // Use Bumper Left and Right on Front?
#define sonarrear true        // Use Bumper Left and Right on Rear?

//GPS
#define usesgps false        // true/false Did the Robot use GPS?

//Timer
#define usestimer false       // true/false Timer to set the mowing times

//Serial Connections
#define Teensy_BAUDRATE 19200
#define ESP32Port Serial1  // Teensymower default OK for ESP32
#define ESP32_BAUDRATE 19200
#define GpsPort Serial3  // GPS 

//INA226 Config
const int inaMotorLeftAddr = 0x40;
const int inaMotorRightAddr = 0x41;
const int inaCutterAddr = 0x42;
const int inaBattAddr = 0x43;


// No changes needed ->
// Variables
float wheel_circumference = (2.0 * PI * WHEEL_RADIUS);    // Wheel circumference
float ticks_per_meter;        // Ticks per metre
float max_ticks_per_second;   // max Ticks pro Second
float max_linear_speed;       // max linear

/*
float calculateWheelCircumference(float wheel_radius){
    return 2.0 * PI * wheel_radius;
}
*/
#endif
