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

  for (int x=50; x<250; x++)
  {
    printf ("x = %d\n", x) ;
    digitalWrite (SVM, x);
    delay (10);
  }
  return 0 ;
}