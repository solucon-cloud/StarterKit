# SOLUCON IoT Starter Kit

Version: 1.0

Release Date: 04.10.2016

http://www.q-loud.de

Libray for Q-loud Arduino IoT-shield to communicate with SOLUCON cloud. The IoT Starter Kit is an easy to use add-on board for the fantastic
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
Arduino is an open-source development platform for physical computing. It is intended for hobbyists, designers or anyone interested to build interactive objects. The IoT-Starter Kit consist one Arduino Mega 2060, Q-Loud IoT-shield for Arduino and a Q-loud Gateway. With a few lines of code you are enabled to send and receive data from the SOLUCON cloud to your Arduino board. Go to 
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

* **init()** calling this method to start serial communication between Arduino and Q-loud IoT-shield and enable pin mapping automaticly to SOLUCON cloud. Serial communication between Arduino and IoT-shield is done by Software Serial (Pin 10,11) with 9600 kB/s.
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
* **registerAnalogIn(boolean)**
* **registerDigitalIn(boolean)**
* **registerDigitalOut(boolean)**

 


## Monitor data in SOLUCON Device-Manager
## Getting started with SOLUCON Rest-API

## What comes next

##License
Copyright (c) 2016 Q-loud GmbH
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.
