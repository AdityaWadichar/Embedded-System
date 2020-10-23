#include<reg51.h>

void delay(int t)
{
	while(t>0)
	{
		t--;
	}
}

void main()
{
	int i;
	unsigned char *string = "Aditya";
	int l = sizeof(string)/sizeof(string[0]);
	P1_3 = 0;
	P1 = 0x38;
	P0_2 = 1;
	delay(50);
	P0_2 = 0;
	P1 = 0b00000110;
	P0_2 = 1;
	delay(50);
	P0_2 = 0;
	P1 = 0b00001100;
	P0_2 = 1;
	delay(50);
	P0_2 = 0;

	P0_3 = 1;

	
	for (i=0; i<=l; i++)
	{
		P2 = string[i];
		P0_2 = 1;
		delay(50);
		P0_2 = 0;
	}
}


