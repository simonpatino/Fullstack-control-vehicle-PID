#include "PWM_Setup.h"
#include <Arduino.h>


PWM_Setup::PWM_Setup(int PWMPin, int PWMChannel, int PWMFrequency, int PWMresolution)
{

    Pin = PWMPin;

    Channel = PWMChannel;

    Frequency = PWMFrequency;

    Resolution = PWMresolution;

    ledcSetup(Channel, Frequency, Resolution); 

    ledcAttachPin(Pin, Channel);

}
