/*
TO compile:  gcc button2.c -l wiringPi

*/

#include <stdio.h>
#include <wiringPi.h>

#define		LED   	  17
#define		BUTTON    27

typedef enum {false, true} bool;

bool stateWindow;

void openWindow(){
	stateWindow = true;
}

void closeWindow(){
	stateWindow = false;
}

bool isOpenWindow(){
	return stateWindow;
}

int main()
{
	if(wiringPiSetupGpio() == -1){
		printf("setup wiringPi failed !");
		return 1;
	}

	pinMode( LED, OUTPUT );
	pinMode(BUTTON, INPUT);

	openWindow();

	while(1) // loop forever
	{
		if (!isOpenWindow)
		{
			if(digitalRead(BUTTON)){
				printf("Window is Open Manually! \n");
				digitalWrite (LED, HIGH);
				delay (3000);
			}
			printf("Window is Close Automatically! \n");
			digitalWrite (LED, LOW);
		}
		else 
		{ 
			if(digitalRead(BUTTON) && delay (500) && digitalRead(BUTTON)){
				printf("Window is Close Manually! \n");
				digitalWrite (LED, LOW);
				delay (3000);
			}
			printf("Window is Open Automatically! \n");
			digitalWrite (LED, LOW);
		}
		delay (500);
	}
	digitalWrite (LED, LOW);
	return 0;
}