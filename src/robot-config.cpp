#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FlywheelMotorA = motor(PORT3, ratio6_1, false);
motor FlywheelMotorB = motor(PORT1, ratio6_1, false);
motor_group Flywheel = motor_group(FlywheelMotorA, FlywheelMotorB);
motor IntakeMotorA = motor(PORT9, ratio18_1, true);
motor IntakeMotorB = motor(PORT8, ratio18_1, false);
motor_group Intake = motor_group(IntakeMotorA, IntakeMotorB);
motor DriveRMotorA = motor(PORT20, ratio6_1, false);
motor DriveRMotorB = motor(PORT12, ratio6_1, false);
motor_group DriveR = motor_group(DriveRMotorA, DriveRMotorB);
motor DriveLMotorA = motor(PORT10, ratio6_1, true);
motor DriveLMotorB = motor(PORT11, ratio6_1, true);
motor_group DriveL = motor_group(DriveLMotorA, DriveLMotorB);
encoder EncoderR = encoder(Brain.ThreeWirePort.C);
inertial Gyro = inertial(PORT15);
controller Controller1 = controller(primary);
digital_out Indexer = digital_out(Brain.ThreeWirePort.A);
digital_out Endgame = digital_out(Brain.ThreeWirePort.E);


// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}