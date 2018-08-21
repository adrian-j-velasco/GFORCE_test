#include "SevenSegDisp.h"

SevenSegDisp::SevenSegDisp(int aPin, int bPin, int cPin, int dPin, int ePin,
	int fPin, int gPin, int GND1, int GND2, int GND3, int GND4, int dPnt)
{
	//	There has to be a better way...
	__Pins[0] = aPin;	__Pins[1] = bPin;	__Pins[2] = cPin;	__Pins[3] = dPin;
	__Pins[4] = ePin;	__Pins[5] = fPin;	__Pins[6] = gPin;	__Pins[7] = GND1;
	__Pins[8] = GND2;	__Pins[9] = GND3;	__Pins[10] = GND4;	__Pins[11] = dPnt;
}

SevenSegDisp & SevenSegDisp::Display(int num)
{
	__Digit[0] = num / 1000;
	__Digit[1] = (num - (__Digit[0] * 1000)) / 100;
	__Digit[2] = (num - (__Digit[0] *1000 + __Digit[1] *100)) / 10;
	__Digit[3] = num % 10;

	// turn off all display digits
	digitalWrite(__Pins[7], HIGH);
	digitalWrite(__Pins[8], HIGH);
	digitalWrite(__Pins[9], HIGH);
	digitalWrite(__Pins[10], HIGH);

	digitalWrite(__Pins[10], LOW);    
	pickNumber(__Digit[3]);
	delay(__Dtime);
	digitalWrite(__Pins[10], HIGH);

	digitalWrite(__Pins[9], LOW);
	pickNumber(__Digit[2]);
	delay(__Dtime);
	digitalWrite(__Pins[9], HIGH);

	digitalWrite(__Pins[8], LOW);   
	pickNumber(__Digit[1]);
	delay(__Dtime);
	digitalWrite(__Pins[8], HIGH);

	digitalWrite(__Pins[7], LOW);
	pickNumber(__Digit[0]);
	delay(__Dtime);
	digitalWrite(__Pins[7], HIGH);

	return *this;
}

SevenSegDisp & SevenSegDisp::Set_dtime(int dtime)
{
	__Dtime = dtime;
	return *this;
}

void SevenSegDisp::begin_()
{
	for (int i = 0; i < (sizeof(__Pins) / sizeof(*__Pins)); i++)
	{
		pinMode(__Pins[i], OUTPUT);
	}
}

void SevenSegDisp::pickNumber(int num)
{
	switch (num)
	{
	case 1: one(); break;
	case 2: two(); break;
	case 3: three(); break;
	case 4: four(); break;
	case 5: five(); break;
	case 6: six(); break;
	case 7: seven(); break;
	case 8: eight(); break;
	case 9: nine(); break;
	default: zero(); break;
	}
}

void SevenSegDisp::one()
{
	digitalWrite(__Pins[0], LOW);
	digitalWrite(__Pins[1], HIGH);
	digitalWrite(__Pins[2], HIGH);
	digitalWrite(__Pins[3], LOW);
	digitalWrite(__Pins[4], LOW);
	digitalWrite(__Pins[5], LOW);
	digitalWrite(__Pins[6], LOW);
}

void SevenSegDisp::two()
{
	digitalWrite(__Pins[0], HIGH);
	digitalWrite(__Pins[1], HIGH);
	digitalWrite(__Pins[2], LOW);
	digitalWrite(__Pins[3], HIGH);
	digitalWrite(__Pins[4], HIGH);
	digitalWrite(__Pins[5], LOW);
	digitalWrite(__Pins[6], HIGH);
}

void SevenSegDisp::three()
{
	digitalWrite(__Pins[0], HIGH);
	digitalWrite(__Pins[1], HIGH);
	digitalWrite(__Pins[2], HIGH);
	digitalWrite(__Pins[3], HIGH);
	digitalWrite(__Pins[4], LOW);
	digitalWrite(__Pins[5], LOW);
	digitalWrite(__Pins[6], HIGH);
}

void SevenSegDisp::four()
{
	digitalWrite(__Pins[0], LOW);
	digitalWrite(__Pins[1], HIGH);
	digitalWrite(__Pins[2], HIGH);
	digitalWrite(__Pins[3], LOW);
	digitalWrite(__Pins[4], LOW);
	digitalWrite(__Pins[5], HIGH);
	digitalWrite(__Pins[6], HIGH);
}

void SevenSegDisp::five()
{
	digitalWrite(__Pins[0], HIGH);
	digitalWrite(__Pins[1], LOW);
	digitalWrite(__Pins[2], HIGH);
	digitalWrite(__Pins[3], HIGH);
	digitalWrite(__Pins[4], LOW);
	digitalWrite(__Pins[5], HIGH);
	digitalWrite(__Pins[6], HIGH);
}

void SevenSegDisp::six()
{
	digitalWrite(__Pins[0], HIGH);
	digitalWrite(__Pins[1], LOW);
	digitalWrite(__Pins[2], HIGH);
	digitalWrite(__Pins[3], HIGH);
	digitalWrite(__Pins[4], HIGH);
	digitalWrite(__Pins[5], HIGH);
	digitalWrite(__Pins[6], HIGH);
}

void SevenSegDisp::seven()
{
	digitalWrite(__Pins[0], HIGH);
	digitalWrite(__Pins[1], HIGH);
	digitalWrite(__Pins[2], HIGH);
	digitalWrite(__Pins[3], LOW);
	digitalWrite(__Pins[4], LOW);
	digitalWrite(__Pins[5], LOW);
	digitalWrite(__Pins[6], LOW);
}

void SevenSegDisp::eight()
{
	digitalWrite(__Pins[0], HIGH);
	digitalWrite(__Pins[1], HIGH);
	digitalWrite(__Pins[2], HIGH);
	digitalWrite(__Pins[3], HIGH);
	digitalWrite(__Pins[4], HIGH);
	digitalWrite(__Pins[5], HIGH);
	digitalWrite(__Pins[6], HIGH);
}

void SevenSegDisp::nine()
{
	digitalWrite(__Pins[0], HIGH);
	digitalWrite(__Pins[1], HIGH);
	digitalWrite(__Pins[2], HIGH);
	digitalWrite(__Pins[3], HIGH);
	digitalWrite(__Pins[4], LOW);
	digitalWrite(__Pins[5], HIGH);
	digitalWrite(__Pins[6], HIGH);
}

void SevenSegDisp::zero()
{
	digitalWrite(__Pins[0], HIGH);
	digitalWrite(__Pins[1], LOW);
	digitalWrite(__Pins[2], HIGH);
	digitalWrite(__Pins[3], HIGH);
	digitalWrite(__Pins[4], HIGH);
	digitalWrite(__Pins[5], HIGH);
	digitalWrite(__Pins[6], LOW);
}

void SevenSegDisp::dPoint()
{
	digitalWrite(__Pins[11], HIGH);
}
