#include "IOhelper.h"
#include "Control.h"

unsigned char Outputs[12] = {SOL1, SOL2, SOL3, SOL4, SOL5, M1, M2, BUZZ, PL1, PL2, PL3, PL4};
unsigned char Sensors[12] = {CS1, CS2, CS3, CS4, CS5, CS6, CS7, CS8, S1, S2, S3, S4};
unsigned char Buttons[3] = {BUTTON_START, BUTTON_STOP, BUTTON_RESET};
volatile unsigned int OutputsStatus = 0;

unsigned int Read_ALL() {
  int i;
  unsigned int data = 0;
  for(i = 0; i < sizeof(Sensors) / sizeof(Sensors[0]); i++) data += Read(Sensors[i]) << i;
  return data;
}

void IntToBitArray(int data, unsigned char* buf) {
  int i, temp;
  temp = data;
  for(i = 0; i < 12; i++){
    buf[i] = temp % 2 ;
    temp = temp / 2;
    Serial1.write(temp);
  }
}

//Shortcut
//Output
void on(int x) {
  active(x);
  cmd_index++;
}

void off(int x) {
  deactive(x);
  cmd_index++;
}

void active(int x) {
  int i;
  for(i = 0; i < sizeof(Outputs) / sizeof(Outputs[0]); i++)
    if(x == Outputs[i]) {
      digitalWrite(x, HIGH);
      OutputsStatus |= (1 << i);
    }
}

void deactive(int x) {
  int i;
  for(i = 0; i < sizeof(Outputs) / sizeof(Outputs[0]); i++)
    if(x == Outputs[i]) {
      digitalWrite(x, LOW);
      OutputsStatus &= ~(1 << i);
    }
}

void Forward(int x) {on(x);}
void Backward(int x) {off(x);}

void SOL1_on()  {on(SOL1);}
void SOL1_off() {off(SOL1);}
void SOL2_on()  {on(SOL2);}
void SOL2_off() {off(SOL2);}
void SOL3_on()  {on(SOL3);}
void SOL3_off() {off(SOL3);}
void SOL4_on()  {on(SOL4);}
void SOL4_off() {off(SOL4);}
void SOL5_on()  {on(SOL5);}
void SOL5_off() {off(SOL5);}

void SOL1_Forward()  {Forward(SOL1);}
void SOL1_Backward() {Backward(SOL1);}
void SOL2_Forward()  {Forward(SOL2);}
void SOL2_Backward() {Backward(SOL2);}
void SOL3_Forward()  {Forward(SOL3);}
void SOL3_Backward() {Backward(SOL3);}
void SOL4_Forward()  {Forward(SOL4);}
void SOL4_Backward() {Backward(SOL4);}
void SOL5_Forward()  {Forward(SOL5);}
void SOL5_Backward() {Backward(SOL5);}

void M1_on()  {on(M1);}
void M1_off() {off(M1);}
void M2_on()  {on(M2);}
void M2_off() {off(M2);}

void CONVEYOR_on()   {M2_on();}
void CONVEYOR_off()  {M2_off();}
void CONV_on()       {M2_on();}
void CONV_off()      {M2_off();}

void PL1_on()  {on(PL1);}
void PL1_off() {off(PL1);}
void PL2_on()  {on(PL2);}
void PL2_off() {off(PL2);}
void PL3_on()  {on(PL3);}
void PL3_off() {off(PL3);}
void PL4_on()  {on(PL4);}
void PL4_off() {off(PL4);}

void BUZZ_on() {on(BUZZ);}
void BUZZ_off() {off(BUZZ);}

void BLUE_LAMP_on()    {on(BLUE_LAMP);}
void BLUE_LAMP_off()   {off(BLUE_LAMP);}
void GREEN_LAMP_on()   {on(GREEN_LAMP);}
void GREEN_LAMP_off()  {off(GREEN_LAMP);}
void YELLOW_LAMP_on()  {on(YELLOW_LAMP);}
void YELLOW_LAMP_off() {off(YELLOW_LAMP);}
void RED_LAMP_on()     {on(RED_LAMP);}
void RED_LAMP_off()    {off(RED_LAMP);}

void sol1(boolean onoff) {onoff ? SOL1_on() : SOL1_off();}
void sol2(boolean onoff) {onoff ? SOL2_on() : SOL2_off();}
void sol3(boolean onoff) {onoff ? SOL3_on() : SOL3_off();}
void sol4(boolean onoff) {onoff ? SOL4_on() : SOL4_off();}
void sol5(boolean onoff) {onoff ? SOL5_on() : SOL5_off();}
void m1(boolean onoff)   {onoff ? M1_on() : M1_off();}
void m2(boolean onoff)   {onoff ? M2_on() : M2_off();}
void buzz(boolean onoff)   {onoff ? BUZZ_on() : BUZZ_off();}
void pl1(boolean onoff)  {onoff ? PL1_on() : PL1_off();}
void pl2(boolean onoff)  {onoff ? PL2_on() : PL2_off();}
void pl3(boolean onoff)  {onoff ? PL3_on() : PL3_off();}
void pl4(boolean onoff)  {onoff ? PL4_on() : PL4_off();}

void conveyor(boolean onoff) {m2(onoff);}
void conv(boolean onoff)     {m2(onoff);}

void blue_lamp(boolean onoff)   {onoff ? BLUE_LAMP_on() : BLUE_LAMP_off();}
void green_lamp(boolean onoff)  {onoff ? GREEN_LAMP_on() : GREEN_LAMP_off();}
void yellow_lamp(boolean onoff) {onoff ? YELLOW_LAMP_on() : YELLOW_LAMP_off();}
void red_lamp(boolean onoff)    {onoff ? RED_LAMP_on() : RED_LAMP_off();}
