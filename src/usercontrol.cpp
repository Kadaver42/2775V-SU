#include "vex.h"

void driveto0(){
straightdrive(0,0);
}

void usercontrol( void ) {
  vex::task positiontrackingtask = task(positionTrack);
  vex::task bangbangcontrol = task(bangbangcontroller);
  float throttle;
  float turn;
  float drivescalefactor = 0.09448818897;
  int shooterstate = 0; //0 is uninvolved, 1 is shooting out, 2 is unshooting
  float shoottimer = 0;
  while (1) {
    throttle = drivescalefactor*Controller1.Axis3.value();
    turn = drivescalefactor*Controller1.Axis1.value();

    setDriveVoltage(throttle+turn,throttle-turn);

    Controller1.ButtonX.pressed(driveto0);

    if(Controller1.ButtonB.pressing()){
    rollerSpin();
    
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
    } else {
      Intake.stop(coast);
    }
    if (Controller1.ButtonL1.pressing()) {
      velcontroller(70);
    } else if (Controller1.ButtonL2.pressing()) {
     
    } else {
     velcontroller(0);
     }
    if(Controller1.ButtonA.pressing() && shooterstate == 0) {
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
      shooterstate = 0;
    }
    if(shooterstate == 0) {
      Indexer.set(true);
    }
  }
}