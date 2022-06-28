#include "vex.h"

void usercontrol( void ) {
  float throttle;
  float turn;
  float drivescalefactor = 0.09448818897;
  while (1) {
    throttle = drivescalefactor*Controller1.Axis3.value();
    turn = drivescalefactor*Controller1.Axis1.value();

    setDriveVoltage(throttle+turn,throttle-turn);

    if (Controller1.ButtonR1.pressing()) {
      Intake.spin(fwd, 100, pct);
    } else if (Controller1.ButtonR2.pressing()) {
      Intake.spin(reverse, 100, pct);
    } else {
      Intake.stop(coast);
    }
    if (Controller1.ButtonL1.pressing()) {
      Flywheel.spin(fwd, 100, pct);
    } else if (Controller1.ButtonL2.pressing()) {
      Flywheel.spin(fwd, 70, pct);
    } else {
      Flywheel.stop(coast);
    }
  }
}