#include <iostream>

#include "Brain.h"
#include <thread>

Brain::Brain(){
	std::thread watchRain(checkRain);
}

Brain::~Brain() {}

void Brain::checkRain(){
	
	rain = sensor.isRaining();
	while(true){
	if(rain){
	update();
	act();
		}
	sleep(60000);
	}
	
}

void Brain::setConfiguration(bool openW){

	if (openW){
	   sensor.openWindow();
	} else {
	   sensor.closeWindow();
	}
}

void Brain::check(){

	config.getConfiguration();
	update();
	act();
}

void Brain::update(){

	rain = sensor.isRaining();
	if (rain)
		std::cout << "It's Raining!!" << std::endl;
	else
		std::cout << "It's NOT Raining!!!!" << std::endl;


	day = sensor.isDay();
	if (day)
		std::cout << "It's Day!!" << std::endl;
	else
		std::cout << "It's Night!!" << std::endl;


	std::cout << "Getting Temperature..." << std::endl;
	temperatureNow = sensor.getTemperature();
	std::cout << "Temperature: " << temperatureNow << std::endl;
	
	automaticOn = isAutomatic();
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
			
		}else if(sensor.isWindowClose()){				//Window is closed.
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
