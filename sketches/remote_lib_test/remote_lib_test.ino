#include "Remote.h"
#include "Bluetooth_RN41.h"

#define RX 9
#define TX 8

Remote remote;
Bluetooth_RN41 bluetooth(RX,TX);

bool master = true;
String address = "0006667D97A8";

void setup(){
  delay(1000);
  remote.begin();
  bluetooth.begin(master, address);
}

void loop() {
  bluetooth.receive();
  remote.readDirections();
  int x = remote.getX();
  int y = remote.getY();
  Serial.println(x);
  Serial.println(y);
  bluetooth.sendDirections(x, y);
  delay(100);
}
