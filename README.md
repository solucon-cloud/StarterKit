# SOLUCON IoT Starter Kit

Version: 1.0

Release Date: 04.10.2016

Frank Radeck, http://www.q-loud.de

Libray for Q-loud Arduino IoT-shield to communicate with SOLUCON platform. The IoT Starter Kit is an easy to use add-on board for the fantastic
Arduino hardware. You can send and receive encryped data and commands securely to the SOLUCON platform, witch is designed especially for Iot-Data.

##Prerequisites
* Arduino board (Arduino UNO, DUE, Leonardo, Mega 2560)
* Q-Loud IoT-shield for Arduino
* Q-Loud Gateway
* Arduino IDE 1.04 and later

## Table of contents

* [Overview](#overview)
* [Information about hardware](#information-about-hardware)
* [Setting up software](#setting-up-software)
* [Getting started with IoT Starter Kit](#getting-started-with-iot-starter-kit)
* [Monitor data in SOLUCON Device-Manager] (#monitor-data-in-solucon-device-manager)
* [Getting started with SOLUCON Rest-API](#getting-started-with-solucon-rest-api)
* [What comes next](#what-comes-next)
* [License](#license)




## Overview
SOLUCON is one of the leading IoT platforms and a powerful ecosystem.

## Information about hardware
### What is the IoT-Starter Kit for SOLUCON platform
Arduino is an open-source development platform for physical computing. It is intended for hobbyists, designers or anyone interested to build interactive objects. The IoT-Starter Kit consist one Arduino Mega 2060, Q-Loud IoT-shield for Arduino and a Q-loud Gateway. 
This shield is a cc430-based device. It is a demonstration tool, intended to convince tech staff of a potential customer that our platform is exactly what they need.

The device has the following inputs (device to cloud):

- 2 rotary knobs (red and blue)
- 1 soft switch (button + led, software-emulated push button switch)
- 20 8-bit registers accessible via UART

The device has the following outputs (cloud to device):

- 3 RGB-LEDs
- 20 8-bit registers accessible via UART
	
Also, there's 2 LEDs to indicate UART RX and TX.

With a few lines of code you are enabled to send and receive data from the SOLUCON cloud to your Arduino board. Digital pins 2, 3, 4, 5 are pre-configured as input and pins 6, 7, 8 ,9 as output ports. There also 2 PWM outputs (Pin 12, 13) and 2 analog inputs (Pin 14, 15) configured by calling the **init()** function. These features can seperatly disabled by software functions. Events and data from the cloud can be catched as user-defined-data in a callback function in the .ino-file.
<br>

## Setting up software
Arduino IDE 1.5.7


Download and install the Arduino IDE version 1.5.7, see instructions <a href="http://arduino.cc/en/Main/software/">here</a>. Versions lower then 1.5.7 will produce errors with some sketches as the compiler is too old.
Start the Arduino IDE once and quit the application again. This will create directory structures needed in the next steps.

Install the SOLUCON IoT Starter Kit library.

**[Installing an Arduino Library Guide](https://learn.sparkfun.com/tutorials/installing-an-arduino-library)** - Basic information on how to install an Arduino library.



## Getting started with IoT Starter Kit
* Download and install one of the mobile apps for Android or IOS.
* Scan the QR-code of the shield and create a SOLUCON-Accout
* Install the Q-Loud IoT-shield to the Arduino board.
* Run the simple sample application.
* Go to https://device-manager.solucon.de to control your device

### Usage:
At the top of your sketch you must include the **Solucon** header file

```C
    #include <Solucon.h>
```

And then at global scope you should instantiate an **SOLUCON** object

```C
    SOLUXON Solucon;
```

* **init()** calling this method to start serial communication between Arduino and Q-loud IoT-shield and enable pin mapping automaticly to SOLUCON cloud. Serial communication between Arduino and IoT-shield is done by Software-Serial (Pin 10,11) at 9600 kB/s.
```C++
    void setup()
    {
        Solucon.init();
    }
```
* **loop(CallBackType callback)** 
To actually process events in the event queue and dispatch them to listeners you
call the `loop()` function. Pass your callback function as parameter.

```C++
    void loop()
    {
        Solucon.loop(&callback);
    }
```
* **registerPwmOut(boolean)**
PWM output is automaticly enabled by calling init(). You can disable PWM output by calling
```C++
    void setup()
    {
        Solucon.registerPwmOut(false);
    }
```
* **registerAnalogIn(boolean)**
Analog input is automaticly enabled by calling init(). You can disable analog input by calling
```C++
    void setup()
    {
        Solucon.registerAnalogIn(false);
    }
```
* **registerDigitalIn(boolean)**
Digital input is automaticly enabled by calling init(). You can disable digital outout by calling
```C++
    void setup()
    {
        Solucon.registerDigitalIn(false);
    }
```
* **registerDigitalOut(boolean)**
Digital output is automaticly enabled by calling init(). You can disable digital output by calling
```C++
    void setup()
    {
        Solucon.registerDigitalOut(false);
    }
```
 


## Monitor data in SOLUCON Device-Manager
Go to https://device-manager.solucon.de and log in to your account. From there you can control your device in a rich GUI implentation.

## Getting started with SOLUCON Rest-API
Look at the SOLUCON API documentation <a href="https://app.cospace.de/doc/index.html">here</a>

## Data Model
### data

| index | capability  | description
|------:|-------------|----------------------------------
|     0 | color_rgb   | left RGB LED
|     1 | color_rgb   | center RGB LED 
|     2 | color_rgb   | right RGB LED 
|     3 | binary_8bit | Arduino (pin 12)  0: PWM (analog OUT) 1
|     4 | binary_8bit | Arduino (pin 13)  1: PWM (analog OUT) 2
|     5 | binary_8bit | Arduino (pin 14)  2: ADC (analog IN) 1
|     6 | binary_8bit | Arduino (pin 15)  3: ADC (analog IN) 2
|     7 | binary_8bit | Arduino (pin 6)  4: digital OUT 1
|     8 | binary_8bit | Arduino (pin 7)  5: digital OUT 2
|     9 | binary_8bit | Arduino (pin 8)  6: digital OUT 3
|    10 | binary_8bit | Arduino (pin 9)  7: digital OUT 4
|    11 | binary_8bit | Arduino (pin 2)  8: digital IN 1
|    12 | binary_8bit | Arduino (pin 3)  9: digital IN 2
|    13 | binary_8bit | Arduino (pin 4) 10: digital IN 3
|    14 | binary_8bit | Arduino (pin 5) 11: digital IN 4
|    15 | binary_8bit | Arduino 12: user defined value 1
|    16 | binary_8bit | Arduino 13: user defined value 2
|    17 | binary_8bit | Arduino 14: user defined value 3
|    18 | binary_8bit | Arduino 15: user defined value 4
|    19 | binary_8bit | Arduino 16: user defined value 5
|    20 | binary_8bit | Arduino 17: user defined value 6
|    21 | binary_8bit | Arduino 18: user defined value 7
|    22 | binary_8bit | Arduino 19: user defined value 8
|    23 | gauge       | red rotary knob
|    24 | gauge       | blue rotary knob
|    25 | onoff       | software-emulated on/off switch


### action

| index | capability  | description
|------:|-------------|----------------------------------
|     0 | color_rgb   | left RGB LED
|     1 | color_rgb   | center RGB LED 
|     2 | color_rgb   | right RGB LED 
|     3 | binary_8bit | Arduino (pin 12) 0: PWM (analog OUT) 1
|     4 | binary_8bit | Arduino (pin 13) 1: PWM (analog OUT) 2
|     5 | binary_8bit | Arduino (pin 14) 2: ADC (analog IN) 1 (IGNORED)
|     6 | binary_8bit | Arduino (pin 15) 3: ADC (analog IN) 2 (IGNORED)
|     7 | binary_8bit | Arduino (pin 6) 4: digital OUT 1
|     8 | binary_8bit | Arduino (pin 7) 5: digital OUT 2
|     9 | binary_8bit | Arduino (pin 8) 6: digital OUT 3
|    10 | binary_8bit | Arduino (pin 9) 7: digital OUT 4
|    11 | binary_8bit | Arduino (pin 2) 8: digital IN 1 (IGNORED)
|    12 | binary_8bit | Arduino (pin 3) 9: digital IN 2 (IGNORED)
|    13 | binary_8bit | Arduino (pin 4) 10: digital IN 3 (IGNORED)
|    14 | binary_8bit | Arduino (pin 5) 11: digital IN 4 (IGNORED)
|    15 | binary_8bit | Arduino 12: user defined value 1
|    16 | binary_8bit | Arduino 13: user defined value 2
|    17 | binary_8bit | Arduino 14: user defined value 3
|    18 | binary_8bit | Arduino 15: user defined value 4
|    19 | binary_8bit | Arduino 16: user defined value 5
|    20 | binary_8bit | Arduino 17: user defined value 6
|    21 | binary_8bit | Arduino 18: user defined value 7
|    22 | binary_8bit | Arduino 19: user defined value 8


## UART communication
We use UART with 9600 bps, 8N1.

### UART Frames

| byte |    0 |    1 |    2 |   3 
|------|------|------|------|------
| name |`P_ID`|`R_ID`|`DATA`|`CKSM`


- `P_ID`: Protocol ID, always 0x42
- `R_ID`: Register index, 0x00 to 0x13 (dec:19)
- `DATA`: Data value for the register stated in `R_ID`
- `CKSM`: checksum. bytes 0, 1 and 2 added (8 bit, discard overflow)


Between frames, a pause of 1 millisecond (approx 1 byte) must be waited.

These frames can either be sent from the shield to the Arduino, or the other way around.

## What comes next
tbd

##License
Copyright (c) 2016 Q-loud GmbH
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.
