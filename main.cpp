/*
Projeto Final - SO2 - UFSC
Karla e Luan
2017.2

Para compilar:
$ g++ -O3 -o janela *.cpp -Wall -std=c++14 *.h -l wiringPi

Para executar:
$ ./janela

*/
#include <iostream>
#include "Brain.h"


int main()
{
	std::cout << "Olá!" << std::endl;
	Brain brain;
	if (brain.test() == 1)
	  std::cout << "Janela Aberta!" << std::endl;
	else
	  std::cout << "Janela Fechada!" << std::endl;	
	return 0;

}