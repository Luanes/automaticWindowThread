/*
Projeto Final - SO2 - UFSC
Karla e Luan
2017.2

Para compilar:
$ g++ -O3 -o janela *.cpp -Wall -std=c++14 *.h -l wiringPi

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
	brain.setConfiguration(24, 17, false, true, false);
	while (count < 9){
		std::cout << "Iniciando iteração " << count <<std::endl;
		brain.check();
		count++;
		std::cout << std::endl << "Proxima iteração " << count << std::endl;
		delay(5000);
		
	}
	return 0; 

}
