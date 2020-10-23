#include<reg51.h>

// pattern of led panel to display
unsigned char led[] = { 0b11111110,0b11111101,0b11111011,0b11110111,0b11101111,0b11011111,0b10111111,0b01111111};

int i = 0;
void main()
{

	while(1)  // for continuous blinking of leds
	{
	    for(i = 0; i<8 ;i++) // anticlockwis 
	    {
	       P1 = led[i];
	    }

	    for(i=7 ; i>=0 ;i--) // clockwise
	    {
	       P1 = led[i];
	    }

	            
	}

}
