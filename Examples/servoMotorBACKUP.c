#include <stdio.h>
#include <wiringPi.h>

// To compile: gcc -o servoMotor servoMotor.c -l wiringPi


#define	SVM 18

int main (void)
{
  wiringPiSetupGpio () ;
  pinMode (SVM, PWM_OUTPUT);
  pwmSetMode(PWM_MODE_MS);
  pwmSetClock(192);
  pwmSetRange(2000);

  /*while(true){
    for (int x = 50; x<=250; x++){
      pwmWrite (SVM, x);
      delay (100);
    }
    for (int x = 250; x>=50; x--){
      pwmWrite (SVM, x);
      delay (100);
    }

  }*/
  
  return 0 ;
}