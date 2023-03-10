#ifndef CONFIG_H
#define CONFIG_H

#include "pin_definations.h"

#define MowerName "MatrixMOW"
#define PCB_V103 true


#define odometryTicksPerRevolution 1200   // WHEEL Pulses per wheel revolution

#define wheeldiameter 32     // Wheel diameter in cm
#define wheeldistance 33     // Wheel distance in cm

#define motorSpeedMaxRpm 30  // motor wheel max RPM (WARNING: do not set too high, so there's still speed control when battery is low!)
#define motorSpeedMaxPwm 108 // motor wheel max Pwm  (8-bit PWM=255, 10-bit PWM=1023)
#define motorPowerMax 20     // motor wheel max power (Watt)
#define motorMaxRPM 150      // max RPM Roboters

// motor wheel PID controller
#define motorLeftPID_Kp 1.0
#define motorLeftPID_Ki 0.4
#define motorLeftPID_Kd 0.0

//Akku
#define batFull 29              // How many volts does the battery have when it is full?
#define batGoHomeIfBelow 24     // At how many volts should it drive back to the station
#define batSwitchOffIfBelow 20  // At how many volts should the robot be switched off?

//Station
#define usestation true        // true/false Did the Roboter use a Charging Station?
#define leavestationdirection right // true/false In which direction should the robot turn after it has left the station?

//Sonar
#define usessonar true        // true/false Did the Robot use Ultrasonic Sensors?
//#define sonarleftright true   // Use Sonar Left and Right?
//#define sonarcenter true      // Use Sonar Center?
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

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

const int inaMotorLeftAddr = 0x40;
const int inaMotorRightAddr = 0x41;
const int inaCutterAddr = 0x42;
const int inaBattAddr = 0x43;

// Variables
float wheel_circumference;    // Wheel circumference
float ticks_per_meter;        // Ticks per metre
float max_ticks_per_second;   // max Ticks pro Second
float max_linear_speed;       // max linear


// Variablen
int left_ticks = 0;
int right_ticks = 0;
float distance = 0.0;

#endif
