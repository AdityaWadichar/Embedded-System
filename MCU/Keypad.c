#include<reg51.h>



void display(unsigned char num)
{
	P0 = ~(num);

}

void main()
{

while(1)
{
	int C1 = P1_6;
	int C2 = P1_5;
	int C3 = P1_4;
	
	int R1 = P1_3;
	int R2 = P1_2;
	int R3 = P1_1;
	int R4 = P1_0;

	 P0 = 0xFF;
	 P2 = 0xFF;
	 P1 = 0xFF;

	 R4 = 0;
	 if( C2 == 0)
		 {display(0);
		  R4=1;}

	 R4=R1=R2=R3=1;
	 R1=0;
	 if (C1 == 0)
		 {display(1);
		  R1=1;}
	 if(C2 == 0)
		 {display(2);
		  R1=1;}
	 if(C3 == 0)
		 {display(3);
		  R1=1;}

	 R4=R1=R2=R3=1;
	 R2 =0;
	 if (C1 == 0)
		 {display(4);
		  R2=1;}
	 if(C2 == 0)
		 {display(5);
		  R2=1;}
	 if(C3 == 0)
		 {display(6);
		  R2=1;}

	 R4=R1=R2=R3=1;
	 R3=0;
	 if (C1 == 0)
		 {display(7);
		  R3=1;}
	 if(C2 == 0)
		 {display(8);
		  R3=1;}
	 if(C3 == 0)
		 {display(9);
		  R3=1;}

}
}
