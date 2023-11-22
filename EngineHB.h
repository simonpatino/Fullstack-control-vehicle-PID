
//#ifndef EngineHB
//#define EngineHB

#include <Arduino.h>

#include "Motor_L29.h"

#include "ControlPID.h"

class EngineHB{

  public:

  //Motor_L29 motorOne;

  //Motor_L29 motorTwo;

  //Motor_L29 motorThree;

  //Motor_L29 motorFourth;

  float lx , ly;


  const float r = 0.033;

  //EngineHB(Motor_L29 motorOne, Motor_L29 motorTwo,Motor_L29 motorThree,Motor_L29 motorFourth);

  void coordinate(float x, float y, int wz , Motor_L29& motorOne, Motor_L29& motorTwo,Motor_L29& motorThree,Motor_L29& motorFourth,
  
                                             ControlPID&  motorOnePID, ControlPID& motorTwoPID, ControlPID& motorThreePID,ControlPID&  motorFourthPID);

  private:


  protected: 

};


//#endif 
