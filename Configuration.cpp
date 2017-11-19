#include "Configuration.h"
#include <iostream>

Configuration::Configuration(){
	tempMax = 200;
	tempMin = -1;
	getConfiguration();
}

void Configuration::getConfiguration(){
	std::string teste;
	teste = connect.retrieve();

	std::string minimumTemperature;
 	minimumTemperature.push_back(teste.at(41));
	minimumTemperature.push_back(teste.at(42));

	std::cout << "Minimum Temperature: " << minimumTemperature << std::endl;
	
	std::string maximumTemperature;
	maximumTemperature.push_back(teste.at(65));
	maximumTemperature.push_back(teste.at(66));

	std::cout << "Maximum Temperature: " << maximumTemperature << std::endl;

	std::string autoDay;
	autoDay.push_back(teste.at(82));
	autoDay.push_back(teste.at(83));
	autoDay.push_back(teste.at(84));
	autoDay.push_back(teste.at(85));
	autoDay.push_back(teste.at(86));

	std::cout << "Automatic at Day: " << autoDay << std::endl;

	std::string autoNight;
	autoNight.push_back(teste.at(104));
	autoNight.push_back(teste.at(105));
	autoNight.push_back(teste.at(106));
	autoNight.push_back(teste.at(107));
	autoNight.push_back(teste.at(108));

	std::cout << "Automatic at Night: " << autoNight << std::endl;
        
	std::string::size_type sz;

	int tempMine = std:: stoi(minimumTemperature, &sz);
	setMinTemp(tempMine);

	int tempMaxa = std:: stoi(maximumTemperature, &sz);
	setMaxTemp(tempMaxa);

	bool automaticD;
	if(autoDay == "false"){
	automaticD = false;
	} else {
	automaticD = true;
	}
	setAutomaticDay(automaticD);

	bool automaticN;
	if(autoNight == "false"){
	automaticN = false;
	} else {
	automaticN = true;
	}
	setAutomaticNight(automaticN);
}

Configuration::~Configuration() {}

int Configuration::getMaxTemp(){
	return tempMax;
}

void Configuration::setMaxTemp(int temp){
	if (temp > tempMin)
		tempMax = temp;
	else //(temp <= tempMin)
		std::cout << "Invalid value to Maximum Temperature! New temperature is lower or equal than minimum temperature" << std::endl;
}

int Configuration::getMinTemp(){
	return tempMin;
}

void Configuration::setMinTemp(int temp){
	if (temp < tempMax)
		tempMin = temp;
	else //(temp >= tempMin)
		std::cout << "Invalid value to Minimum Temperature! New temperature is greater or equal than maximun temperature" << std::endl;
		
}

bool Configuration::isAutomaticDay(){
	return isAutDay;
}

void Configuration::setAutomaticDay(bool aut){
	isAutDay = aut;
}

bool Configuration::isAutomaticNight(){
	return isAutNight;
}
void Configuration::setAutomaticNight(bool aut){
	isAutNight = aut;
}