#include "ControlPID.h"
#include <Arduino.h>

//ControlPID* ControlPID::objectInstance = nullptr;

ControlPID::ControlPID(int ENCA_ONE, int ENCA_TWO)

{

  errorIntegral = 0;

  ENCA_One = ENCA_ONE;

  ENCA_Two = ENCA_TWO;

  prevT_velocity = 0;

  prevT_pid = 0;

  prevE = 0;

  pinMode(INPUT, ENCA_ONE);

  pinMode(INPUT, ENCA_TWO);

}

//void ControlPID::encoderRutine()
//{
  
//  objectInstance = this;
  
//  attachInterrupt(digitalPinToInterrupt(ENCA_Two),staticEncoderRutine,RISING);

//}

//void  IRAM_ATTR ControlPID::readEncoder(int increment)
//{


//  currT_velocity = micros();

  //deltaT_velocity = ((float)(currT_velocity - prevT_velocity)) / 1.0e6 ;

  //velocity = increment / deltaT_velocity;

  //prevT_velocity = currT_velocity;

//}


//void ControlPID::staticEncoderRutine() 
//{
  
//  if (objectInstance) 
//  {
    
//    objectInstance->readEncoder();
    
//  }
  
//}




void ControlPID::calculatePID(float velocityGoal, float velocity )
{

  currT_pid = micros();

  deltaT_pid = ((float)(currT_pid - prevT_pid)) / 1.0e6;

  prevT_pid = currT_pid;

  errorValue = velocityGoal - velocity;

  errorDerivative = (errorValue - prevE)/ deltaT_pid;

  prevE = errorValue;

  errorIntegral = errorIntegral + (errorValue * deltaT_pid);

  PID =  kp*errorValue + kd*errorDerivative + ki*errorIntegral;

  if (PID > normalizeResolution){

    PID = normalizeResolution;

  }

  else if ( PID < -normalizeResolution){

    PID = -normalizeResolution;

  }

  

  
}

void ControlPID::setResolution(int Resolution)
{

  resolution =  Resolution;

  normalizeResolution = pow(2, resolution) -1;

}
