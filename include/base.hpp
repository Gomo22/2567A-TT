#ifndef _BASE_H_
#define _BASE_H_


void driveTask(void* parameter);
void turnTask(void* parameter);
void setSpeed(int speed);
bool isDriving();
void driveAsync(double sp);
void drive(double sp);
void turnAsync(double sp);
void turn(double sp);
void driveOP();
void driveTask(void* parameter);
void turnTask(void* parameter);
void setSpeed(int speed);
bool isDriving();
void driveAsync(double sp);
void drive(double sp);
void driveAsync(double sp);
void turn(double sp);
void driveOP();
int getBatteryLevel();
int getDriveError();
int getTurnError();

#endif
