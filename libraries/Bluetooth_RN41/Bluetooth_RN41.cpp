#include "Arduino.h"
#include "Bluetooth_RN41.h"
#include "SoftwareSerial.h"


/*Bluetooth_RN41::Bluetooth_RN41(int rx, int tx){
  SoftwareSerial BTSerial(rx, tx);
}*/

void Bluetooth_RN41::begin(bool master, String address = ""){
  BTSerial.begin(115200); 
  send("$$$", false);
  receive();
  send("U,9600,N", true);
  BTSerial.begin(9600); 
  delay(100);
  send("$$$", false);
  receiveNoEnd();
  if(master){
    send("SM,1");
  }else{
    send("SM,0");
  }
  receive();
  send("---");
  receive();
  BTSerial.flush();
  if(master) connect(address);
  #ifdef DEBUG
    Serial.println("Bluetooth started");
  #endif
}

//todo: adress as string
void Bluetooth_RN41::connect(String address){
  send("$$$", false);
  receive();
  send("C,", false);
  BTSerial.println(address);
  receive();
  send("---");
  receive();
  delay(1000);
}

void Bluetooth_RN41::send(char* i_pBtCmd, bool i_ln = true){
  if(i_ln){
    BTSerial.println(i_pBtCmd);
  } else{
    BTSerial.print(i_pBtCmd);
  }
  delay(100);
}

void Bluetooth_RN41::receive(){
  bool keepReading = true;
  int index = 0;
  //gBtMsg[0] = '\0';
  while(keepReading){
    keepReading = false;
    if (BTSerial.available() > 0) {
      // read the incoming byte:
      delay(5);
      incomingByte = BTSerial.read();
      if(incomingByte != 13){
        gBtMsg[index++] = incomingByte;
        #ifdef DEBUG
          Serial.write(incomingByte);
        #endif
        keepReading = true;
      }
    }
  }
  gBtMsg[index] = '\0';
}

void Bluetooth_RN41::receiveNoEnd(){
bool keepReading = true;
  int index = 0;
  gBtMsg[0] = '\0';
  while(keepReading){
    keepReading = false;
    if (BTSerial.available() > 0) {
      // read the incoming byte:
      incomingByte = BTSerial.read();
      gBtMsg[index++] = incomingByte;
      #ifdef DEBUG  
        Serial.write(incomingByte);
      #endif
      keepReading = true;
    }
  }
  gBtMsg[index] = '\0';
}

void Bluetooth_RN41::parseCommand(){
  int _x = 0;
  int _y = 0;
  bool test = false;
  if('#'==gBtMsg[0]){
    gBtMsg[0]=0;
    for(int i = 1; i < 256; i++){
      if(','==gBtMsg[i] || (gBtMsg[i] > 47 && gBtMsg[i] < 58)){
        if(','==gBtMsg[i]){
          test = true;
        }
        if('!'==gBtMsg[i+1]){
          break;
        }
        if(!test){
          _x = (_x*10)+(gBtMsg[i]-48);
        }else{
          _y = (_y*10)+(gBtMsg[i+1]-48);  
        }
        x = _x;
        y = _y;
      }else{
        break;
      }
    }
  }
}

void Bluetooth_RN41::sendDirections(int ax, int ay){
  BTSerial.print("#");
  BTSerial.print(ax);
  BTSerial.print(",");
  BTSerial.print(ay);
  BTSerial.println("!");
}

void Bluetooth_RN41::viewSettings(){
  send("$$$", false);
  receive();
  send("D");
  delay(10);
  while(BTSerial.available() > 0){
    Serial.write(BTSerial.read());
  }
  receiveNoEnd();
  send("---");
  receive();
  delay(1000);
}

int Bluetooth_RN41::getX(){
  return x;
}

int Bluetooth_RN41::getY(){
  return y;
}