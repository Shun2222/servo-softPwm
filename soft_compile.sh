#!/bin/bash
g++ servo_soft.cpp softServo.c softServo.h -lwiringPi -pthread -lrt -lcrypt
