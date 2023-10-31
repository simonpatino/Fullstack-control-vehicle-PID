
#include "telemetry.h"

#include <Arduino.h>

#include <DabbleESP32.h>

telemetry::telemetry()
{
  
  
  Dabble.begin("Ramon");
  
  
}


int telemetry::getData(){
  
  Dabble.processInput();

  float x = GamePad.getXaxisData();

  float y = GamePad.getYaxisData();

  float right = 0;

  float left = 0; 

  float start = 0;

 

  if (GamePad.isSelectPressed())
  {
    

  }

  if (GamePad.isTrianglePressed())
  {
    right = 1;
  }

  if (GamePad.isCrossPressed())
  {
    left =1;    
  }

  


  float values[5] = {x,y,left,right,start};


    return  values[0];
  
  }
