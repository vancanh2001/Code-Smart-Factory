#include "IOhelper.h" 
#include "Control.h"
unsigned long count;
void setup() {  //최초 한 번만 실행된다.
    IOSetup();
}

void loop() {  //반복 해서 실행된다.
    delay(1);
    count = count + 1;
    if(count == 1 * SEC) {
        M1_on();
    }
    if(count == 2 * SEC) {
        M1_off();
        count = 0;
    }
}
void StartButton() {}  //Button_Start
void StopButton() {}  //Button_Stop
void ResetButton() {}  //Button_Reset
