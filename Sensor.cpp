#include "Sensor.h"

#define	LED 17

Sensor::Sensor(){
	wiringPiSetupGpio () ;
 	pinMode (LED, OUTPUT) ;
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



 

