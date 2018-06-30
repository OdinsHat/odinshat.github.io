---
title: MQ Gas Sensors List
date: 2018-06-24 23:20:31
tags:
 - arduino
 - iot
 - electronics
---

Here's a not entirely comprehensive list of the MQ gas sensors often seen being used in Arduino smoke alarm or breathalyser projects. Like mine for example. I also have 2 of these set up as analog sensors on my Enviro pHat connected PiZero. One being an MQ135 and the other MQ-2. Not sure why I need to keep an eye on gas leaks in the living room but you never know! MQ-135 may make a bit more sense though to be honest it keeps a pretty still *0.41* value for the past several days. I may replace it with the optical [Sharp GP2Y1010AU0F dust sensor](https://rover.ebay.com/rover/1/710-53481-19255-0/1?mpre=https%3A%2F%2Fwww.ebay.co.uk%2Fitm%2FSHARP-PM2-5-sensor-GP2Y1010AU0F-Compact-Optical-Dust-Sensor%2F181935249428%3Fepid%3D1488932038%26hash%3Ditem2a5c2f9814%3Ag%3AYVEAAOSwsFpWTA09&campid=5338315954&toolid=20008) as a general air quality indicator.

* MQ-2 - Methane, Butane, LPG, smoke
* MQ-3 - Alcohol, Ethanol, smoke
* MQ-4 - Methane, CNG Gas
* MQ-5 - Natural gas, LPG
* MQ-6 - LPG, butane gas
* MQ-7 - Carbon Monoxide
* MQ-8 - Hydrogen Gas
* MQ-9 - Carbon Monoxide, flammable gasses
* MQ131 - Ozone
* MQ135 - Air Quality (CO, Ammonia, Benzene, Alcohol, smoke)
* MQ136 - Hydrogen Sulfide gas
* MQ137 - Ammonia
* MQ138 - Benzene, Toluene, Alcohol, Acetone, Propane, Formaldehyde gas, Hydrogen
* MQ214 - Methane, Natural gas
* MQ216 - Natural gas, Coal gas

While you're here you may find the [following tutorial](https://tutorials-raspberrypi.com/configure-and-read-out-the-raspberry-pi-gas-sensor-mq-x/) on how to read MQ sensor values using a Raspberry Pi and how to convert its analog data output to a digital output for the Pi.