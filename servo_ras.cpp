#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>
#include <string>

// 動かないサイトからもってきた

using namespace std;

float computePalseWidth(int angle) {
   // Servo can position only 0-180
   angle = angle >   0 ? angle :   0;
   angle = angle < 180 ? angle : 180;
   // Palse-width must be 0.5-2.4[ms]
   return angle / 180.0 * 1.9 + 0.5;
}

int main() {
   const int PWM_OUT = 4; //wPi番号
   const int PALSE_RANGE = 20; //[ms]

   // Init
   wiringPiSetup();
   softPwmCreate(PWM_OUT, 0, 10*PALSE_RANGE);

   cout << "When you finish : end" << endl;
   while (true) {
      float palseWidth;

      try {
         string angle;
         cout << "(0 ~ 180) -> ";
         cin >> angle;
         if (angle == "end") break;

         palseWidth = computePalseWidth( stoi(angle) );

      } catch (...) { /* Skip */ continue; }

      softPwmWrite(PWM_OUT, 10*palseWidth);
      delay(500);
   }

   // Finalize
   // Do nothing
}
