#include "EngineHB.h"



//EngineHB::EngineHB(Motor_L29& motorOne, Motor_L29& motorTwo,Motor_L29& motorThree,Motor_L29& motorFourth){

 //motorOne = motorOne;
 //motorTwo = motorTwo;
 //motorThree = motorThree;
 //motorFourth = motorFourth ;

//}


void EngineHB::coordinate(int x, int y, Motor_L29& motorOne, Motor_L29& motorTwo,Motor_L29& motorThree,Motor_L29& motorFourth){

  motorOne.SetSpeed((1/r*(x-y))*(60/(2*3.14)));

  motorTwo.SetSpeed((1/r*(x+y))*(60/(2*3.14)));

  motorThree.SetSpeed((1/r*(x+y))*(60/(2*3.14)));

  motorFourth.SetSpeed((1/r*(x-y))*(60/(2*3.14)));
  
}

