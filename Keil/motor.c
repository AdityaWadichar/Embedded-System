#include<reg51.h>

sbit zero = P3^0;
sbit one = P3^1;

void main()
{
	int i;
	// Data for seven segment display
	unsigned char disp[] = {0xC0, 0xF9, 0xA4, 0x99, 0xB0, 0x92, 0x82, 0xF8, 0x80, 0x90};
	TMOD = 0x50;  // counter in mode 1
	TR1 = 1;      // Start counter
	
	zero = 0;
	one = 1;  // forward motion of motor
	
	while(1)
	{
		i = TL1;
		if (i==10)
		{
			TL1 = 0x00; // reset to zero if count exceeds 9
		}
		P1 = disp[i];
	}
}
