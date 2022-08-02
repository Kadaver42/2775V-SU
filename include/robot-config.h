using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor_group Flywheel;
extern motor_group Intake;
extern motor_group DriveR;
extern motor_group DriveL;
extern controller Controller1;
extern digital_out Indexer;
extern inertial Gyro;
extern encoder EncoderR;
extern digital_out Endgame;
extern optical opt;
extern bumper Cycle;
extern bumper Confirm;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );