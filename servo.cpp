#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>


double getPulseWidth(double angle)
{    
    if(angle>1.0) angle = 1.0;
    else if(angle<0.0) angle = 0.0;
    double maxValue = 2.0;
    double minValue = 1.0;
    return minValue + angle * (maxValue - minValue);
}

int main()
{
      if (wiringPiSetupGpio() == -1) {
          std::cout << "cannot setup gpio." << std::endl;
          return 1;
      }
      int pin = 8;
      int pulseRange = 20;
      int pulseWidth; 
      pinMode(pin, PWM_OUTPUT);
      softPwmCreate(pin, 0, pulseRange);
      double angle = 0.1;
      while (true) {
	  std::cout << "angle:" <<std::endl;
          std::cin >> angle;
          if (angle == -1) {
              break;
          }
          pulseWidth = getPulseWidth(angle);
          softPwmWrite(pin, pulseWidth);
      }
      return 0;
}
