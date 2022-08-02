#include "vex.h"



void usercontrol( void ) {
  vex::task positiontrackingtask = task(positionTrack);
  vex::task bangbangcontrol = task(bangbangcontroller);

  float throttle;
  float turn;
  float drivescalefactor = 0.09448818897;
  float shoottimer = 0;
  int shooterstate = 0; //0 is uninvolved, 1 is shooting out, 2 is unshooting
  while (1) {
    throttle = drivescalefactor*Controller1.Axis3.value();
    turn = drivescalefactor*Controller1.Axis1.value();

    setDriveVoltage(throttle+turn,throttle-turn);

    if(Controller1.ButtonL2.pressing()){
      while(Controller1.ButtonL2.pressing()){}
    Intake.rotateFor(fwd, 95, deg, 100, velocityUnits::pct, false);
    }

    if(Controller1.ButtonUp.pressing() && (Controller1.ButtonLeft.pressing()) && (Controller1.ButtonDown.pressing()) && (Controller1.ButtonRight.pressing())){
    Endgame.set(true);
    }

    else{
    Endgame.set(false);
    }

    if (Controller1.ButtonR1.pressing()) {
      Intake.spin(fwd, 100, pct);
    } else if (Controller1.ButtonR2.pressing()) {
      Intake.spin(reverse, 100, pct);
    } else if (Intake.isDone()){
      Intake.stop(coast);
    }

    if (Controller1.ButtonA.pressing()) {
      velcontroller(70);
    } else if (Controller1.ButtonB.pressing()) {
     velcontroller(0);
    } else if (Controller1.ButtonX.pressing()){
     velcontroller(90);
     }

    if(Controller1.ButtonL1.pressing() && shooterstate == 0) {
      Indexer.set(false);
      shooterstate = 1;
      shoottimer = Brain.timer(msec);
    }
    if(shooterstate == 1 && Brain.timer(msec)-shoottimer > shootingtime) {
      Indexer.set(true);
      shooterstate = 2;
      shoottimer = Brain.timer(msec);
    }
    if(shooterstate == 2 && Brain.timer(msec)-shoottimer > unshootingtime) {
      Indexer.set(false);
      shooterstate = 0;
    }
    if(shooterstate == 0) {
      Indexer.set(true);
    }
  }
}