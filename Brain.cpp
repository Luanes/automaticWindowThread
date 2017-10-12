#include <iostream>

#include "Brain.h"

Brain::Brain(){}

Brain::~Brain() {}

void Brain::test(){

	/* Set led on and off five times. 
	And check if window is closed*/
	for (int x=0; x<5; x++){
	  sensor.openWindow();
	  sensor.closeWindow();
	}
	
	if (sensor.isWindowOpen())
	  std::cout << "Open Window!" << std::endl;
	else
	  std::cout << "Close Window!" << std::endl;	

	for (int x=0; x<5; x++){
	if (sensor.isRaining())
	  std::cout << "Raining!" << std::endl;
	else
	  std::cout << "Not Raining!" << std::endl;	}
}