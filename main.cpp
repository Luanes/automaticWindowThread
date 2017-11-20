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
	
	while(true){
	if(brain.checkRain()){
	brain.check();
		}
	delay(6000);
	}

}

int main()
{
	Brain brain;
	int count = 1;
	std::thread(brain.checkRainStatus, brain);
	while (count < 100){
		std::cout << std::endl  << std::endl << "Beggining Iteration..." << count << std::endl;
		brain.check();
		count++;
		
		
	}
	return 0; 

}
