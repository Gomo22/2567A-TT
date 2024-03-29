#include "main.h"
//user edits

//motor ports
const int lift = 18;

//variables
int lspeed = 127;
///////////////////////////////////////////////////////
//motor definitions
Motor lift1(lift, MOTOR_GEARSET_18, 0,  MOTOR_ENCODER_DEGREES);

//usercontroL
void liftOP()
{
  if(controller.get_digital(DIGITAL_L1))
  {
    angle.move_absolute(300, 40);
    lift1.move(lspeed);
  }
  else if(controller.get_digital(DIGITAL_L2))
  {
    lift1.move(-lspeed);
    angle.move_absolute(0, -100);
  }
  else
  {
    lift1.move(0);
  }
}
///////////////////////////////////////////////////////
//autonomous functions
void expand(int lheight, bool up)
{
    if(up)
    {
      lift1.move_relative(lheight, 100);
    }
    else
    {
      lift1.move_relative(lheight, -100);
    }
}
