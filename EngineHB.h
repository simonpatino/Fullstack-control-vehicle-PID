#pragma once
#include <Arduino.h>
#include "Motor_L29.h"

class EngineHB{

  public:

    const float r = 1;

    void coordinate(int x, int y, Motor_L29& motorOne, Motor_L29& motorTwo,Motor_L29& motorThree,Motor_L29& motorFourth);

  private:


  protected: 

};