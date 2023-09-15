#include "PWM_Setup.h" 
#include "EngineHB.h"
#include "ControlPID.h"
#include "Motor_L29.h"

#define motorOneFrequency 2
#define motorTwoFrequency 2
#define motorThreeFrequency 2
#define motorFourthFrequency 2

#define motorOneChannel 2
#define motorTwoChannel 2
#define motorThreeChannel 2
#define motorFourthChannel 2

#define motorOneResolution 2
#define motorTwoResolution 2
#define motorThreeResolution 2
#define motorFourthResolution 2

#define motorOnePWMPin 2
#define motorTwoPWMPin 2
#define motorThreePWMPin 2
#define motorFourthPWMPin 2

#define motorOnePinOne 2
#define motorOnePinTwo 2

#define motorTwoPinOne 2
#define motorTwoPinTwo 2

#define motorThreePinOne 2
#define motorThreePinTwo 2

#define motorFourthPinOne 2
#define motorFourthPinTwo 2


#define motorOnePinOneEncoder 2
#define motorOnePinTwoEncoder  2

#define motorTwoPinOneEncoder  2
#define motorTwoPinTwoEncoder  2

#define motorThreePinOneEncoder  2
#define motorThreePinTwoEncoder  2

#define motorFourthPinOneEncoder  2
#define motorFourthPinTwoEncoder  2

PWM_Setup motorOnePWM(motorOnePWMPin, motorOneChannel, motorOneFrequency, motorOneResolution);

PWM_Setup motorTwoPWM(motorTwoPWMPin, motorTwoChannel, motorTwoFrequency, motorTwoResolution);

PWM_Setup motorThreePWM(motorThreePWMPin, motorThreeChannel, motorThreeFrequency, motorThreeResolution);

PWM_Setup motorFourthPWM(motorFourthPWMPin, motorFourthChannel, motorFourthFrequency, motorFourthResolution);

Motor_L29 motorOne(motorOnePinOne,motorOnePinTwo, motorOneChannel, motorOnePinOneEncoder, motorOnePinTwoEncoder);

Motor_L29 motorTwo(motorTwoPinOne, motorTwoPinTwo, motorTwoChannel,motorTwoPinOneEncoder, motorTwoPinTwoEncoder);

Motor_L29 motorThree(motorThreePinOne, motorThreePinTwo,motorThreeChannel,motorThreePinOneEncoder, motorThreePinTwoEncoder);

Motor_L29 motorFourth(motorFourthPinOne,motorFourthPinTwo, motorFourthChannel,motorFourthPinOneEncoder, motorFourthPinTwoEncoder);

//ControlPID motorOnePID(motorOnePinOneEncoder, motorOnePinTwoEncoder);

//ControlPID motorTwoPID(motorTwoPinOneEncoder, motorTwoPinTwoEncoder);

//ControlPID motorThreePID(motorThreePinOneEncoder, motorThreePinTwoEncoder);

//ControlPID motorFourthPID(motorFourthPinOneEncoder, motorFourthPinTwoEncoder);


void setup() {

  //attachInterrupt(digitalPinToInterrupt(motorOnePinTwoEncoder),motorOnePID.readEncoder,RISING);

  //attachInterrupt(digitalPinToInterrupt(motorTwoPinTwoEncoder),motorTwoPID.readEncoder,RISING);

 // attachInterrupt(digitalPinToInterrupt(motorThreePinTwoEncoder),motorThreePID.readEncoder,RISING);

  //attachInterrupt(digitalPinToInterrupt(motorFourthPinTwoEncoder),motorFourthPID.readEncoder,RISING);

  //motorOnePID.encoderRutine();

  //motorTwoPID.encoderRutine();

  //motorThreePID.encoderRutine();

  //motorFourthPID.encoderRutine();

   motorOne.dynamic->encoderRutine();

   motorOne.dynamic->setResolution(motorOnePWM.Resolution);

   motorTwo.dynamic->encoderRutine();

   motorTwo.dynamic->setResolution(motorTwoPWM.Resolution);

   motorThree.dynamic->encoderRutine();

   motorThree.dynamic->setResolution(motorThreePWM.Resolution);

   motorFourth.dynamic->encoderRutine();

   motorFourth.dynamic->setResolution(motorFourthPWM.Resolution);

   


}

void loop() {
  // put your main code here, to run repeatedly:

}
