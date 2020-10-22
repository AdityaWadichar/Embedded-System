#include<reg51.h>
void main()
{
	while(1)
	{
		P0=0b11110111; //checking first row
		if (P0_6==0) // 1 is pressed
		{
			P1=0b11111110;
			break;
		}
		else if (P0_5==0) // 2 is pressed
		{
			P1=0b11111101;
			break;
		}
		else if (P0_4==0) // 3 is pressed
		{
			P1=0b11111100;
			break;
		}

		P0=0b11111011; // checking second row
		if (P0_6==0)  // 4 is pressed
		{
			P1=0b11111011;
			break;
		}
		else if (P0_5==0) // 5 is pressed
		{
			P1=0b11111010;
			break;
		}
		else if (P0_4==0) // 6 is pressed
		{
			P1=0b11111001;
			break;
		}
		P0=0b11111101; // checking third row
		if (P0_6==0) // 7 is pressed
		{
			P1=0b11111000;
			break;
		}
		else if (P0_5==0) // 8 is pressed
		{
			P1=0b11110111;
			break;
		}
		else if (P0_4==0) // 9 is pressed
		{
			P1=0b11110110;
			break;
		}
		P0=0b11111110; // checking last row
		if (P0_5==0) // 0 is pressed
		{
			P1=0b11111111;
			break;
		}
		P1=0b00000000; // if nothing is pressed, all leds will glow
	}
}
