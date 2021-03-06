#ifndef Remote_h
#define Remote_h

#include "Arduino.h"

#define DEBUG

// Pin definitions for the joystick (ADC)
#define AX 1
#define AY 0

class Remote{
	public:
		Remote();
		void begin();
		void readDirections();
		int getPWMA();
		int getPWMB();
	private: 
		int _pwma;
		int _pwmb;
};

#endif