/*
   Neutron magpie dodeca: 

   LEFT SIDE

1) Velocity (synth voice) Midi Channel 3
2) Note out (synth voice) Midi Channel 3
3) Gate (synth voice) Midi Channel 3
4) CC# 71 MIDI Channel 1
5) Note to Gate/Trig - C Midi Channel 1
6) CC #72 MIDI Channel 1
7) Note to Gate/Trig - D Midi Channel 1
😎 CC #73 MIDI Channel 1
9) Note to Gate/Trig - E Midi Channel 1
10) CC #74 MIDI Channel 1
11) CC #75 MIDI Channel 1
12) CC #76 MIDI Channel 1

  
 * */

#include <MIDI.h>

const uint8_t CHANA = 1;//set the MIDI channel here!
const uint8_t CHANB = 3;

uint8_t out2pin[] = {23, 0, 22, 25, 20, 6, 21, 5, 9, 4, 10, 3};//output number to actual teensy pin, dont change.
uint8_t whitekeys[] = {4, 0, 6, 0, 8, 0, 0, 0, 0, 0, 0, 0};//non zero keys sent to output number.
uint8_t pulses;
uint8_t sixteenthnotes; 
uint8_t quartertoggle;
uint8_t wholetoggle;
bool playing;



uint8_t cc2active[] = {71, 72, 73, 74, 75, 76 };
uint8_t cc2out[] = {3, 5, 7, 9, 10, 11};



void setup() {
  // Initiate MIDI communications, listen to all channels

  for (int i = 0; i < 12; i ++) {
    if (out2pin[i]) {
      pinMode(out2pin[i], OUTPUT);
      analogWriteFrequency(out2pin[i], 200000);
    }
  }

  analogWriteResolution(7);
  
   for (int i = 0; i < 12; i ++) {//start up LED animation
    for (int j = 0; j < 128; j ++) {
      if (out2pin[i] == 0) analogWrite(A14, (j ));
      else analogWrite(out2pin[i], j );
      delay(1);
    }
    if (out2pin[i] == 0) analogWrite(A14, 0);
    analogWrite(out2pin[i], 0);
  }//end of start up animantion

  MIDI.begin(MIDI_CHANNEL_OMNI);
  // Connect the Handlers to the library, so it is called upon reception.
  MIDI.setHandleNoteOn(HandleNoteOn);  // Put only the name of the function
  MIDI.setHandleControlChange(HandleControlChange);
  MIDI.setHandleNoteOff(HandleNoteOff);
//  MIDI.setHandleClock(HandleClock);
//  MIDI.setHandleStart(HandleStart);
//  MIDI.setHandleStop(HandleStop);
//  MIDI.setHandleContinue(HandleContinue);

  Serial.begin(9600);
}

void loop() {
  // Call MIDI.read the fastest you can for real-time performance.
  MIDI.read();

  // There is no need to check if there are messages incoming if they are bound to a Callback function.
}
