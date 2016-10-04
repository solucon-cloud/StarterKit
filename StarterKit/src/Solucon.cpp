/*
Solucon.cpp - IoT starter kit library
Copyright (c) 2016 Q-loud GmbH
Author: Frank Radeck, <www.q-loud.de>
Version: Oktober 04, 2016

This library is designed to use IoT starter kit on Solucon platform.
IoT starter kit is an useful wireless module.Using the functions of the
library, you can easily send and receive data to Solucon-platform.
Just have fun!
For the details, please refer to the documentation on www.q.loud.de
*/


#include "Solucon.h"
#include <Arduino.h>
#include <SoftwareSerial.h>



SoftwareSerial Uart1= SoftwareSerial(10, 11); // RX, TX


const uint8_t gpio_PWM[] { 12, 13 }; // Analog out
const uint8_t gpio_Analog[]{ 14, 15 }; // Analog in
const uint8_t gpio_Dout[]{ 6, 7, 8, 9 }; // Digital out
const uint8_t gpio_Din[]{ 2, 3, 4, 5 }; // Digital in	
boolean enaPWM = 0x00;
boolean enaAnalog = 0x00;
boolean enaDout = 0x00;
boolean enaDin = 0x00;

struct GPIO_States
{
	uint8_t dPort2;
	uint8_t dPort3;
	uint8_t dPort4;
	uint8_t dPort5;
	uint16_t aPort14;
	uint16_t aPort15;

};

GPIO_States gpio_States = { 0,0,0,0,0,0 };


/****************************************************************
*FUNCTION NAME:SoluconInit
*FUNCTION     :Uart1 Communication initialization
*INPUT        :none
*OUTPUT       :none
****************************************************************/
void SOLUCON::SoluconInit(void)
{
	// initialize the Uart1 port
	Uart1.begin(9600);

}


/****************************************************************
*FUNCTION NAME:Send2Cloud
*FUNCTION     :Uart1 Communication initialization
*INPUT        :uint8_t port, uint8_t data to send
*OUTPUT       :none
****************************************************************/
void SOLUCON::send2Cloud(uint8_t port, uint8_t tx)
{
	// send data to cloud
	
	uint8_t chksum = ProtocolID + port + tx;
	Uart1.flush();
	byte tx_data[] = { ProtocolID, port, tx, chksum };
	for (int i = 0; i < sizeof(tx_data); i++) {
		Uart1.write(tx_data[i]);
	}

}


/****************************************************************
*FUNCTION NAME:Init
*FUNCTION     :Uart1 Communication initialization
*INPUT        :none
*OUTPUT       :none
****************************************************************/
void SOLUCON::init(void)
{
	SoluconInit();
	registerPwmOut(true);
	registerAnalogIn(true);
	registerDigitalIn(true);
	registerDigitalOut(true);
	send2Cloud(0x13,0xFD);
	pinMode(gpio_PWM[0], OUTPUT);
	pinMode(gpio_PWM[1], OUTPUT);
	pinMode(gpio_Dout[0], OUTPUT);
	pinMode(gpio_Dout[1], OUTPUT);
	pinMode(gpio_Dout[2], OUTPUT);
	pinMode(gpio_Dout[3], OUTPUT);
	pinMode(gpio_Din[0], INPUT);
	pinMode(gpio_Din[1], INPUT);
	pinMode(gpio_Din[2], INPUT);
	pinMode(gpio_Din[3], INPUT);
	pinMode(gpio_Analog[0], INPUT);
	pinMode(gpio_Analog[1], INPUT);
	send2Cloud(gpio_Analog[0], 0x00);
	send2Cloud(gpio_Analog[1], 0x00);
	send2Cloud(gpio_Din[0], 0x00);
	send2Cloud(gpio_Din[1], 0x00);
	send2Cloud(gpio_Din[2], 0x00);
	send2Cloud(gpio_Din[3], 0x00);

}


/****************************************************************
*FUNCTION NAME:registerPwmOut
*FUNCTION     :Cloud to PWM output initialization Pin 12 , 13
*INPUT        :none
*OUTPUT       :none
****************************************************************/
void SOLUCON::registerPwmOut(boolean state)
{
	enaPWM = state;

}


