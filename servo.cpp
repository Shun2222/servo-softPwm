#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>


static_cast<int> getPulseWidth(double angle)
{    
    if(angle>1.0) angle = 1.0;
    else if(angle<0.0) angle = 0.0;
      int maxValue = 27;
      int minValue = 8;
      int servoRange = 
    return minValue + angle * (maxValue - minValue);
}

int main()
{
      if (wiringPiSetupGpio() == -1) {
              std::cout << "cannot setup gpio." << std::endl;
                  return 1;
                    }
      int pulseRange = 1920;
      int pin = 8;
      int maxValue = 27;
      int minValue = 8;
      int pulseWidth; 
        pinMode(pin, PWM_OUTPUT);
        softPwmCreate(pin, 0, pulseRange);
        angle = 0.1;
                while (true) {
                        int num;
                            std::cin >> num;

                                if (num == -1) {
                                          break;
                                              }
                                getPulseWidth(angle);
        softPwmWrite(pin, pulseWidth);
        angle += 0.1;
                                      }

                  return 0;
}
