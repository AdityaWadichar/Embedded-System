#include<reg51.h>

// pattern of led panel to display
unsigned char led[] = { 0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};

void main()
{
	int i;
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
