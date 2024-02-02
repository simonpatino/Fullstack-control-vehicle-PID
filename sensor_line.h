
//####################### Functions of moving ##########################

void forward(int speed_left, int speed_right)
{
    motorTwo.SetSpeed(-speed_left);
    motorThree.SetSpeed(speed_left);
    motorOne.SetSpeed(speed_right);
    motorFourth.SetSpeed(-speed_right);
}

void reverse(int speed)
{
    motorTwo.SetSpeed(speed);
    motorThree.SetSpeed(-speed);
    motorOne.SetSpeed(-speed);
    motorFourth.SetSpeed(speed);
}

void right_shift(int speed_fl_fwd, int speed_rl_bck, int speed_rr_fwd, int speed_fr_bck)
{
    motorTwo.SetSpeed(speed_fl_fwd);
    motorThree.SetSpeed(-speed_rl_bck);
    motorOne.SetSpeed(speed_rr_fwd);
    motorFourth.SetSpeed(-speed_fr_bck);
}

void left_shift(int speed_fl_bck, int speed_rl_fwd, int speed_rr_bck, int speed_fr_fwd)
{
    motorTwo.SetSpeed(-speed_fl_bck);
    motorThree.SetSpeed(speed_rl_fwd);
    motorOne.SetSpeed(-speed_rr_bck);
    motorFourth.SetSpeed(speed_fr_fwd);
}

void left_turn(int speed)
{
    motorTwo.SetSpeed(0);
    motorThree.SetSpeed(0);
    motorOne.SetSpeed(speed);
    motorFourth.SetSpeed(-speed);
}

void right_turn(int speed)
{
    motorTwo.SetSpeed(-speed);
    motorThree.SetSpeed(speed);
    motorOne.SetSpeed(0);
    motorFourth.SetSpeed(0);
}

// Without using 
    
void right_back(int speed)
{
    motorTwo.SetSpeed(speed);
    motorThree.SetSpeed(0);
    motorOne.SetSpeed(0);
    motorFourth.SetSpeed(speed);
}

void sharpRightTurn(int speed_left, int speed_right)
{
    motorTwo.SetSpeed(-speed_left);
    motorThree.SetSpeed(speed_right);
    motorOne.SetSpeed(-speed_right);
    motorFourth.SetSpeed(speed_left);
}

void sharpLeftTurn(int speed_left, int speed_right)
{
    motorTwo.SetSpeed(speed_left);
    motorThree.SetSpeed(-speed_left);
    motorOne.SetSpeed(speed_right);
    motorFourth.SetSpeed(-speed_right);
}

void stop_bot() 
{
  
  motorOne.SetSpeed(0);
  motorTwo.SetSpeed(0);
  motorThree.SetSpeed(0);
  motorFourth.SetSpeed(0);
  delay(40);

}



//#################### End Functions of moving ########################


//#################### Line Sensor Tracking  ##########################

#define HIGH_SPEED 16383
#define MID_SPEED 16383*0.92   // 65 , 625 is the best option
#define LOW_SPEED 16383*0.8     //here was 0.5 in good options     
#define LONG_DELAY_TIME 70*1.8 
#define DELAY_TIME 40*1.8 
#define SHORT_DELAY_TIME 30*1.8 
#define a 0.69

void tracking()
{
  String senstr="";

  int s0 = !digitalRead(S1);
  int s1 = !digitalRead(S2);
  int s2 = !digitalRead(S3);
  int s3 = !digitalRead(S4);
  int s4 = !digitalRead(S5);

  int sensorvalue=32;

  sensorvalue +=s0*16+s1*8+s2*4+s3*2+s4;

  senstr= String(sensorvalue,BIN);

  senstr=senstr.substring(1,6);
  
  Serial.println(senstr);
  //Serial.print("\t");
 
  if ( senstr=="10000" || senstr=="01000" || senstr=="11000")
   {
     Serial.println(" Shift Left");
      sharpLeftTurn(LOW_SPEED,MID_SPEED);
    //  left_shift(HIGH_SPEED,HIGH_SPEED,HIGH_SPEED,HIGH_SPEED);
      delay(DELAY_TIME);
      stop_bot();     
   }
   
  if ( senstr=="11100" || senstr=="10100" )
  {
     Serial.println("Slight Shift Left");
      forward(0,HIGH_SPEED);
      delay(DELAY_TIME);
      stop_bot(); 
  }
  if ( senstr=="01100" ||  senstr=="11110"  || senstr=="10010"  || senstr=="10110"  || senstr=="11010")
  {
     Serial.println("Slight Left");
      forward(LOW_SPEED,MID_SPEED);
      delay(DELAY_TIME);
  }
 if (senstr=="01110" || senstr=="01010" || senstr=="00100"  || senstr=="10001"  || senstr=="10101"  || senstr=="10011" || senstr=="11101" || senstr=="10111" || senstr=="11011"  || senstr=="11001")
  {
     Serial.println("Forward");          //FORWARD
      forward(HIGH_SPEED*a,HIGH_SPEED*a);
      delay(DELAY_TIME);
      stop_bot(); 
  }
 if ( senstr=="00110" || senstr=="01111" || senstr=="01001" || senstr=="01011" || senstr=="01101")
  {
        Serial.println("Slit Right");
      forward(MID_SPEED,LOW_SPEED);
      delay(DELAY_TIME);
       stop_bot(); 
  }
 if (senstr=="00111" || senstr=="00101" )
  {    Serial.println("Slight Shift to Right ");
       forward(HIGH_SPEED,0);
      delay(DELAY_TIME);
      stop_bot(); 
  }
 if (senstr=="00001" || senstr=="00010" || senstr=="00011")
 {
   Serial.println("Shift to Right");
   sharpRightTurn(MID_SPEED,LOW_SPEED);
    //  right_shift(HIGH_SPEED,HIGH_SPEED,HIGH_SPEED,HIGH_SPEED);
      delay(DELAY_TIME);
      stop_bot();   
        
 }
  if (  senstr=="00000"){      //REVERSE

      
 //forward(HIGH_SPEED*a,HIGH_SPEED*a); 

      reverse(MID_SPEED*0.65) ;   // here was mid speed with 0.625
 
      delay(DELAY_TIME);
      stop_bot();  
  }
 if (  senstr=="11111")
 {
   Serial.println("Sharp Right U Turn");
      sharpRightTurn(MID_SPEED,MID_SPEED);
      delay(DELAY_TIME);
      stop_bot();     
 }

}



 //################### End Line Sensor Tracking  ##########################
