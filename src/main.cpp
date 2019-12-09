#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	Task drive_task (driveTask,NULL,TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"");
	Task turn_task (turnTask,NULL,TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"");
//insert autons here
//	drive(1.2);
	//drive(-1.8);
	turn(90);
	drive(1.0);
	turn(-90);

	drive_task.remove();
  turn_task.remove();


}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
 Controller controller(CONTROLLER_MASTER);
 void opcontrol() {
 	char lblstring[30] = "";


 	lv_obj_t * scr = lv_page_create(NULL,NULL);
 	lv_scr_load(scr);

 	lv_obj_t * labelbattery = lv_label_create(lv_scr_act(), NULL);
 	lv_label_set_text(labelbattery, "Battery Level");
 	// lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);

 	lv_obj_t * labelDriveError = lv_label_create(lv_scr_act(), NULL);
 	lv_obj_align(labelDriveError, labelbattery, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
 	lv_label_set_text(labelDriveError, "Drive Error");

 	lv_obj_t * labelTurnError = lv_label_create(lv_scr_act(), NULL);
 	lv_obj_align(labelTurnError, labelDriveError, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
 	lv_label_set_text(labelTurnError, "Turn Error");
 /*=
 	lv_obj_t * labelLiftError = lv_label_create(lv_scr_act(), NULL);
 	lv_obj_align(labelLiftError, labelTurnError, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
 	lv_label_set_text(labelLiftError, "Lift Error");
 	lv_obj_t * labelAngleError = lv_label_create(lv_scr_act(), NULL);
 	lv_obj_align(labelAngleError, labelLiftError, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
 	lv_label_set_text(labelAngleError, "Angle Error");
 *//*
 	lv_obj_t * btnpuncher = lv_btn_create(lv_scr_act(), NULL);
 	lv_obj_align(btnpuncher, labelAngleError, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
 	lv_btn_set_action(btnpuncher,LV_BTN_ACTION_CLICK, btn_rel_puncher);
 	lv_obj_t * label = lv_label_create(btnpuncher, NULL);
 	lv_label_set_text(label, "Reset\nPuncher");
 	lv_obj_t * btnencoder = lv_btn_create(lv_scr_act(), NULL);
 	lv_obj_align(btnencoder, btnpuncher, LV_ALIGN_OUT_RIGHT_BOTTOM, 0, 0);
 	lv_btn_set_action(btnencoder,LV_BTN_ACTION_CLICK, btn_rel_encoder);
 	label = lv_label_create(btnencoder, NULL);
 	lv_label_set_text(label, "Reset\nDrive"); */
 	while (true) {
 		std::string charstring = "Battery Level: " + std::to_string(getBatteryLevel());
 		strcpy(lblstring, charstring.c_str());
 		lv_label_set_text(labelbattery, lblstring);
 		charstring = "Drive Error: " + std::to_string(getDriveError());
 		strcpy(lblstring, charstring.c_str());
 		lv_label_set_text(labelDriveError, lblstring);
 		charstring = "Turn Error: " + std::to_string(getTurnError());
 		strcpy(lblstring, charstring.c_str());
 		lv_label_set_text(labelTurnError, lblstring);

		if(controller.get_digital(DIGITAL_LEFT) && !competition::is_connected())
				autonomous();
 										  driveOP();
 											intakeOP();
 											anglerOP();
 											 liftOP();
 											 delay(20);
 	}

 }
