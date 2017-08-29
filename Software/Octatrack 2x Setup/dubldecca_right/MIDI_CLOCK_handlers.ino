void HandleClock(void){
  if (playing){
  pulses ++;
  if (pulses > 5){
    pulses = 0;
    sixteenthnotes ++;
  }
  if (pulses < 3){
    analogWrite(out2pin[3],127);
  }
   else analogWrite(out2pin[3],0);
}
}

 void HandleStart(){
  pulses = 0;
  sixteenthnotes = 0;
  playing = 1;    
  }
  
 void HandleStop(){
  playing = 0; //remove this to have continuous clock pulses on dodeca after sequencer is stopped
  digitalWriteFast(out2pin[3],LOW);  //turn pulse off when stopped even if it is in the middle of "on" cycle
  }

  
  void HandleContinue(){
    //maybe only needed for song position pointer
  }

