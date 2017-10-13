#include <iostream>

#include "Brain.h"

Brain::Brain(){}

Brain::~Brain() {}

void Brain::test(){
	for (int x=0; x<5; x++){
	  sensor.openWindow();
	  sensor.closeWindow();

	
	  if (sensor.isWindowOpen())
	    std::cout << "Open Window!" << std::endl;
	  else
	    std::cout << "Close Window!" << std::endl;	
	
	
	  if (sensor.isRaining())
	    std::cout << "Raining!" << std::endl;
	  else
	    std::cout << "Not Raining!" << std::endl;
	  
	  //std::cout << "Temperature = " << sensor.getTemperature() << "C;" << std::endl;
	
	  if (sensor.isDay())
	    std::cout << "It's Day!" << std::endl;
	  else
	    std::cout << "It's Night!" << std::endl;

	}	
}