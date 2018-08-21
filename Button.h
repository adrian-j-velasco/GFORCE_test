#pragma once

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram,h"
#endif

#define HIGH 0x1
#define LOW 0x0

class Button
{
public:
	Button();
	//	GETTERS
	int Get_bpin()const;
	int Get_pcounter()const;
	int* Get_bval()const;							//	returns array of __button_Val

	//	SETTERS
	Button & Set_bpin(int pin);
	Button & Set_pcounter(int count);	
	Button & Set_bval(int pos, int state);			//	Not sure if 1 and 0 works for HIGH and LOW

	//	OTHER FUNCTIONS
	bool Button_press();							//	return true for button press
	bool Compare_val(int pos);						//	return true if equal
	Button & Plus_cnter();							//	increase 1 to __press_Counter
	Button & Reset_bval();							//	resets __button_Va to LOW,HIGH,LOW
private:
	int __button_Pin;								//	digital pin used for the button
	int __press_Counter;							//	Counts # of presses
	int __button_Val[3] = { LOW,HIGH,LOW };			//	it should be LOW, HIGH, LOW. (LOW = 0x0 and HIGH 0x1)
													//	initial values are the opposite of a button read'
	const int __expect_Val[3] = { HIGH,LOW,HIGH };	//	button press is High, LOW, HIGH
};

