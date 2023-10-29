template <int j>

void IRAM_ATTR readEncoder(){
  
  int b = digitalRead(enca[j]);
  
  if(b > 0){
    
    positions[j]=1;
    
  }
  else{
    
    positions[j]=-1;
  }

  currT_velocity[j] = micros();

  deltaT_velocity[j] = ((float)(currT_velocity[j] - prevT_velocity[j])) / 1.0e6 ;

  velocity[j] = (positions[j] / deltaT_velocity[j]*0.5 + prevelocity[j]+ preprevelocity[j])/3;

  if (velocity[j] > 1000 || velocity[j] < -1000 ){
    
    velocity[j] = prevelocity[j]; 
    
    }

  prevT_velocity[j] = currT_velocity[j];

  vfilter[j] = 0.854*vfilter[j] + 0.0728*velocity[j]+ 0.0728*prevelocity[j];

  prevelocity[j] = velocity[j];

  preprevelocity[j] =  prevelocity[j];
  
}
