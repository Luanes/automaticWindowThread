#include <iostream>

#include "Brain.h"

Brain::Brain(){}

Brain::~Brain() {}

void Brain::setConfiguration(int tempMax, int tempMin, bool autDay, bool autNight, bool openW){

	config.setMaxTemp(tempMax);
	config.setMinTemp(tempMin);
	config.setAutomaticDay(autDay);
	config.setAutomaticNight(autNight);

	if (openW){
	   sensor.openWindow();
	} else {
	   sensor.closeWindow();
	}
}

void Brain::check(){

	update();
	act();
}

void Brain::update(){

	rain = sensor.isRaining();
	day = sensor.isDay();
	temperatureNow = sensor.getTemperature();
	automaticOn = isAutomatic();

	if (rain)
		std::cout << "Está Chuvendo!!" << std::endl;
	else
		std::cout << "Não está Chuvendo!!" << std::endl;
	if (day)
		std::cout << "Está Dia!!" << std::endl;
	else
		std::cout << "Está Noite!!" << std::endl;

	std::cout << " Temperatura: " << temperatureNow << std::endl;
	
}

void Brain::act(){

	if(automaticOn){
		if(sensor.isWindowOpen()){ 	//Window is open?
			if((rain) || (config.getMinTemp() > temperatureNow)){
			   sensor.closeWindow();
			   std::cout << "Close the window!" << std::endl;
			} else {
			    std::cout << "Keep Open!" << std::endl;
			}
			
		}else{				//Window is closed.
			if(config.getMaxTemp() < temperatureNow && !rain){
			sensor.openWindow();
			std::cout << "Open the window!" << std::endl;
			} else {
			    std::cout << "Keep Closed!" << std::endl;
			}
		}
	}
	else{
	   std::cout << "Está manual!!" << std::endl;
	}
}

bool Brain::isAutomatic(){

	if(day){		//is it day?
		if(config.isAutomaticDay()){// Automatic on day is on?
			return true;//It's on automatic mode
			}
			return false;//It's on manual mode
	}else{			//it's night.
		if(config.isAutomaticNight()){//Automatic on night is on?
			return true;//It's on automatic mode
			}
			return false;//It's on manual mode
	}

}
