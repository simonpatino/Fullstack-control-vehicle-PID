#include "PWM_Setup.h" 
#include "EngineHB.h"
#include "ControlPID.h"
#include "Motor_L29.h"
//nclude <Arduino.h>
#include <DabbleESP32.h>


#define motorOneFrequency 800
#define motorTwoFrequency 800
#define motorThreeFrequency 800
#define motorFourthFrequency 800

#define motorOneChannel 0
#define motorTwoChannel 1
#define motorThreeChannel 2
#define motorFourthChannel 3

#define motorOneResolution 14
#define motorTwoResolution 14
#define motorThreeResolution 14
#define motorFourthResolution 14

#define motorOnePWMPin 27
#define motorTwoPWMPin 33
#define motorThreePWMPin 3
#define motorFourthPWMPin 4

#define motorOnePinOne 14
#define motorOnePinTwo 12

#define motorTwoPinOne 26
#define motorTwoPinTwo 25

#define motorThreePinOne   0
#define motorThreePinTwo   2

#define motorFourthPinOne 19
#define motorFourthPinTwo 21

#define motorOnePinOneEncoder 16
#define motorOnePinTwoEncoder 17

#define motorTwoPinOneEncoder 18
#define motorTwoPinTwoEncoder 5

#define motorThreePinOneEncoder  23
#define motorThreePinTwoEncoder  22

#define motorFourthPinOneEncoder  13
#define motorFourthPinTwoEncoder  15

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE


PWM_Setup motorOnePWM(motorOnePWMPin, motorOneChannel, motorOneFrequency, motorOneResolution);

PWM_Setup motorTwoPWM(motorTwoPWMPin, motorTwoChannel, motorTwoFrequency, motorTwoResolution);

PWM_Setup motorThreePWM(motorThreePWMPin, motorThreeChannel, motorThreeFrequency, motorThreeResolution);

PWM_Setup motorFourthPWM(motorFourthPWMPin, motorFourthChannel, motorFourthFrequency, motorFourthResolution);


Motor_L29 motorOne(motorOnePinOne,motorOnePinTwo, motorOneChannel, motorOnePinOneEncoder, motorOnePinTwoEncoder);

Motor_L29 motorTwo(motorTwoPinOne, motorTwoPinTwo, motorTwoChannel,motorTwoPinOneEncoder, motorTwoPinTwoEncoder);

Motor_L29 motorThree(motorThreePinOne, motorThreePinTwo,motorThreeChannel,motorThreePinOneEncoder, motorThreePinTwoEncoder);

Motor_L29 motorFourth(motorFourthPinOne,motorFourthPinTwo, motorFourthChannel,motorFourthPinOneEncoder, motorFourthPinTwoEncoder);


EngineHB controlCenter;


ControlPID motorOnePID(motorOnePinOneEncoder, motorOnePinTwoEncoder);

ControlPID motorTwoPID(motorTwoPinOneEncoder, motorTwoPinTwoEncoder);

ControlPID motorThreePID(motorThreePinOneEncoder, motorThreePinTwoEncoder);

ControlPID motorFourthPID(motorFourthPinOneEncoder, motorFourthPinTwoEncoder);



volatile int positions[] = {0,0,0,0};

const int enca[] = {motorOnePinOneEncoder,motorTwoPinOneEncoder,motorThreePinOneEncoder,motorFourthPinOneEncoder};

//const int encb[] = {4,5};

//const int pwm[] = {9,13};

//const int in1[] = {8,11};

//nst int in2[] = {10,12};

volatile float velocity[] = {0,0,0,0};

volatile float prevelocity[] = {0,0,0,0};

volatile float currT_velocity[]= {0,0,0,0};

volatile float prevT_velocity[]= {0,0,0,0};

volatile float deltaT_velocity[]= {0,0,0,0};

volatile float preprevelocity[] = {0,0,0,0};

volatile float vfilter[] = {0,0,0,0};




#include "templates.h"


void setup() {

      
  //attachInterrupt(digitalPinToInterrupt(motorOnePinTwoEncoder),readEncoder<0>,RISING);

  //attachInterrupt(digitalPinToInterrupt(motorTwoPinTwoEncoder),readEncoder<1>,RISING);

  //attachInterrupt(digitalPinToInterrupt(motorThreePinTwoEncoder),readEncoder<2>,RISING);

  //attachInterrupt(digitalPinToInterrupt(motorFourthPinTwoEncoder),readEncoder<3>,RISING);


  //motorOnePID.setResolution(motorOnePWM.Resolution);

  //motorTwoPID.setResolution(motorTwoPWM.Resolution);

  //motorThreePID.setResolution(motorThreePWM.Resolution);

  //motorFourthPID.setResolution(motorFourthPWM.Resolution);


  Serial.begin(115200);

  Dabble.begin("Ramon");  

  


}

void loop() {

// ########################  Init Telemetry Code   ########################

  Dabble.processInput();

   float x = GamePad.getXaxisData();

   float y = GamePad.getYaxisData();

   int start = 0;

   int wz = 0;

   
   if (GamePad.isStartPressed())
  {
    
    start = 1;
    
  }
  
  if (GamePad.isTrianglePressed())
  {
    
    wz = 10;  //right
    
  } 
    
  else if (GamePad.isCrossPressed())
  {
     
    wz = -10;  //left
    
  } else {
    
    wz = 0;
    
    }

  //################### Telemetry Debug #######################################

  //int lx, ly = 125;

  //Serial.print( map( (x + y + wz) , 0, 14, 0, 16383));

  //Serial.print(",");

  //Serial.println( map( (x - y + wz) , 0, 14, 0, 16383)) ;

  //Serial.print(",");

  //Serial.print(start);

  //Serial.print(",");

  //Serial.print(right);

  //Serial.print(",");

  //Serial.println(left);

//########################### End Telemetry Code ##############################


//##################### Init Inverse Kinematics Moves #########################

  controlCenter.coordinate(x,y, wz, motorOne,motorTwo,motorThree, motorFourth,                             
                           motorOnePID, motorTwoPID, motorThreePID, motorFourthPID );


  //motorTwo.SetSpeed(10000);

  //motorThree.SetSpeed(15000);

  //motorFourth.SetSpeed(5000);

 
                           
//##################### End Inverse Kinematics Moves ##########################

//########################### Init Line Sensor ################################

//########################### End Line Sensor #################################

//############################# Init Debbug ###################################

  //motorOnePID.calculatePID(5000*sin(micros()/10e6*10),vfilter[0]);
  //motorOne.SetSpeed(motorOnePID.PID);

  //motorTwoPID.calculatePID(5000*cos(micros()/10e6*10),vfilter[1]);
  //motorTwo.SetSpeed(motorTwoPID.PID);

  //motorThreePID.calculatePID(5000*cos(micros()/10e6*10),vfilter[2]);
  //motorThree.SetSpeed(motorThreePID.PID);

  //motorFourthPID.calculatePID(5000*sin(micros()/10e6*10),vfilter[3]);
  //motorFourth.SetSpeed(motorFourthPID.PID);

  //Serial.print(vfilter[0]);
  //Serial.print(",");
  //Serial.print(vfilter[1]);
  //Serial.print(",");
  //Serial.print(vfilter[2]);
  //Serial.print(",");
  //Serial.println(vfilter[3]);
  
  //Serial.println(motorOnePID.PID);
  //Serial.println(",");

  //Serial.println(velocity[1]);
  //Serial.print(",");
  //Serial.println(motorTwoPID.PID);

//############################# End Debbug ####################################
  

}
