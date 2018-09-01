/*
   GFORCE_test_02
   Sensor - adxl193 (analog output)
          - button
*/

#include "Button.h"
#include "SevenSegDisp.h"

/*
    Accel Variables
*/
const int adxl_Pin = A1;      //  use analog pin 1 for accelerometer
int adxl_Raw = 0;             //  output sensor from 0V to 5V
int g_Max = 250;              //  range of sensor is -250g to 250g
int g_Min = -250;
int adxl_Max = 1023;          //  analog has range from 0 to 1023
int adxl_Min = 0;
int adxl_Conv, adxl_Adj = 0;  //  2.5V -> 1023/2 -> 0g
int offset[2] = {1, 2};       //  change offsets here, [0] is a multiplier
//  adxl_Adj = offset[0]*adxl_Conv + offset[1]
int max_Val = 0;              //  it will only be a positive number
//  Or the sensor is flipped
int counter = 0;              //  to reset max_val
/*
    Button stuff
*/
Button Button_;
int button_Pin = 0;

/*
    Seven Segment Display Stuff
*/
SevenSegDisp Ssdisp_(8, 6, 10, 12, 13, 7, 9, 5, 4, 3, 2, 11);

/*
    Function Prototypes
*/
void Display_serial();        //  Display max val, adxl_Adj, and adxl_Raw
void Sensor_read();           //  Reads raw data from sensor
void Get_max();               //  Gets highest value from readings
void Adjust_raw();            //  Converts raw values to adjusted values

void setup()
{
  Button_.Set_bpin(button_Pin);
  Ssdisp_.begin_();
  //Serial.begin(9600);
}

void loop()
{
  Button_.Button_press();

  if (Button_.Get_pcounter() % 2 == 0)
  {
    Ssdisp_.Display(max_Val);
    //Display_serial();   //  take out comment for serial output
    counter = 0;
  }
  else
  {
    if(counter == 0)
    {
      max_Val = 0;
    }
    //delay(300);  //  LOL the lazy easy way lol fuck it
    Sensor_read();
    Adjust_raw();
    Get_max();
    //Display_serial();   //  take out comment for serial output
    counter++;
  }
}

/*
    Function Prototypes
*/
void Display_serial()         //  Display max val, adxl_Adj, and adxl_Raw
{
  Serial.print("max_Val="); Serial.print(max_Val);
  Serial.print(", adxl_Adj="); Serial.print(adxl_Adj);
  Serial.print(", adxl_Raw="); Serial.println(adxl_Raw);
}

void Sensor_read()            //  Reads raw data from sensor
{
  adxl_Raw = analogRead(adxl_Pin);
}

void Get_max()                //  Gets highest value from readings
{
  if ( adxl_Adj > max_Val )
  {
    max_Val = adxl_Adj;
  }
}

void Adjust_raw()             //  Converts raw values to adjusted values
{
  adxl_Conv = map(adxl_Raw, adxl_Min, adxl_Max, g_Min, g_Max);
  adxl_Adj = (offset[0] * adxl_Conv) + offset[1];
}
