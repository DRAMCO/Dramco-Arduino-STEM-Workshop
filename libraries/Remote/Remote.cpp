#include "Arduino.h"
#include "Remote.h"

Remote::Remote(){}

void Remote::begin(){
  // Setup serial
  Serial.begin(9600);

}

void Remote::readDirections(){
  int x = analogRead(AX);
  int y = analogRead(AY);

  // Change x and y axis values to left and right pwm values
  #ifdef DEBUG
    Serial.print("x: ");
    Serial.println(x);
    Serial.print("y: ");
    Serial.println(y);
  #endif

  int xdir = (x/2)-255;       //scaling from 0-1024 to -256-256
  int ydir = (y/2)-255;
  _pwma = ydir-xdir;
  _pwmb = ydir+xdir;
}


int Remote::getPWMA(){
  return _pwma;
}

int Remote::getPWMB(){
  return _pwmb;
}