#include "util/delay.h"
#include "Control.h"


void changeOutputs(int output) {
  int i;
  unsigned int temp = output;
  
  if((output & 0x0fff) != OutputsStatus) {
      cmd_index++;
      for(i = 0; i < (sizeof(Outputs) / sizeof(Outputs[0])); i++) {
        if(temp & 0x01) {
          active(Outputs[i]);
        } else {
          deactive(Outputs[i]);
        }
        temp = temp >> 1;
      }
  }
  respond("T");
}


void changeMode(String data) {
  if(data == "AUTO") {
    manual = false;
  } else if(data == "MANU") {
    manual = true;
  }
  respond("M");
}

void uint16_2_hexstr(unsigned int data, char str[]) {
  int temp = 0;
  temp |= data & 0x0f;
  if(temp < 10)
    str[2] = temp + '0';
  else
    str[2] = temp + 'A';

  temp = 0;
  temp |= (data & 0xf0) >> 4;
  if(temp < 10)
    str[1] = temp + '0';
  else
    str[1] = temp + 'A';

  temp = 0;
  temp |= (data & 0x700) >> 8;
  if(temp < 10)
    str[0] = temp + '0';
  else
    str[0] = temp + 'A';
}

void CheckButtons() {
  if(Read(BUTTON_START)) StartButton();
  if(Read(BUTTON_STOP)) StopButton();
  if(Read(BUTTON_RESET)) ResetButton();
}
/*
void setup() {
  CommSetup();
  IOSetup();
  Setup();
}

void loop() {
  CheckButtons();
  Loop();
}
*/
void IOSetup() {
  int i;
  //Setting Output
  pinMode(SOL1,  OUTPUT);
  pinMode(SOL2,  OUTPUT);
  pinMode(SOL3,  OUTPUT);
  pinMode(SOL4,  OUTPUT);
  pinMode(SOL5,  OUTPUT);
  pinMode(M1,    OUTPUT);
  pinMode(M2,    OUTPUT);
  pinMode(BUZZ,    OUTPUT);
  pinMode(PL1,   OUTPUT);
  pinMode(PL2,   OUTPUT);
  pinMode(PL3,   OUTPUT);
  pinMode(PL4,   OUTPUT);
  
  for(i = 0; i < sizeof(Outputs) / sizeof(Outputs[0]); i++) off(Outputs[i]);

  //Setiing Input
  pinMode(CS1,   INPUT);
  pinMode(CS2,   INPUT);
  pinMode(CS3,   INPUT);
  pinMode(CS4,   INPUT);
  pinMode(CS5,   INPUT);
  pinMode(CS6,   INPUT);
  pinMode(CS7,   INPUT);
  pinMode(CS8,   INPUT);
  pinMode(S1,    INPUT);
  pinMode(S2,    INPUT);
  pinMode(S3,    INPUT);
  pinMode(S4,    INPUT);

  pinMode(BUTTON_START,    INPUT);
  pinMode(BUTTON_STOP,     INPUT);
  pinMode(BUTTON_RESET,    INPUT);
}
