#include "vex.h"

#define RED 0
#define BLUE 1

float shootingtime = 400;
float unshootingtime = 400;

float flywheelVelocity = 0;

float kP = .2;
float kI = 0;
float kD = 0;
float kF = .12;
float target = 0;
float error = 0;
float integral = 0;
float prevError = error;
float derivative = error - prevError;
float power = 0;

int bangbangcontroller() {
while(true){
 double vel = Flywheel.velocity(pct);
 error = target - vel;
 integral += error;
 derivative = error - prevError;

 power = (error *kP + integral * kI + derivative * kD + target * kF);

 prevError = error;

 Flywheel.spin(fwd, power, volt);

 vex::task::sleep(20);
 }
 
 return 0;
} 

void velcontroller(double vel){
 target = vel;
 if(target == 0){
 Flywheel.stop(coast);
 }
}

int getColor(){
  opt.setLightPower(100,pct);
  if (opt.isNearObject()) {
    int objHue = opt.hue();
    if (objHue < 300 && objHue > 180) {return BLUE;}
    else if (objHue < 20) {return RED;} 
    else {return 2;}
  }  
  else {return 2;}
}

int rollerSpin(bool color, float speed, float timeout, float extraspin){
  if (color == RED) {
  float starttime = Brain.timer(msec);
  while( !getColor() == color && Brain.timer(msec)-starttime < timeout){
    Intake.spin(fwd, speed, pct);
  }
  while( getColor() == color && Brain.timer(msec)-starttime < timeout){
    Intake.spin(fwd, speed/2, pct);
  }
  Intake.stop(hold);
  Intake.rotateFor(fwd, extraspin, deg, false);
  }
  if (color == BLUE) {
  float starttime = Brain.timer(msec);
  while( getColor() == RED && Brain.timer(msec)-starttime < timeout){
    Intake.spin(fwd, speed, pct);
  }
  while( (!getColor() == RED) && Brain.timer(msec)-starttime < timeout){
    Intake.spin(fwd, speed/2, pct);
  }
  Intake.stop(hold);
  Intake.rotateFor(fwd, extraspin, deg, false);
  }
  return 0;
}


