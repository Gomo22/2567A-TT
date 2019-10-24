#include "main.h"
//user edits

//motor ports
const int lift = 14;

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
    lift1.move(lspeed);
  }
  else if(controller.get_digital(DIGITAL_L2))
  {
    lift1.move(-lspeed);
  }
  else
  {
    lift1.move(0);
  }
}
///////////////////////////////////////////////////////
//autonomous functions
