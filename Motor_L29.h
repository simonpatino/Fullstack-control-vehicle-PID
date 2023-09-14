#pragma once
#include <Arduino.h>

class Motor_L29 
{   

    public:

    int Channel;

    int MotorPinOneSetUp, MotorPinTwoSetUp;

    Motor_L29(int MotorPinOne, int MotorPinTwo, int PWMChannel, int ENCA_ONE, int ENCA_TWO);

    void SetSpeed(int Velocity);

    void run(String Direction);

    private:

    protected: 

};
