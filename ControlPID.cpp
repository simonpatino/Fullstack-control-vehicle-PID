#include "ControlPID.h"
#include <Arduino.h>

ControlPID* ControlPID::objectInstance = nullptr;

ControlPID::ControlPID(int ENCA_ONE, int ENCA_TWO)

{

  ENCA_One = ENCA_ONE;

  ENCA_Two = ENCA_TWO;

  prevT_velocity = 0;

  prevT_pid = 0;

  prevE = 0;

  pinMode(INPUT, ENCA_ONE);

  pinMode(INPUT, ENCA_TWO);

}

void ControlPID::encoderRutine()
{
  
  objectInstance = this;
  
  attachInterrupt(digitalPinToInterrupt(ENCA_Two),staticEncoderRutine,RISING);

}

void  IRAM_ATTR ControlPID::readEncoder()
{

  StateEncoder = digitalRead(ENCA_One);

  increment = 0;

  if (StateEncoder > 0)
  {

    increment = 1;

  }

  else
  {

    increment = -1;

  }

  currT_velocity = micros();

  deltaT_velocity = ((float)(currT_velocity - prevT_velocity)) / 1.0e6 ;

  velocity = increment / deltaT_velocity;

  prevT_velocity = currT_velocity;

}

void ControlPID::staticEncoderRutine() 
{
  
  if (objectInstance) 
  {
    
    objectInstance->readEncoder();
    
  }
  
}

void ControlPID::calculatePID(float velocityInput )
{

  currT_pid = micros();

  deltaT_pid = ((float)(currT_pid - prevT_pid)) / 1.0e6;

  prevT_pid = currT_pid;

  errorValue = velocityInput - velocity;

  errorDerivative = (errorValue - prevE)/ deltaT_pid;

  prevE = errorValue;

  errorIntegral = errorIntegral + (errorValue * deltaT_pid);

  PID =  kp*errorValue + kd*errorDerivative + ki*errorIntegral;

}
