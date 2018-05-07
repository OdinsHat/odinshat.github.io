---
title: Creating a Breathalyzer with an Arduino and MQ-3 Gas Sensor
date: 2018-02-18 18:32:28
tags: mq sensors, digital, analog, arduino, nano 
---

I got this idea after seeing all the available MQ-sensors at BangGood.com which each promised to detect a different gas.

## Some Sensors Avilable

* MQ-2 - Smoke Gas and LPG/Butane
* MQ-3 - Alcohol/Ethanol. As [mentioned in the datashseet](https://www.sparkfun.com/datasheets/Sensors/MQ-3.pdf) to properlky calibrate these sensors you would need to be able to properly isolate the sensor in an area with an exact level of the gas you wish to sense for.So for alcohol have th sensor isolated in 0.4mg/l to gain a baseline. Fo rthis experiment the calibration was more ad-hoc.
* MQ-6 - Made for domestic detection of Liquefied Petroleum Gas (LPG) or Liquefied Natural Gas (LNG).
* MQ-7 - Carbon Monoxide detector (the one I thought could be used most usefully).
* MQ-8 - Specifically designed to detect hydrogen leaks in the area of the sesor.
* MQ-9 - Fo rtestiung for the presence of Carbon Monoxide (CO) and I had the idea later of trying to create an example carbon monoxide detector.
* MQ-135 - This is a multi-purpose gas sensor capable of detecting gases including CO<sub>2</sub>, Alcohol, Benzene, Nitrogen Oxide, Ammonia (NH3), etc. You should be mindful of the attached callibration pot on the snsor and [the datasheet](https://www.olimex.com/Products/Components/Sensors/SNS-MQ135/resources/SNS-MQ135.pdf) when deciding what to calibrate for specifically.

## Caveat and Warning
Though obviously none of the detectors I or any othe rmaker may build using these sensors has likely passed the stringent safety checked required to go to market they make for interested testing and calibrating of the sensor with your Arduino setup.

## Setup
The setup was pretty simple and my fiurst decision was to use an Arduino Nano over the Uno as I didn't need anywhere near the pins required of a full board.

See the Fritzig image below to see the wire up. You may notice a difference in the coloutr of the sires betwen mine and the diagram. Thats because I changed my mind during the diagram.

**NOTE: Not all MQ sensors come with the same PCB breakout board pinouts. Be sure to double check the pins before hookup**

## Circuit Diagram

{% asset_img circuit-design_bb.png [Circuit design using Fritzing Breadboard Mode] %}

Here's a link to the Fritzing file: {% asset_path circuit-design.fzz %}

## Wiring Instructions

On the MQ-3 breakout board the pins are as follows (as it faces you):

1. Vcc (+5V)
2. Ground (GND)
3. D0 (Digital)
4. A0 (Analog)

Each connects into corresponding pins into the Arduino Nano. If the diagram isn't clear then:

* MQ-3 Pin 1 -> 5V Pin on Arduino
* MQ-3 Pin 2 -> GND on Arduino
* MQ-3 Pin 3 -> Digital 8 pin on Arduino
* MQ-4 Pin 4 -> Analog 0 pin on Arduino

The LED lights up when ethanol/acohol is detected in the air. At base vcalibration this stayed unlit until I placed Bonjela and Alcohol hand wash near the sensor at which point the LED lights up.

Watching the serial monitor als shows the Analog reading coming from D8 increases at the presence of the alcohol sources. The biuggest imcrease was seen by being placed near Bonjela. Contrary to my original hypothesis.

Starting analog readouts are around 1-200. When alcohol is introduced this increases to around 7-800.

## Arduino Source
The source was written usining PlatformIO whose source is saved in *.cpp files. They have a single header at the top 

{% asset_path breath.cpp %}

## All Photos Of Project As Finished

See the photos with the semi-completed projct in this Google Album Link: [https://photos.app.goo.gl/P5TVb6YLoEUU3sFk1](https://photos.app.goo.gl/P5TVb6YLoEUU3sFk1)

Or check out thesre one or two to see how they turn out:

{% asset_img IMG_20180218_010456_896.jpg [The finished product]%}

{% asset_img IMG_20180218_095526.jpg [The MQ-3 Sensor Alone] %}