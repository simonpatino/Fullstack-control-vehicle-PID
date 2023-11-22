#include "EngineHB.h"
#include <Arduino.h>

extern volatile float vfilter[];

//EngineHB::EngineHB(Motor_L29 motorOne, Motor_L29 motorTwo,Motor_L29 motorThree,Motor_L29 motorFourth)

//{


//}


void EngineHB::coordinate(float x, float y, int wz, Motor_L29& motorOne, Motor_L29& motorTwo, Motor_L29& motorThree, Motor_L29& motorFourth,

                          ControlPID&  motorOnePID, ControlPID& motorTwoPID, ControlPID& motorThreePID, ControlPID&  motorFourthPID)

{

  lx , ly = 0;

  //##################### Init Tune #####################


  
  float MotorVelOne = map((1 / r) * (x + y + (lx + ly)*wz) , 0, 250, 0, 16383);

  float MotorVelTwo = map((1 / r) * (x - y - (lx + ly)*wz) , 0, 250, 0, 16383);
  
  float MotorVelThree =  map((1 / r) * (x + y - (lx + ly)*wz) , 0, 250, 0, 16383);

  float MotorVelFourth = map((1 / r) * (x - y + (lx + ly)*wz) , 0, 250, 0, 16383);


//if ( -6000 < MotorVelOne < 6000) {
//
//  MotorVelOne = 0;
//
//}
//
//if ( -4000 < MotorVelTwo < 4000) {
//
//  MotorVelTwo = 0;
//
//}
//
//if ( -6000 < MotorVelThree < 6000) {
//
//  MotorVelThree = 0;
//
//}
//
//if ( -6000 < MotorVelFourth < 6000) {
//
//  MotorVelFourth = 0;
//
//}

//#################### End Tune #######################


//#################### Init Move ######################

//motorOnePID.calculatePID( map(1/r*(x-y- (lx + ly)*wz) ,0,250,0,625) , vfilter[0]);
motorOne.SetSpeed(MotorVelOne);

//motorTwoPID.calculatePID(map(1/r*(x+y- (lx + ly)*wz), 0,250,0,625), vfilter[1]);
motorTwo.SetSpeed(MotorVelTwo);

//motorThreePID.calculatePID(map(1/r*(x+y- (lx + ly)*wz), 0,250,0,625), vfilter[2]);
motorThree.SetSpeed(MotorVelThree);

//motorFourthPID.calculatePID( map(1/r*(x-y- (lx + ly)*wz),0,250,0,625), vfilter[3]);
motorFourth.SetSpeed(MotorVelFourth);

//################### End Move #########################

}
