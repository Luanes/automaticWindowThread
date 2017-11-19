#include "Sensor.h"

#include <iostream>

//#define	LED   17

#define	SVM 18
#define RAIN  23
#define DHTPIN 24
#define LDR   25
#define switchOPEN   27
#define switchCLOSE   22

#define MAXTIMINGS 85

int dht11_dat[5] = { 0, 0, 0, 0, 0 };

Sensor::Sensor(){
	wiringPiSetupGpio();
 	//pinMode (LED, OUTPUT);
        pinMode (SVM, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(192);
	pwmSetRange(2000);
	pinMode (RAIN, INPUT);
	// não é preciso iniciar o DHT11 aqui, pois é inicializado toda vez que chamar getTemperature();
	pinMode (LDR, INPUT);
	pinMode (switchOPEN, OUTPUT);
	digitalWrite( switchOPEN, HIGH );
	pinMode (switchCLOSE, OUTPUT);
	digitalWrite( switchCLOSE, HIGH );
}

Sensor::~Sensor() {}

void Sensor::openWindow(){
  
  // WHen used a LED to represent the window
  //digitalWrite (LED, HIGH);
  
  // horario: 1-150
  pwmWrite (SVM, 120);
  while(!isWindowOpen()){
    delay (400);
  }
  pwmWrite (SVM, 0); // stop servo motor
}

void Sensor::closeWindow(){

  // WHen used a LED to represent the window
  // digitalWrite (LED, LOW);
  
  // anti-horario: 158 - 180
  pwmWrite (SVM, 165);
  while(!isWindowClose()){
    delay (400);
  }
  pwmWrite (SVM, 0); // stop servo motor
}

bool Sensor::isWindowOpen(){
  if(digitalRead(switchOPEN))
	return true;
  return false; // close or closing or opening
}

bool Sensor::isWindowClose(){
  if(digitalRead(switchCLOSE))
	return true;
  return false; // open or closing or opening
}

bool Sensor::isRaining(){
  if(digitalRead(RAIN))
	return false;
  return true;
}


int Sensor::getTemperature(){
	int count = 0;
	int temp = -1;
	while ( count < 50)
	{
		temp = aux_getTemperature();
		if (temp >=0 && temp <=50){
			return temp;
		}
		delay( 1000 ); 
		count++;
	}
 
	return -1;
}

int Sensor::aux_getTemperature(){
	uint8_t laststate	= HIGH;
	uint8_t counter		= 0;
	uint8_t j		= 0, i;
	float	f; 
 
	dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;
 
	pinMode( DHTPIN, OUTPUT );
	digitalWrite( DHTPIN, LOW );
	delay( 18 );
	digitalWrite( DHTPIN, HIGH );
	delayMicroseconds( 40 );
	pinMode( DHTPIN, INPUT );
 
	for ( i = 0; i < MAXTIMINGS; i++ )
	{
		counter = 0;
		while ( digitalRead( DHTPIN ) == laststate )
		{
			counter++;
			delayMicroseconds( 1 );
			if ( counter == 255 )
			{
				break;
			}
		}
		laststate = digitalRead( DHTPIN );
 
		if ( counter == 255 )
			break;
 
		if ( (i >= 4) && (i % 2 == 0) )
		{
			dht11_dat[j / 8] <<= 1;
			if ( counter > 16 )
				dht11_dat[j / 8] |= 1;
			j++;
		}
	}
 
	if ( (j >= 40) &&
	     (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3])) ) )
	{
		return dht11_dat[2];
	}else  {
		return -1;
	}
}

bool Sensor::isDay(){
  if(digitalRead(LDR))
	return true;
  return false;
}