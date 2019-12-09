
#include "main.h"
//user edits

//motor ports
const int right_intake = 1;
const int left_intake = 10;

///////////////////////////////////////////////////////
//motor definitions
Motor intake1(right_intake, MOTOR_GEARSET_36, 0,  MOTOR_ENCODER_DEGREES);
Motor intake2(left_intake, MOTOR_GEARSET_36, 1,  MOTOR_ENCODER_DEGREES);

//usercontroL
void intakeOP()
{
if(controller.get_digital(DIGITAL_R1))
{
  intake1.move(127);
  intake2.move(127);
}
else if(controller.get_digital(DIGITAL_R2))
{
  intake1.move(-127);
  intake2.move(-127);
}
else
{
  intake1.move(0);
  intake2.move(0);
}
}
///////////////////////////////////////////////////////
//autonomous functions
void intake(int ispeed)
{
intake1.move_velocity(ispeed);
intake2.move_velocity(ispeed);
}
