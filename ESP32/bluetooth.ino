#include "BluetoothSerial.h"
BluetoothSerial BT;
char led;

void setup() 
{
  // put your setup code here, to run once:
BT.begin("Aditya's ESP");  // deviece name
pinMode( 2, OUTPUT);       // built in led as output
}

void loop()
{
  // put your main code here, to run repeatedly:
  led = BT.read();    // reading the command sent via bluetooth
  if (led == '1')     // showing output on led
  {
    digitalWrite( 2, HIGH);
  }
  if ( led == '0')
  {
    digitalWrite( 2, LOW);
  }
}
