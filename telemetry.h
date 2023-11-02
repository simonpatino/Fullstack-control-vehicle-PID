
#pragma once 

#include "Arduino.h"



class telemetry
{
   
  public:


  float x;

  float y;

  float right;

  float left; 

  float start;

  

   telemetry();
   
   void getData(float Values[5]);

  
  
  private:

  protected:
    
};
