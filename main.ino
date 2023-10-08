#include "PWM_Setup.h" 
#include "EngineHB.h"
#include "ControlPID.h"
#include "Motor_L29.h"
#include <Arduino.h>

#define motorOneFrequency 5000
#define motorTwoFrequency 5000
#define motorThreeFrequency 5000
#define motorFourthFrequency 5000

#define motorOneChannel 0
#define motorTwoChannel 1
#define motorThreeChannel 2
#define motorFourthChannel 3

#define motorOneResolution 12
#define motorTwoResolution 12
#define motorThreeResolution 12
#define motorFourthResolution 12

#define motorOnePWMPin 27
#define motorTwoPWMPin 33
#define motorThreePWMPin 3
#define motorFourthPWMPin 4

#define motorOnePinOne 14
#define motorOnePinTwo 12

#define motorTwoPinOne 25
#define motorTwoPinTwo 26

#define motorThreePinOne 0
#define motorThreePinTwo 2

#define motorFourthPinOne 21
#define motorFourthPinTwo 19

#define motorOnePinOneEncoder 16
#define motorOnePinTwoEncoder 17

#define motorTwoPinOneEncoder 18
#define motorTwoPinTwoEncoder 5

#define motorThreePinOneEncoder  23
#define motorThreePinTwoEncoder  22

#define motorFourthPinOneEncoder  13
#define motorFourthPinTwoEncoder  15


PWM_Setup motorOnePWM(motorOnePWMPin, motorOneChannel, motorOneFrequency, motorOneResolution);

PWM_Setup motorTwoPWM(motorTwoPWMPin, motorTwoChannel, motorTwoFrequency, motorTwoResolution);

PWM_Setup motorThreePWM(motorThreePWMPin, motorThreeChannel, motorThreeFrequency, motorThreeResolution);

PWM_Setup motorFourthPWM(motorFourthPWMPin, motorFourthChannel, motorFourthFrequency, motorFourthResolution);


Motor_L29 motorOne(motorOnePinOne,motorOnePinTwo, motorOneChannel, motorOnePinOneEncoder, motorOnePinTwoEncoder);

Motor_L29 motorTwo(motorTwoPinOne, motorTwoPinTwo, motorTwoChannel,motorTwoPinOneEncoder, motorTwoPinTwoEncoder);

Motor_L29 motorThree(motorThreePinOne, motorThreePinTwo,motorThreeChannel,motorThreePinOneEncoder, motorThreePinTwoEncoder);

Motor_L29 motorFourth(motorFourthPinOne,motorFourthPinTwo, motorFourthChannel,motorFourthPinOneEncoder, motorFourthPinTwoEncoder);

//EngineHB controlCenter;

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
      
  attachInterrupt(digitalPinToInterrupt(motorOnePinTwoEncoder),readEncoder<0>,RISING);

  attachInterrupt(digitalPinToInterrupt(motorTwoPinTwoEncoder),readEncoder<1>,RISING);

  attachInterrupt(digitalPinToInterrupt(motorThreePinTwoEncoder),readEncoder<2>,RISING);

  attachInterrupt(digitalPinToInterrupt(motorFourthPinTwoEncoder),readEncoder<3>,RISING);

  //motorOnePID.encoderRutine();

  //motorTwoPID.encoderRutine();

  //motorThreePID.encoderRutine();

  //motorFourthPID.encoderRutine();

  motorOnePID.setResolution(motorOnePWM.Resolution);

  motorTwoPID.setResolution(motorTwoPWM.Resolution);

  motorThreePID.setResolution(motorThreePWM.Resolution);

  motorFourthPID.setResolution(motorFourthPWM.Resolution);

  //pinMode(8, OUTPUT);
  
  //pinMode(21, OUTPUT);

  



   //pinMode(12, OUTPUT);

   //pinMode(14, OUTPUT);
   
   //digitalWrite(12,LOW);

   //digitalWrite(14,HIGH);

 

   //ledcSetup(0, 1000, 8); 

   //ledcAttachPin(27, 0);

   //ledcWrite(0, 254);

   Serial.begin(9600);

   //motorOne.run("FORWARD");

   //motorTwo.run("FORWARD");

   //motorThree.run("FORWARD");

   //motorFourth.run("FORWARD");

   

   digitalWrite(8,HIGH);

   //digitalWrite(2,LOW);


}

void loop() {
  

  //controlCenter.coordinate(2,3,motorOne,motorTwo,motorThree, motorFourth);

  //ledcWrite(motorOneChannel, 255);

  

  //Serial.println("xd");

  motorOnePID.calculatePID(400,vfilter[0]);
  motorOne.SetSpeed(motorOnePID.PID);

  motorTwoPID.calculatePID(0,vfilter[1]);
  motorTwo.SetSpeed(motorTwoPID.PID);

  motorThreePID.calculatePID(0,vfilter[2]);
  motorThree.SetSpeed(motorThreePID.PID);

  motorFourthPID.calculatePID(400,vfilter[3]);
  motorFourth.SetSpeed(motorFourthPID.PID);

   //Serial.print(",");
  Serial.print(vfilter[0]);
  Serial.print(",");
   Serial.print(vfilter[1]);
  Serial.print(",");
   Serial.print(vfilter[2]);
  Serial.print(",");
  //Serial.println(150);
  //Serial.println(motorOnePID.PID);
  //Serial.println(",");

  Serial.println(vfilter[3]);
  //Serial.println(",");

  //Serial.println(motorOnePID.PID);
  //Serial.println(",");

  //Serial.println(velocity[1]);
  //Serial.print(",");
  //Serial.println(motorTwoPID.PID);

  

  

}
