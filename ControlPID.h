#pragma once


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

  int normalizeResolution;

  int resolution;

  void setResolution(int Resolution);
  
  ControlPID(int ENCA_ONE, int ENCA_TWO);

  void encoderRutine();

  void readEncoder();

  void calculatePID(float velocityInput);

  private:

   static ControlPID* objectInstance;
   
   static void staticEncoderRutine();

  protected:

    const float kp = 1;

    const float ki = 0;

    const float kd = 0;
  
};
