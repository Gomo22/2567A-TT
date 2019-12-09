
#include "main.h"
//user edits

//motor ports
const int angler = 2;

//variables
int aspeed = 50;
///////////////////////////////////////////////////////
//motor definitions
Motor angle(angler, MOTOR_GEARSET_36, 0,  MOTOR_ENCODER_DEGREES);
ADIPotentiometer anglePot ('A');
//usercontroL
void anglerOP()
{
  angle.set_brake_mode(MOTOR_BRAKE_HOLD);

if(controller.get_digital(DIGITAL_X))
{
angle.move_absolute(670, aspeed);
}
else if(controller.get_digital(DIGITAL_B))
{
angle.move_absolute(0, aspeed);
}
else
{
  angle.move(0);
}
}

int tiltSpeed = 0;
void tilt(int tiltTarget)
{
  tiltSpeed = tiltTarget;
  angle.move(tiltSpeed);
}

void anglerOP1()
{
  double kp = 1.4;
  int pos = angle.get_position();//anglePot.get_value();
  int target = 640;
  int error = target - pos;
  int anglePower = (error * kp);

  if(controller.get_digital(DIGITAL_X))
  {
  target = 550;
   tilt(anglePower);
  }
  else if(controller.get_digital(DIGITAL_B))
  {
    angle.move(-127);
  }
  else
  {
    tilt(0);
  }
}

int tiltSpeed = 0;
void tilt(int tiltTarget)
{
  tiltSpeed = tiltTarget;
  angle.move(tiltSpeed);
}
void anglerOP1()
{
  double kp = 1.4;
  int pos = anglePot.get_value();
  int target = 550;
  int error = target - pos;
  int anglePower = (error * kp);

  if(controller.get_digital(DIGITAL_X))
  {
   tilt(anglePower);
  }
  else if(controller.get_digital(DIGITAL_B))
  {
  target = -550;
  tilt(-anglePower);
  }
  else
  {
    tilt(0);
  }
}
///////////////////////////////////////////////////////
//autonomous functions
