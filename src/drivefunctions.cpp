#include "vex.h"

void setDriveVoltage(float leftVolts, float rightVolts) {
  DriveL.spin(fwd, leftVolts, volt);
  DriveR.spin(fwd, rightVolts, volt);
}

void setDriveVelocity(float leftVelo, float rightVelo) {
  DriveL.spin(fwd, leftVelo, pct);
  DriveR.spin(fwd, rightVelo, pct);
}