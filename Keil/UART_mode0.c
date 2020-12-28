#include<reg51.h>
void main()
{
	unsigned int i=0;
	char name[] = "Aditya";
	SCON = 0x00;   // mode 0
	for (i=0; i<sizeof(name); i++)
	{
		SBUF = name[i];  // sending character
		while(TI==0);    // wait for transmission to complete
		T1 = 0;          // reset the flag after transmission
	}
}