/****************************************************************
*FUNCTION NAME:registerAnalogIn
*FUNCTION     :Analog input to Cloud initialization Pin 14, 15
*INPUT        :none
*OUTPUT       :none
****************************************************************/
void SOLUCON::registerAnalogIn(boolean state)
{
	enaAnalog = state;

}

/****************************************************************
*FUNCTION NAME:registerDigitalIn
*FUNCTION     :Digital port input to Cloud initialization Pin 2, 3, 4, 5
*INPUT        :none
*OUTPUT       :none
****************************************************************/
void SOLUCON::registerDigitalIn(boolean state)
{
	enaDin = state;

}

/****************************************************************
*FUNCTION NAME:registerDigitalOut
*FUNCTION     :Digital port output to Cloud initialization Pin 6, 7, 8, 9
*INPUT        :none
*OUTPUT       :none
****************************************************************/
void SOLUCON::registerDigitalOut(boolean state)
{
	enaDout = state;

}




/****************************************************************
*FUNCTION NAME:ReadData
*FUNCTION     :Read Data from Cloud
*INPUT        :Name callback function(User defined data, value)  
*OUTPUT       :none
****************************************************************/
void SOLUCON::loop(CallBackType callback)
{
	if (enaDin) {
		byte c = digitalRead(gpio_Din[0]);
		if (gpio_States.dPort2 != c) {
			gpio_States.dPort2 = c;
			Solucon.send2Cloud(gpio_Din[0], gpio_States.dPort2);
		}
		delay(1);

		c = digitalRead(gpio_Din[1]);
		if (gpio_States.dPort3 != c) {
			gpio_States.dPort3 = c;
			Solucon.send2Cloud(gpio_Din[1], gpio_States.dPort3);
		}
		delay(1);

		c = digitalRead(gpio_Din[2]);
		if (gpio_States.dPort4 != c) {
			gpio_States.dPort4 = c;
			Solucon.send2Cloud(gpio_Din[2], gpio_States.dPort4);
		}
		delay(1);

		c = digitalRead(gpio_Din[3]);
		if (gpio_States.dPort5 != c) {
			gpio_States.dPort5 = c;
			Solucon.send2Cloud(gpio_Din[3], gpio_States.dPort5);
		}
		delay(1);
	}



	if(enaAnalog){ 

		uint16_t d = digitalRead(gpio_Analog[0]);
		if (gpio_States.aPort14 != d) {
			gpio_States.aPort14 = d;
			Solucon.send2Cloud(gpio_Analog[0], gpio_States.aPort14);
		}
		delay(1);

		d = digitalRead(gpio_Analog[1]);
		if (gpio_States.aPort15 != d) {
			gpio_States.aPort15 = d;
			Solucon.send2Cloud(gpio_Analog[1], gpio_States.aPort15);
		}
		delay(1);
	}


	if (Uart1.available())  
	{   
		// get the new bytes:
		unsigned char inByte[5];
		for (int i = 0; i < 5; i++) {
			if (Uart1.available()) {
				inByte[i] = Uart1.read();
				delay(2);
			}
		}
		uint8_t chksum = inByte[0] + inByte[1] + inByte[2];
		if (chksum == inByte[3]) {
			if (inByte[1] > 0x0A) {
				callback(inByte[1], inByte[2]);
			} else {

				switch (inByte[1])
				{
				case 0x01:

					if (enaPWM) {
						
						analogWrite(gpio_PWM[0], inByte[2]);
					}
					break;

				case 0x02:

					if (enaPWM) {
						
						analogWrite(gpio_PWM[1], inByte[2]);
					}
					break;

				case 0x04:

					if (enaDout) {
						digitalWrite(gpio_Dout[0], (inByte[2] == 0x00) ? LOW : HIGH);
					}
					break;

				case 0x05:

					if (enaDout) {
						digitalWrite(gpio_Dout[1], (inByte[2] == 0x00) ? LOW : HIGH);
					}
					break;
				
				case 0x06:

					if (enaDout) {
						digitalWrite(gpio_Dout[2], (inByte[2] == 0x00) ? LOW : HIGH);
					}
					break;

				case 0x07:

					if (enaDout) {
						digitalWrite(gpio_Dout[3], (inByte[2] == 0x00) ? LOW : HIGH);
					}
					break;
				default:
					//Serial.println("nothing done");
					break;
				}

			}
			
		}
	}

}

