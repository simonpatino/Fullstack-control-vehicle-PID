#include "EngineHB.h"
#include <Arduino.h>

extern volatile float vfilter[];

//EngineHB::EngineHB(Motor_L29 motorOne, Motor_L29 motorTwo,Motor_L29 motorThree,Motor_L29 motorFourth)

//{


//}


void EngineHB::coordinate(float x, float y, int wz, Motor_L29& motorOne, Motor_L29& motorTwo, Motor_L29& motorThree, Motor_L29& motorFourth,

                          ControlPID&  motorOnePID, ControlPID& motorTwoPID, ControlPID& motorThreePID, ControlPID&  motorFourthPID)

{

  lx , ly = 125;

  //##################### Init Tune #####################

  if ( x > 3) {

    x = 7;

  }

  else if ( x < -3) {

    x = -7;

  }


  else {

    x = 0;

  }


  if ( y > 3) {

    y = 7;

  }


  else if ( y < -3) {

    y = -7;

  }


  else {

    y = 0;

  }


  float MotorVelOne = map( (x - y + wz) , 0, 14, 0, 16383);

  float MotorVelTwo = map( (x + y + wz) , 0, 14, 0, 16383);

  float MotorVelThree =  map( (x - y - wz) , 0, 14, 0, 16383);

  float MotorVelFourth = map(  (x + y - wz) , 0, 14, 0, 16383);


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
