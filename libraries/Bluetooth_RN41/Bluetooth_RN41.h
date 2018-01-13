#ifndef Bluetooth_RN41_h
#define Bluetooth_RN41_h

#include "Arduino.h"
#include "SoftwareSerial.h"

//#define DEBUG

class Bluetooth_RN41{
	public:
		Bluetooth_RN41(int rx, int tx):BTSerial(rx, tx){}
		void begin(bool master, String address = "");
		void receive();
		void parseCommand();	//used on the robot to check the received commands
		void sendDirections(int pwmA, int pwmB);
		void viewSettings();		
		int getPWMA();
		int getPWMB();
	private:
		void connect(String address);
		void send(char* i_pBtCmd, bool i_ln = true);
		void receiveNoEnd();
		SoftwareSerial BTSerial;
		int incomingByte = 0;
		char gBtMsg[256];
		int _pwma = 0;
		int _pwmb = 0;
};

#endif