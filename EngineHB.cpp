#include "EngineHB.h"
#include <Arduino.h>

extern volatile float vfilter[];

//EngineHB::EngineHB(Motor_L29 motorOne, Motor_L29 motorTwo,Motor_L29 motorThree,Motor_L29 motorFourth)

//{


//}


void EngineHB::coordinate(float x, float y, int wz, Motor_L29& motorOne, Motor_L29& motorTwo,Motor_L29& motorThree,Motor_L29& motorFourth,

                                                     ControlPID&  motorOnePID, ControlPID& motorTwoPID, ControlPID& motorThreePID,ControlPID&  motorFourthPID)
                                                     
{

  //lx , ly = 0;


  motorOnePID.calculatePID((1/r*(x-y))*(60/(2*3.14)) - (lx + ly)*wz, vfilter[0]);
  motorOne.SetSpeed(motorOnePID.PID);

  motorTwoPID.calculatePID((1/r*(x+y))*(60/(2*3.14)) - (lx + ly)*wz, vfilter[1]);
  motorTwo.SetSpeed(motorTwoPID.PID);

  motorThreePID.calculatePID((1/r*(x+y))*(60/(2*3.14))  - (lx + ly)*wz, vfilter[2]);
  motorThree.SetSpeed(motorThreePID.PID);

  motorFourthPID.calculatePID( (1/r*(x-y))*(60/(2*3.14))- (lx + ly)*wz, vfilter[3]);
  motorFourth.SetSpeed(motorFourthPID.PID);
  
  //motorOne.SetSpeed((1/r*(x-y))*(60/(2*3.14)) - (lx + ly)*wz );

  //motorTwo.SetSpeed((1/r*(x+y))*(60/(2*3.14)) - (lx + ly)*wz);

  //motorThree.SetSpeed((1/r*(x+y))*(60/(2*3.14))  - (lx + ly)*wz);

  //motorFourth.SetSpeed((1/r*(x-y))*(60/(2*3.14))- (lx + ly)*wz);
  
}
