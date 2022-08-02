#include "vex.h"



void autonomous(void) {
  switch(currentselection){
 case 1:
  fifteenSkillsAuto();
  break;
 case 2:
  leftAuto();
  break;
 case 3:
  rightAuto();
  break;
 case 4:
  WPAuto();
  break;
}

}