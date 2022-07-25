#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>


int getPulseWidth(double angle)
{    
    if(angle>1.0) angle = 1.0;
    else if(angle<0.0) angle = 0.0;
    int maxValue = 27;
    int minValue = 8;
    return minValue + angle * (maxValue - minValue);
}

int main()
{
      if (wiringPiSetupGpio() == -1) {
          std::cout << "cannot setup gpio." << std::endl;
          return 1;
      }
      int pulseRange = 1920;
      int pulseWidth; 
      pinMode(pin, PWM_OUTPUT);
      softPwmCreate(pin, 0, pulseRange);
      double angle = 0.1;
      while (true) {
          std::cin >> angle;
          if (angle == -1) {
              break;
          }
          pulseWidth = getPulseWidth(angle);
          softPwmWrite(pin, pulseWidth);
      }
      return 0;
}
