#include "main.h"
//user edits

//motor ports
const int lift = 1;

//variables
int speed = 127;
///////////////////////////////////////////////////////
//motor definitions
Motor lift1(lift, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);

//usercontroL
void anglerOP()
{
  if(controller.get_digital(DIGITAL_L1))
  {
    lift1.move(speed);
  }
  else if(controller.get_digital(DIGITAL_L2))
  {
    lift1.move(-speed);
  }
  else
  {
    lift1.move(0);
  }
}
///////////////////////////////////////////////////////
//autonomous functions
