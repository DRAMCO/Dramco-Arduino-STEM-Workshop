#ifndef Robot_h
#define Robot_h

#include "Arduino.h"

//#define DEBUG

class Robot{
	public:
		Robot(int enA, int in1, int in2, int enB, int in3, int in4);	// Constructor
		void begin();													// Initialize the robot!
		void driveCar(int pwmA, int pwmB);									// Drive the car with 2 values (0 - 1024) -> inputs from ADC
	private:
		int _enA;
		int _in1;
		int _in2;
		int _enB;
		int _in3;
		int _in4;
};

#endif