#include "Sensor.h"

#define	LED   17
#define RAIN  23
#define DHT11 24
#define LDR   25

#define MAXTIMINGS 85

Sensor::Sensor(){
	wiringPiSetupGpio();
 	pinMode (LED, OUTPUT);
	pinMode (RAIN, INPUT);
	// não é preciso iniciar o DHT11 aqui, pois é inicializado toda vez que chamar getTemperature();

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

  int dht11_dat[5] = { 0, 0, 0, 0, 0 };

  for (int t = 0; t<50; t++){
    int laststate = 1;
    int counter = 0;
    int j = 0;

    pinMode( DHT11, OUTPUT );
    digitalWrite( DHT11, LOW );
    delay( 18 );
    digitalWrite( DHT11, HIGH );
    delayMicroseconds( 40 );  
    pinMode( DHT11, INPUT );
    
    for ( int i = 0; i < MAXTIMINGS; i++ )
	{
		counter = 0;
		while ( digitalRead( DHT11 ) == laststate )
		{
			counter++;
			delayMicroseconds( 1 );
			if ( counter == 255 )
			{
				break;
			}
		}
		laststate = digitalRead( DHT11 );
 
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
         (dht11_dat[4] == (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) ) )
	return dht11_dat[2];

    delay(50);
  }
  return -1; // ERROR!!
}