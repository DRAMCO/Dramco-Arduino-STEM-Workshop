#include "Remote.h"
#include "Bluetooth_RN41.h"

#define RX 9
#define TX 8

Remote remote;
Bluetooth_RN41 bluetooth(RX,TX);

bool master = true;
String address = "";     //Fill this in yourself! Find out the address! 

void setup(){
  delay(1000);
}

void loop() {

}
