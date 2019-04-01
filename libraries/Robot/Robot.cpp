#include "Arduino.h"
#include "Robot.h"

Robot::Robot(int enA, int in1, int in2, int enB, int in3, int in4){
  _enA = enA;
  _in1 = in1;
  _in2 = in2;
  _enB = enB;
  _in3 = in3;
  _in4 = in4;

  // All pins should be setup as outputs:
  pinMode(_enA, OUTPUT);
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
  pinMode(_enB, OUTPUT);
  pinMode(_in3, OUTPUT);
  pinMode(_in4, OUTPUT);
  
  // Initialize all pins as low:
  digitalWrite(_enA, LOW);
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, LOW);
  digitalWrite(_enB, LOW);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, LOW);
}

void Robot::begin(){
  // Setup serial
  Serial.begin(9600);
}

void Robot::driveCar(int pwmA, int pwmB){

  #ifdef DEBUG
    Serial.print("pwmA: ");
    Serial.println(pwmA);
    Serial.print("pwmB: ");
    Serial.println(pwmB);
  #endif

  if(pwmA > 0){
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, LOW);
  }
  if(pwmB > 0){
    digitalWrite(_in3, HIGH);
    digitalWrite(_in4, LOW);
  }
  if(pwmA > 255){
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, LOW);
    pwmA = 255;
  }
  if(pwmB > 255){
    digitalWrite(_in3, HIGH);
    digitalWrite(_in4, LOW);
    pwmB = 255;
  }
  if(pwmA < 0){
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, HIGH);
    pwmA *= -1;
  }
  if(pwmB < 0){
    digitalWrite(_in3, LOW);
    digitalWrite(_in4, HIGH);
    pwmB *= -1;
  }
  analogWrite(_enA, pwmA);
  analogWrite(_enB, pwmB);
}



void Robot::drive(int pwmA, int pwmB){

  if(pwmA < 0){
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, LOW);
    pwmA *= -1;
  }
  if(pwmB < 0){
    digitalWrite(_in3, HIGH);
    digitalWrite(_in4, LOW);
    pwmB *= -1;
  }
  if(pwmA > 0){
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, HIGH);
  }
  if(pwmB > 0){
    digitalWrite(_in3, LOW);
    digitalWrite(_in4, HIGH);
  }

  analogWrite(_enA, pwmA);
  analogWrite(_enB, pwmB);
}