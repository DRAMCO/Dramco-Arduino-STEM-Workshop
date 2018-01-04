#include "Robot.h"
#include "Bluetooth_RN41.h"

#define RX  12
#define TX  11

// Motor A
#define ENA  10
#define IN1  9
#define IN2  8

// Motor B
#define ENB  5  
#define IN3  7
#define IN4  6


Robot robot(ENA, IN1, IN2, ENB, IN3, IN4);
Bluetooth_RN41 bluetooth(RX, TX);

bool master = false;

void setup(){
  delay(1000);
  robot.begin();
  bluetooth.begin(master);
  bluetooth.viewSettings();
}

void loop(){
  bluetooth.receive();
  bluetooth.parseCommand();
  int x = bluetooth.getX();
  int y = bluetooth.getY();
  Serial.println(x);
  Serial.println(y);
  robot.driveCar(x,y);
}
