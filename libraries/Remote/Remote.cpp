#include "Arduino.h"
#include "Remote.h"

Remote::Remote(){}

void Remote::begin(){
  // Setup serial
  Serial.begin(9600);

}

void Remote::readDirections(){
  _ax = analogRead(AX);
  _ay = analogRead(AY);
}


int Remote::getX(){
  return _ax;
}

int Remote::getY(){
  return _ay;
}