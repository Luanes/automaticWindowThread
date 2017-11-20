/*
Projeto Final - SO2 - UFSC
Karla e Luan
2017.2

Para compilar:
$ g++ -O3 -o janela *.cpp -Wall -std=c++14 *.h -l wiringPi -l curl

Para executar:
$ ./janela

*/

#include "Brain.h"
#include <wiringPi.h>
#include <iostream>
#include <thread>

void checkRainStatus(Brain brain){
	
	int aux = 1;
	while(aux<100){
	if(brain.checkRain()){
	brain.check();
	delay(6000);
	}
	aux++;
	}

}

int main()
{
	Brain brain;
	int count = 1;
	std::thread rainChecker(checkRainStatus, brain);
	rainChecker.detach();
	while (count < 100){
		std::cout << std::endl  << std::endl << "Beggining Iteration..." << count << std::endl;
		brain.check();
		count++;
	}
	return 0; 

}
