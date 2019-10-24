#ifndef _BASE_H_
#define _BASE_H_


void driveTask(void* parameter);
void turnTask(void* parameter);
void resetDrive();
void reset();
void setSpeed(int speed);
bool isDriving();
void driveAsync(int sp);
void drive(int sp);
void turnAsync(int sp);
void turn(int sp);
void driveOP();

#endif
