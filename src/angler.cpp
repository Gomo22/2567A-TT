
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
  if(angle.get_position() <= 350)
    angle.move_absolute(350, 55);
  else if(angle.get_position() <= 450 && angle.get_position() > 350)
      angle.move_absolute(450, 45);
  else
    angle.move_absolute(650, 30);
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
void tilting()
{
  while(angle.get_position() != 650)
  delay(20);
}

void tiltAsync(bool vert){
  if(vert)
  {
  if(angle.get_position() <= 500)
    angle.move_absolute(500, 100);
  else
    angle.move_absolute(650, 30);
  }
  else
  angle.move_absolute(0, 70);
}

void tilt(bool vert)
{
  tiltAsync(vert);
  tilting();
}
