/*
TO compile:  gcc button.c -l wiringPi

*/

#include <stdio.h>
#include <wiringPi.h>

#define		BUTTON    27

int main()
{
	int tmp;
	int status = 5;

	if(wiringPiSetupGpio() == -1){
		printf("setup wiringPi failed !");
		return 1;
	}
	pinMode( BUTTON, OUTPUT );
	digitalWrite( BUTTON, LOW );
	delay( 18 );
	pinMode(BUTTON, INPUT);

	while(1) // loop forever
	{
		tmp = digitalRead(BUTTON);
		//printf("%d\n", status);
		if (tmp != status)
		{
			if (tmp == 1){
				printf("Window is Open Manually! %d\n", tmp);
				status = tmp;
			}
			else {
				printf("Window is Close Manually! %d\n", tmp);
				status = tmp;
			}
		}

		delay (10);
	}
	return 0;
}