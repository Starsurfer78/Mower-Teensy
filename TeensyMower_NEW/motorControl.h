#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H


extern const int MAX_SPEED;
extern const int MIN_SPEED;
extern const int MAX_PWM;
extern const int MIN_PWM;

void initMotorControl();
void setMotorSpeed(int leftSpeed, int rightSpeed);
void moveForward(int speed);
void moveBackward(int speed);
void moveLeft(int speed);
void moveRight(int speed);
void stopMotors();

#endif
