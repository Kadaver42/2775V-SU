#include "vex.h"

void LeftRollerAuto(){
  vex::task positiontrackingtask = task(positionTrack);
  vex::task bangbangcontrol = task(bangbangcontroller);
  setDriveVoltage(5,5);
  task::sleep(500);
  rollerSpin();
  driveReset(31.5, 10, 180);
  straightdrive(31.5, 15);
  velcontroller(89);
  turntopoint(12, 126);
  repeat(3){
    Indexer.set(false);
    task::sleep(600);
    Indexer.set(true);
    task::sleep(400);
  }
}