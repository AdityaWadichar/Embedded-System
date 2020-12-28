#include<reg51.h>
void main()
{
	unsigned int i=0;
	char name[]= "Aditya";   // character
	TMOD = 0x20;             // Timer 1 in mode 2
	TH1 = 0xFD;              // count for 3
	SCON = 0x40;			// transmission in mode 1
	TR1 = 1;				// start timer 1
	


	for (i=0; i<sizeof(name); i++)
	{
		SBUF = name[i];			// send character
		while(TI==0);			// wait till transmission of one character is complete
		TI = 0;					// reset the flag
		
	}
}
