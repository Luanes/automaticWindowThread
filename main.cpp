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

int main()
{
	Brain brain;
	int count = 1;
	//int tempMax, int tempMin, bool autDay, bool autNight, bool openW
	//brain.setConfiguration(false);
	while (count < 100){
		std::cout << std::endl  << std::endl << "Beggining Iteration..." << count << std::endl;
		brain.check();
		count++;
		delay(5000);
		
	}
	return 0; 

}
