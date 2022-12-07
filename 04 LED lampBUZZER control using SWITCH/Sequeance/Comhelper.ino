#include "Control.h"

char store_str[10] = "";
volatile char store_index = 0;
String send_msg = "";
char cmd_index = 0;
boolean manual;
unsigned long cmd_delay = 0;
char store_buf[8] = "";

void CommSetup() {
  Serial1.begin(9600);
  Serial.begin(9600);
}

void readSerial(char* result) {
  char ch;
  char buf[8];
  while(Serial1.available()) {
    ch = Serial1.read();
    if(store_index == 0) {
      if(ch == '$') {
        store_str[store_index] = ch;
        store_index++;
      }
    } else if(ch != '&' || store_index < 6){
        store_str[store_index++] = ch;
    } else{
      store_str[store_index++] = ch;
      memcpy(result, store_str, store_index);
      store_index = 0;
      break;
    }
  }
}

void respond(String cmd) {
  int i;
  char buf[8];
  int temp;
  send_msg = "";
  if(cmd == "M") {
      if(manual) send_msg = "$MMANU&";
      else send_msg = "$MAUTO&";
  } else if(cmd == "T") {
      send_msg = "$Qasdf&";
      send_msg.toCharArray(buf, 8);
      
      temp = Read_ALL();
      buf[2] = char((temp & 0xff00) >> 8);
      buf[3] = char(temp & 0xff);
      
      temp = OutputsStatus;
      buf[4] = char(((temp & 0x0f00) >> 8) | cmd_index << 4);
      buf[5] = char(temp & 0x00ff);

//      if(cmd_delay++ >= 50) {
//        cmd_delay = 0;
//        Serial1.write(buf, 7);
//        for(i = 0; i < 7; i++)
//          Serial.print(buf[i], HEX);
//        Serial.print('\n');
//      }
      if((check_cmd(buf) && cmd_delay++ >= 300) || cmd_delay++ >= 900) {
        cmd_delay = 0;
        Serial1.write(buf, 7);
        for(i = 0; i < 7; i++)
          Serial.print(buf[i], HEX);
        Serial.print('\n');        
      }
      return;
  }

  send_msg.toCharArray(buf, 8);
  Serial1.write(buf);
}

boolean check_cmd(char * buf) {
  int i;
  for(i = 0; i < 7; i++) {
    if(store_buf[i] != buf[i]) {
      memcpy(store_buf, buf, 7);
      return true;
    }
  }
  return false;
}

void seperate(String str, String* cmd, String* data) {
  *cmd = str.substring(1, 2);
  *data = str.substring(2, 6);
}

void seperate(char* str, char* cmd, char* data) {
  memcpy(cmd, &str[1], 1);
  memcpy(data, &str[2], 4);

}

void readAndDO() {
  char result[10] = "QWERTY";
  unsigned char cmd[2]="", data[5]="";
  char buf[8];
  unsigned int temp = 0;
  
  readSerial(result);
  if(result[0] != 'Q') {
    seperate(result, cmd, data);
    if(cmd[0] == 'M') {
      changeMode(data);
    } else if(cmd[0] == 'T') {
      if((data[2] >> 4) == (cmd_index & 0x0f)) {
        temp = ((int)data[2] << 8) | data[3];
        if(manual)
          changeOutputs(temp);
        else {
          cmd_index++;
        }
      }
    } else if(cmd[0] == 'B') {
        if(data[0] == 'S' && data[1] == 'T' && data[2] == 'R' && data[3] == 'T') StartButton();
        if(data[0] == 'S' && data[1] == 'T' && data[2] == 'O' && data[3] == 'P') StopButton();
        if(data[0] == 'R' && data[1] == 'S' && data[2] == 'E' && data[3] == 'T') ResetButton();
          
      
//      if(data == "STRT") {
//        StartButton();
//      } else if(data == "STOP") {
//        StopButton();
//      } else if(data == "RSET") {
//        ResetButton();
//      }
    }
    respond(cmd);
  }else respond("T");
}
