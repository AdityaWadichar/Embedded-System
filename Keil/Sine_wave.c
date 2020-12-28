#include<reg51.h>
#include<math.h>
void main()
{
	while(1)
	{
		int i;
		double result;
		for (i=0; i<=360; i++)
		{
			result = sin(2*3.1415*i /360);   // points of sin wave
			// the variable result is analysed in logic analyser
		}
	}
}
