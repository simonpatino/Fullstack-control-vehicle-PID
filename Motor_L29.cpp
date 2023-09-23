#include "Motor_L29.h"
#include <Arduino.h>
#include "ControlPID.h"

Motor_L29::Motor_L29(int MotorPinOne, int MotorPinTwo, int PWMChannel,  int ENCA_ONE, int ENCA_TWO)
{

    MotorPinOneSetUp = MotorPinOne;

    MotorPinTwoSetUp= MotorPinTwo;

    Channel= PWMChannel;

   
    pinMode(MotorPinOne, OUTPUT);

    pinMode(MotorPinTwo, OUTPUT);

    ControlPID ax(ENCA_ONE, ENCA_TWO);

    dynamic = &ax;

    
}

void Motor_L29::SetSpeed(int Velocity)
{

  dynamic->calculatePID(Velocity);

  velocityProcessed = dynamic->PID;
  
  if(velocityProcessed > 0)
    {

        digitalWrite(MotorPinOneSetUp, HIGH);

        digitalWrite(MotorPinOneSetUp, LOW);

    } 

    else if (velocityProcessed < 0)
    {

        digitalWrite(MotorPinOneSetUp, LOW);

        digitalWrite(MotorPinTwoSetUp, HIGH);

    }
   


 ledcWrite(Channel, abs(velocityProcessed)); 

}

void Motor_L29::run(String Direction)
{


  // Old command, setSpeed now can determine the direction 

    if(Direction == "FORWARD")
    {

        digitalWrite(MotorPinOneSetUp, HIGH);

        digitalWrite(MotorPinOneSetUp, LOW);

    } 

    else if (Direction == "BACKWARD")
    {

        digitalWrite(MotorPinOneSetUp, LOW);

        digitalWrite(MotorPinTwoSetUp, HIGH);

    }

}

void Motor_L29::coordinate(int x, int y)
{

  


}



