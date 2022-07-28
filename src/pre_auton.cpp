#include "vex.h"

void pre_auton(){
Indexer.set(true);

Brain.Screen.printAt(1,100,"Current Selection: %f",currentselection);

if(Up.pressing()){
 currentselection --;
}

else if(Down.pressing()){
 currentselection ++;
}

}