#!/bin/bash
TOOLCHAIN_TYPE=arm-linux
export TOOLCHAIN_TYPE
PREFIX_GPIO=/home/onion/raspberrypi/libs/pigpio
PREFIX_DRIVERS=/home/onion/micro/raspberrypiZeroDroid/drivers
PREFIX_FRAMEWORK=/home/onion/micro/raspberrypiZeroDroid/framework
export PREFIX_GPIO
export PREFIX_DRIVERS
export PREFIX_FRAMEWORK
#PREFIX_RASPICAM=/home/onion/raspberrypi/libs/raspicam
#export PREFIX_RASPICAM
#PREFIX_VC=/home/onion/raspberrypi/tools/arm-bcm2708/arm-bcm2708-linux-gnueabi/arm-bcm2708-linux-gnueabi/sysroot/opt/vc
#export PREFIX_VC 
PREFIX_WIRINGPI=/home/onion/raspberrypi/libs/wiringpi
export PREFIX_WIRINGPI
PREFIX_SYSTEM=/home/onion/raspberrypi/libs/system
export PREFIX_SYSTEM
