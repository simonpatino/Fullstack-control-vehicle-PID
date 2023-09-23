#pragma once
#include <Arduino.h>
#include "ControlPID.h"

class Motor_L29 
{   

    public:

    int Channel;

    int MotorPinOneSetUp, MotorPinTwoSetUp;
    
    ControlPID* dynamic;

    volatile float velocityProcessed; 
    
    Motor_L29(int MotorPinOne, int MotorPinTwo, int PWMChannel, int ENCA_ONE, int ENCA_TWO);

    void coordinate(int x, int y);

    void SetSpeed(int Velocity);

    void run(String Direction);

    private:

    protected: 

};
