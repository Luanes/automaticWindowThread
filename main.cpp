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


int main()
{
	Brain brain;
	brain.test();
	return 0; 

}