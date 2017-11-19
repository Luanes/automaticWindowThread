/*
TO compile:  gcc -o switch Switch.c -l wiringPi

*/

#include <stdio.h>
#include <wiringPi.h>
#include <math.h>

#define		Switch    27

void Print(int x)
{
	switch(x)
	{
		case 1:
			printf("\n***************\n"  );
			printf(  "* 1 *\n"  );
			printf(  "***************\n\n");
		break;
		case 0:
			printf("\n*************\n"  );
			printf(  "* 0 *\n"  );
			printf(  "*************\n\n");
		break;
		default:
			printf("\n**********************\n"  );
			printf(  "* Print value error. *\n"  );
			printf(  "**********************\n\n");
		break;
	}
}

int main()
{
	int tmp, status;

	if(wiringPiSetupGpio() == -1){
		printf("setup wiringPi failed !");
		return 1;
	}

	pinMode(Switch, OUTPUT);
	digitalWrite( Switch, HIGH );
	//delay( 18 );
	//pinMode(Switch, INPUT);

	status = 5;
	while(1) // loop forever
	{
		
		tmp = digitalRead(Switch);
		printf("tmp = %d\n", tmp);
		if (tmp != status)
		{
			printf("Digital Signal: %d\n", tmp);
			Print(tmp);
			status = tmp;
		}

		delay (200);
	}
	return 0;
}