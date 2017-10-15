/*
TO compile:  gcc rainSensor.c -l wiringPi

*/

#include <stdio.h>
#include <wiringPi.h>
#include <math.h>

#define		RAIN    23

void Print(int x)
{
	switch(x)
	{
		case 1:
			printf("\n***************\n"  );
			printf(  "* Not Raining *\n"  );
			printf(  "***************\n\n");
		break;
		case 0:
			printf("\n*************\n"  );
			printf(  "* Raining!! *\n"  );
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

	pinMode(RAIN, INPUT);

	status = 0;
	while(1) // loop forever
	{
		
		tmp = digitalRead(RAIN);

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