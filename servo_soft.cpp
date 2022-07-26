extern "C"{
    #include<wiringPi.h>
    #include<softServo.h>
}

int main()
{
    int pin = 8;
    if(wiringPiSetupGpio()==-1) return 1;
    softServoSetup( pin, -1, -1, -1, -1, -1, -1, -1);
    for(int i=-250; i<1250;i+=100)
    {
        // 750 mu(micro) s ~ 2250 musでパルス幅変更
        // softServoWrite 1.2ms->1200mus-1000mus=200  
        softServoWrite(pin, i);
        delay(1000);
    }
    return 0;
}

