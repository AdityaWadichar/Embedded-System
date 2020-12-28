#include<reg51.h>
void delay();
void main()
{
	TMOD = 0x15;   /*TIMER 1 IN MODE 1 AND TIMER 0 
	AS COUNTER IN MODE 1 */
	TH0 = 0x00;
	TL0 = 0x00;
	TR0 = 1;       //START COUNTER
	
	TH1 = 0xD8;
	TL1 = 0xF0;    // TIMER FOR 10 mS
	TR1 = 1;       // START TIMER
	
	while(TF1 != 1)
	{
		
		P1 = 0x00;   // LOW STATE
		P3 = 0x00;   
		delay();
		P1 = 0xFF;   // HIGH STATE
		P3 = 0xFF;
		delay();	
		
	}
}

void delay()
{
	int t = 39;
	while(t>=0)
	{
		t--;
	}
}
