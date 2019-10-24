#include "main.h"
//user edits

//motor ports
const int angler = 1;

//variables
int aspeed = 30;
///////////////////////////////////////////////////////
//motor definitions
Motor angle(angler, MOTOR_GEARSET_36, 0,  MOTOR_ENCODER_DEGREES);

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
///////////////////////////////////////////////////////
//autonomous functions
