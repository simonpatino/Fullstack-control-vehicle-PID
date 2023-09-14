#include "Motor_L29.h"
#include <Arduino.h>
#include "ControlPID.h"

Motor_L29::Motor_L29(int MotorPinOne, int MotorPinTwo, int PWMChannel)
{

    MotorPinOneSetUp = MotorPinOne;

    MotorPinTwoSetUp= MotorPinTwo;

    Channel= PWMChannel;

    pinMode(MotorPinOne, OUTPUT);

    pinMode(MotorPinTwo, OUTPUT);

    ControlPID dynamic(2,2);
    
}

void Motor_L29::SetSpeed(int Velocity)
{

 ledcWrite(Channel, Velocity); 

}

void Motor_L29::run(String Direction)
{

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
