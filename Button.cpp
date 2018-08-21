#include "Button.h"

Button::Button()
{
	__press_Counter = 0;
}

//	GETTERS
int Button::Get_bpin()const
{
	return __button_Pin;
}

int Button::Get_pcounter()const
{
	return __press_Counter;
}

int* Button::Get_bval()const
{
	static int holder[3];
	for (int i = 0; i < 3; i++)
	{
		holder[i] = __button_Val[i];
	}
	return holder;
}

//	SETTERS
Button & Button::Set_bpin(int pin)
{
	__button_Pin = pin;
	pinMode(pin, INPUT_PULLUP);
	return *this;
}

Button & Button::Set_pcounter(int count)
{
	__press_Counter = count;
	return *this;
}

Button & Button::Set_bval(int pos, int state)
{
	__button_Val[pos] = state;
	return *this;
}

//	OTHER FUNCTIONS
bool Button::Button_press()
{
	bool ret;
	int counter = 0;

	for (int i = 0; i < 3; i++)
	{
		if (Compare_val(i))
		{
			counter++;
		}
	}

	switch (counter)
	{
	case 0: 
		if (__expect_Val[counter] == digitalRead(__button_Pin))
		{
			__button_Val[counter] = __expect_Val[counter];
		}
		ret = false;
		break;

	case 1:
		if (__expect_Val[counter] == digitalRead(__button_Pin))
		{
			__button_Val[counter] = __expect_Val[counter];
		}
		ret = false;	
		break;

	case 2:	
		if (__expect_Val[counter] == digitalRead(__button_Pin))
		{
			__button_Val[counter] = __expect_Val[counter];
		}
		ret =  false;	
		break;

	case 3:
		Plus_cnter().Reset_bval();
		ret =  true;	
		break;
	}
}

bool Button::Compare_val(int pos)
{
	if (__button_Val[pos] == __expect_Val[pos])
	{
		return true;
	}
	else
	{
		return false;
	}
}

Button & Button::Plus_cnter()
{
	++__press_Counter;
	return *this;
}

Button & Button::Reset_bval()
{
	for (int x = 0; x < 3; x++)
	{
		if (x % 2 == 1)
		{
			__button_Val[x] = HIGH;
		}
		else
		{
			__button_Val[x] = LOW;
		}
	}
	return *this;
}
