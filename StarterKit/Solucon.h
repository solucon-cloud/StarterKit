/*
Solucon.h - IoT starter kit library
Copyright (c) 2016 Q-loud GmbH
Author: Frank Radeck, <www.q-loud.de>
Version: Oktober 04, 2016

This library is designed to use IoT starter kit on Solucon platform.
IoT starter kit is an useful wireless module.Using the functions of the
library, you can easily send and receive data to Solucon-platform.
Just have fun!
For the details, please refer to the documentation on www.q.loud.de
*/

#ifndef _SOLUCON_h
#define _SOLUCON_h
#include <Arduino.h>



#define ProtocolID 0x42


typedef void(*CallBackType)(uint8_t, uint8_t);


class SOLUCON
{
private:
	void SoluconInit(void);
	
	
	

public:
	void Init(void);
	void send2Cloud(uint8_t, uint8_t);
	void loop(CallBackType callback);
	void registerPwmOut(boolean);
	void registerAnalogIn(boolean);
	void registerDigitalIn(boolean);
	void registerDigitalOut(boolean);
	
};

extern SOLUCON Solucon;



#endif