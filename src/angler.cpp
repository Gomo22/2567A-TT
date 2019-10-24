#include "main.h"
//user edits

//motor ports
const int angler = 1;

//variables
int speed = 30;
///////////////////////////////////////////////////////
//motor definitions
Motor angle(angler, MOTOR_GEARSET_36, 0,  MOTOR_ENCODER_DEGREES);

//usercontroL
void anglerOP()
{
  if(controller.get_digital(DIGITAL_X))
  {
  angle.move_absolute(400, speed);
  }
  else if(controller.get_digital(DIGITAL_B))
  {
  angle.move_absolute(0, speed);
  }
  else
  {
    angle.move(0);
  }
}
///////////////////////////////////////////////////////
//autonomous functions
