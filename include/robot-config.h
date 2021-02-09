using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor leftClaw;
extern motor rightClaw;
extern motor topWheel;
extern motor twoWheels;
extern motor bottomRightMotor;
extern motor topRightMotor;
extern motor topLeftMotor;
extern motor bottomLeftMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );