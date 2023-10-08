
#pragma once 
//#ifndef ControlPID
//#define ControlPID

#include <Arduino.h>

class ControlPID
{

  public: 
  
  int ENCA_One, ENCA_Two;

  volatile float velocity;

  volatile float currT_velocity;

  volatile float prevT_velocity;

  volatile int increment;

  volatile float deltaT_velocity;

  volatile int StateEncoder;

  volatile float currT_pid;

  volatile float deltaT_pid;

  volatile float prevT_pid;
  
  volatile float errorValue;

  volatile float prevE;

  volatile float errorDerivative;

  volatile float errorIntegral; 

  volatile float velocityInput;

  volatile float PID;

  volatile float pos;

  int normalizeResolution;

  int resolution;

  void setParameters(volatile float velocity );

  void setResolution(int Resolution);
  
  ControlPID(int ENCA_ONE, int ENCA_TWO);

  void encoderRutine();

  void readEncoder(volatile int increment);

  void calculatePID(float velocityGoal, float velocity);

  private:

   //static ControlPID* objectInstance;
   
   //static void staticEncoderRutine();

  protected:

    const float kp = 2.5;

    const float ki = 4;

    const float kd = 1;
  
};


//#endif
