#include <stdio.h>
#include <wiringPi.h>

// To compile: gcc -o servoMotor servoMotor.c -l wiringPi
// Important!!! To execute: sudo ./servoMotor


#define	SVM 18

int main (void)
{
  wiringPiSetupGpio () ;
  pinMode (SVM, PWM_OUTPUT);
  pwmSetMode(PWM_MODE_MS);
  pwmSetClock(192);
  pwmSetRange(2000);
  

    for (int x = 0; x<=180; x++){
      printf("%d\n", x);
      pwmWrite (SVM, x);
      delay (2000);
    }
  
  return 0 ;
}