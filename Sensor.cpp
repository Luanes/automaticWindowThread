#include "Sensor.h"

#include <iostream>

#define	LED   17
#define RAIN  23
#define DHTPIN 24
#define LDR   25

#define MAXTIMINGS 85

int dht11_dat[5] = { 0, 0, 0, 0, 0 };

Sensor::Sensor(){
	wiringPiSetupGpio();
 	pinMode (LED, OUTPUT);
	pinMode (RAIN, INPUT);
	// não é preciso iniciar o DHT11 aqui, pois é inicializado toda vez que chamar getTemperature();
	pinMode (LDR, INPUT);
}

Sensor::~Sensor() {}

void Sensor::openWindow(){
  digitalWrite (LED, HIGH);
  delay (500);
}

void Sensor::closeWindow(){
  digitalWrite (LED, LOW);
  delay (500);
}

bool Sensor::isWindowOpen(){
  if(digitalRead(LED))
	return true;
  return false;
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