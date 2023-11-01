
#include "telemetry.h"

#include <Arduino.h>

#include <DabbleESP32.h>

#include <vector>

telemetry::telemetry()
{
  Dabble.begin("Ramon");  
}

void telemetry::getData(float Values[5])
{
  
  Dabble.processInput();

  x = GamePad.getXaxisData();

  y = GamePad.getYaxisData();

  right = 0;

  left = 0; 

  start = 0;

  if (GamePad.isSelectPressed())
  {

    start = 1;
    
  }

  if (GamePad.isTrianglePressed())
  {
    right = 1;
  }

  if (GamePad.isCrossPressed())
  {
    left =1;    
  }

  Values[0] = x;
  Values[1] = y;
  Values[2] = left;
  Values[3] = right;
  Values[4] = start;
  
  }
