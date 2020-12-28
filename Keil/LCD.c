#include<reg51.h>
#include<string.h>

void LCD_set(unsigned char set);
void LCD_input(unsigned char *input);
void delay();


sbit rs=P3^1;  // Register select pin
sbit rw=P3^2;  // read/write pin
sbit en=P3^3;  // enable pin

void main()
{
	LCD_set(0x38);  // Setting LCD 2 lines, 5*7 matrix
	LCD_set(0x0E);  // cursor & display on
	LCD_set(0x06);  // increment cursor position
	
	LCD_input("Aditya Wadichar");
	LCD_set(0xC0);
	delay();
	
}

void LCD_set(unsigned char set)
{
	rs = 0;  // command mode
	rw = 0;  // write mode select
	P2 = set;  // command
	en = 1;
	delay();
	en = 0;
	return;
}

void LCD_input(unsigned char *input)
{
	int i;
	int l = strlen(input);
	for (i=0; i<l; i++)   // string to be displayed
	{
		rw = 0;  // write mode
		rs = 1;  // Data mode
		P2 = input[i];  // sending character one by one
		en = 1;
		delay();
		en = 0;
	}
	return;
}

void delay()
{
	int i = 1000;
	while (i>=0)
	{
		i--;
	}
	return;
}
