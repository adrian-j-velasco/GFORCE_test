#pragma once

//	REALLY NEED TO KNOW HOW THIS WORKS LOL
#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//         A
//      ________            D1  A   F   D2  D3  B
//     |        |         -------------------------
//  F  |        |  B     |                        |
//     |   G    |        |                        |
//     |________|        |                        |
//     |        |        |                        |
//     |        |        |    o    o      o    o  |
//   E |        |   C    -------------------------
//     |________|           E   D   o   C   G  D4
//       
//         D       O dPnt

class SevenSegDisp
{
public:
	SevenSegDisp(int aPin, int bPin, int cPin, int dPin, int ePin, 
		int fPin, int gPin, int GND1, int GND2, int GND3, int GND4, int dPnt);
	SevenSegDisp & Set_dtime(int dtime);
	SevenSegDisp & Display(int num);
	void begin_();
	void pickNumber(int num);
	void one();
	void two();
	void three();
	void four();
	void five();
	void six();
	void seven();
	void eight();
	void nine();
	void zero();
	void dPoint();
private:
	int __Pins[12];
	int __Digit[4];
	int __Dtime = 4;	//	default value in milliseconds
};

