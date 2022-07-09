#include "vex.h"

float shootingtime = 400;
float unshootingtime = 200;

void bangbangflywheel(float voltage, float velocity) {
  if (Flywheel.velocity(pct) < velocity-5) {Flywheel.spin(fwd,12, volt);}
  else {Flywheel.spin(fwd, voltage, volt);}
}