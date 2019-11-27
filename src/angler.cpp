#include "main.h"
//user edits

//motor ports
const int angler = 7;

//variables
int aspeed = 30;
///////////////////////////////////////////////////////
//motor definitions
Motor angle(angler, MOTOR_GEARSET_36, 0,  MOTOR_ENCODER_DEGREES);
ADIPotentiometer anglePot ('A');
//usercontroL
void anglerOP()
{
  if(controller.get_digital(DIGITAL_X))
  {
  angle.move_absolute(400, aspeed);
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
