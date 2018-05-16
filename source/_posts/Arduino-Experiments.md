title: Arduino Experiments
date: 2018-05-03 12:02:27
tags: 
 - arduino
 - electronics
 - hacking
 - maker
 - esp8266
 - esp32
---

## Introduction

I've recently begun [creating a repo under my account](https://github.com/OdinsHat/arduino-experiments) with a range of related sensor-based experiments. These all have a final goal in mind.

However as I planned to build a multitude of static LCD displaying sensors around the home I came across chips called the ESP8266 and ESP32. They seemed to be cut-down Arduino's with WiFi. The absolute panacea people had been waiting for to develop the perfect IoT devices.

But before I could run with these devices dealing with Wi-Fi conectivity and this acronym I kept hearing (MQTT) which seemed to make ESPXX solution sound more complicted I ewanted to conquer Arduino sensing and displaying first.

So that's what I did and that's what [the repo](https://github.com/OdinsHat/arduino-experiments) is for. To first master the arduino then moive onto the ESP.

At first each room will have an [Arduino](https://www.arduino.cc) showing one or more of the following:

* Temperature (C)
* Relative Humidity
* Light (LDR)
* Microphone (either actual sound or just the sound level in decibels which can be worked out using formulae).
* Barometric pressure (maybe redundant in multiple rooms of a home).
* Carbon Monoxide levels
* Cardon Dioxide levels
* Other gases (check out the sheer number of MQ sensors!)
* Dust levels (courtesy of a rather expensive Sharp Electronics dust sensor).

All of the above will then be put up on a dashboard. So far I'm unsure whether to keep it local and build my own [Flask API](http://flask.pocoo.org) or use one of the many IoT services out there.

## Hang on I thought you said "Arduino", what's this ESP-whatsit?

Great question no one asked but I'm pretending you did! The [ESP8266](https://en.wikipedia.org/wiki/ESP8266) & upgraded [ESP32](https://en.wikipedia.org/wiki/ESP32) are a group of chips developed by a company called [Espressif Systems](https://www.espressif.com) as a low cost Wi-Fi chip with full TCP/IP capability. I describe them to people as *"chopped down Wi-Fi Arduinos the size of a chunky nano version"*.

So it has digital inputs, runs at 3.3v (which can be a bugger as most sensors can be 5v). It has WiFi obviously and a number of inputs and outputs including CLK digital 1 analog GPIO pins and others depending on the specific brand. Some of the more popular ones are:

* [NodeMCU](http://www.nodemcu.com)
* [Adafruit HUZZAH](https://www.adafruit.com/product/2471)
* [Wemos D1 Mini](https://wiki.wemos.cc/products:d1:d1_mini)
* [DF Robot WiFi Bee](https://www.dfrobot.com/product-1279.html)

All of them offering something a bit different but still a spin on the basic chip design of the ESP8266/ESP32.

### ESP8266 Example Pinout

<img src="{% asset_path "ESP8266-pinout.png" %}" alt="ESP8266 Pinout" class="img-responsive" />

### ESP32 Example Pinout

<img src="{% asset_path "ESP32-pinout.jpg" %}" alt="ESP32 Pinout" class="img-responsive" />

## The Future

So what happens when I feel happy I've conquered the various sensors, displays and experiments with the Arduino? Build them in ESP32 and ESP8266 versions of course and use one of the serviucres mentioned in another post or my own local Flask dashboard and API. Here's to an exciting IoT future.