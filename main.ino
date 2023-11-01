#include "PWM_Setup.h" 
#include "EngineHB.h"
#include "ControlPID.h"
#include "Motor_L29.h"
#include <Arduino.h>
#include "telemetry.h"

#define motorOneFrequency 2000
#define motorTwoFrequency 15000
#define motorThreeFrequency 15000
#define motorFourthFrequency 15000

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

telemetry bluetooth; 




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

   motorOne.run("FORWARD");

   motorTwo.run("FORWARD");

   motorThree.run("FORWARD");

   motorFourth.run("FORWARD");

   

   //digitalWrite(8,HIGH);

   //digitalWrite(2,LOW);

   //pinMode(34, INPUT);

   //pinMode(35, INPUT);

   motorOne.SetSpeed(4000);


}

void loop() {

  float DataBluetooth[5];

  bluetooth.getData(DataBluetooth);

  Serial.print(DataBluetooth[0]);

  Serial.print(",");

  Serial.print(DataBluetooth[1]);
  
  //controlCenter.coordinate(2,3,motorOne,motorTwo,motorThree, motorFourth);

  //ledcWrite(motorOneChannel, 5000);
  //Serial.println("xd");

  //motorOnePID.calculatePID(5000*sin(micros()/10e6*10),vfilter[0]);
  //motorOne.SetSpeed(motorOnePID.PID);

  //motorTwoPID.calculatePID(5000*cos(micros()/10e6*10),vfilter[1]);
  //motorTwo.SetSpeed(motorTwoPID.PID);

  //motorThreePID.calculatePID(5000*cos(micros()/10e6*10),vfilter[2]);
  //motorThree.SetSpeed(motorThreePID.PID);

  //motorFourthPID.calculatePID(5000*sin(micros()/10e6*10),vfilter[3]);
  //motorFourth.SetSpeed(motorFourthPID.PID);


  //motorOnePID.calculatePID(500,vfilter[0]);
  //motorOne.SetSpeed(motorOnePID.PID);
  //motorTwo.SetSpeed(5000);

  //motorTwoPID.calculatePID(500,vfilter[1]);
  //motorTwo.SetSpeed(motorTwoPID.PID);

  //motorThreePID.calculatePID(500,vfilter[2]);
  //motorThree.SetSpeed(motorThreePID.PID);

  //motorFourthPID.calculatePID(500,vfilter[3]);
  //motorFourth.SetSpeed(motorFourthPID.PID);
   //Serial.print(",");
  //Serial.print(vfilter[0]);
  //Serial.print(",");
  //Serial.print(vfilter[1]);
  //Serial.print(",");
  //Serial.print(vfilter[2]);
  //Serial.print(",");
  //Serial.println(150);
  //Serial.println(motorOnePID.PID);
  //Serial.println(",");
  //Serial.println(vfilter[3]);
  //Serial.println(",");

  //Serial.println(motorOnePID.PID);
  //Serial.println(",");

  //Serial.println(velocity[1]);
  //Serial.print(",");
  //Serial.println(motorTwoPID.PID);


  //if (digitalRead(34) == HIGH){
    
    
   // Serial.println("alto");
    //}

   //else {

    //Serial.println("bajo");

    //}
  

}
