/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// leftClaw             motor         20              
// rightClaw            motor         11              
// topWheel             motor         12              
// twoWheels            motor         19              
// bottomRightMotor     motor         1               
// topRightMotor        motor         2               
// topLeftMotor         motor         9               
// bottomLeftMotor      motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  topLeftMotor.setVelocity(100,percent);
  bottomLeftMotor.setVelocity(100,percent);
  topRightMotor.setVelocity(100,percent);
  bottomRightMotor.setVelocity(100,percent);
  topWheel.setVelocity(100,percent);
  twoWheels.setVelocity(100,percent);
  leftClaw.setVelocity(100,percent);
  rightClaw.setVelocity(100,percent);
  Brain.Battery.voltage();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
    topLeftMotor.spin(forward);
    bottomLeftMotor.spin(forward);
    topRightMotor.spin(forward);
    bottomRightMotor.spin(forward);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  int deadband = 5;
  while (1) {
      while (true) {
    // Get the velocity percentage of the left motor. (Axis3)
    int leftMotorSpeed = Controller1.Axis3.position();
    // Get the velocity percentage of the right motor. (Axis2)
    int rightMotorSpeed = Controller1.Axis2.position();


    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      topLeftMotor.setVelocity(0, percent);
      bottomLeftMotor.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      topLeftMotor.setVelocity(leftMotorSpeed, percent);
      bottomLeftMotor.setVelocity(leftMotorSpeed, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      topRightMotor.setVelocity(0, percent);
      bottomRightMotor.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      topRightMotor.setVelocity(rightMotorSpeed, percent);
      bottomRightMotor.setVelocity(rightMotorSpeed, percent);
    }
  //might change actual motor settings later
    topLeftMotor.spin(reverse);
    bottomLeftMotor.spin(reverse);
    topRightMotor.spin(forward);
    bottomRightMotor.spin(forward);

    leftClaw.setStopping(hold);
    rightClaw.setStopping(hold);

    if(Controller1.ButtonR1.pressing()){
      leftClaw.spin(forward);
      rightClaw.spin(forward);
    }else if(Controller1.ButtonR2.pressing()){
      leftClaw.spin(reverse);
      rightClaw.spin(reverse);
    }else {
      leftClaw.stop();
      rightClaw.stop();
    }

    twoWheels.setStopping(hold);

    if(Controller1.ButtonL1.pressing()){
      twoWheels.spin(forward);
    }else if(Controller1.ButtonL2.pressing()){
      twoWheels.spin(reverse);
    }else {
      twoWheels.stop();
    }

    topWheel.setStopping(hold);

    if(Controller1.ButtonA.pressing()){
      topWheel.spin(reverse);
    }else if(Controller1.ButtonB.pressing()){
      topWheel.spin(forward);
    }else{
      topWheel.stop();
    }
     wait(25, msec);
  }
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
