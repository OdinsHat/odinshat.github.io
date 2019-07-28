---
title: Using the CJMCU 8128 Breakout Environment Sensor Board
date: 2018-07-28 19:30:56
tags: raspbery pi, pi, sensors, electronics
---

The CJMCU 8128 breakout board includes a great trio of environment sensors that pretty much cover all the bases when it comes to sensing your local environment and has a few overlaps especially with temperature. I've only seen it avialable so far at [Baggood.com](https://www.banggood.com/CJMCU-8128-CCS811-SI7021-BMP280-Carbon-Dioxide-CO2-VOCs-Temperature-Humidity-Gas-Pressure-Sensor-p-1167432.html).

In the picture below you can see each of the three sensors labelled:

{% asset_img cjmcu-8128-modules.jpg "CJMCU Module" %}

## What's on Board

These relatively cheap sensors include 3 main modules - with links to their data sheets:

Its worth mentioning the temperature values returned by each of these sensors are all different and sometimes by a few degrees so you could either use all 3 and pick an average of the 3 or pick the one which has the smallest reported variance according to its datasheet. Which at the time of writing would be the HDC1080.

Having said that I'd still recommend checking the temperature's reporting against other sensors you may have and deciding for yourself.

## Hooking up to a Raspberry Pi 3

You only need to hook up the 5 of the 8 pins provided for all 3 sensors to work on a Raspberry Pi connected using the i2C bus with pins VCC and GND being self-explanatory. Although VCC should go to 3.3V supply pin on the Raspberry Pi. The SDA and SCL pins shoyuld go to the corresponding SDA/SCL i2c GPIO pins. The last pin to notice is the WAK pin which according to the documentation should go to a free Ground pin.
[CCS811 datasheet](https://ams.com/documents/20143/36005/CCS811_AN000369_2-00.pdf/25d0db9a-92b9-fa7f-362c-a7a4d1e292be)[PDF]. The WAK(E) pin is used to wake a sleeping sensor from a hibernated low-power state. To make the module sleep you would put logic high to pin WAK and to wake the module you'd put logic low or Ground to that pin. As the whole breakout board uses only a tiny amount of power anyway and this post is about being connected to a Raspberry Pi I've chosen to hook up the WAK pin to GND to keep it permanently awake.

If you were using this on an ESP32 or ESP8266 where you wanted to take advantage of low power states then its worth looking further into this by checking the datasheets for each sensor.

See below for a photo of one connected and working with my home setup.

{% asset_image cjmcu-8128-wired-up.jpg "Wired Up CJMCU Module" %}

## Prerequisites

### Required Libraries

I've [created a repo](https://github.com/OdinsHat/cjmcu-8128-sensor-breakout) with an example that uses all three of the onboard sensors based off submodules of existing libraries that are out there for each. Adafruit have Python libraries for the CCS811 and BME280. With SDL having an example Python script for the HDC chip.

You can reach the repo with an example that combines all 3 of the submodules [here](https://github.com/OdinsHat/cjmcu-8128-sensor-breakout).

There are other libraries you an use as the above uses Python mainly but especially in the case of the BME280

That library is what I am using with my own IoT setup at home with the small change of including and using Artik Python libraries to send my data to Samsung Artik for displaying the data in a dashboard format.

### Ensuring the Breakout is Connected Correctly

You can run the i2cdetect command with the following arguments:

`i2cdetect -y 1`

You should get the following output:

```
0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- --
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
40: 40 -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
50: -- -- -- -- -- -- -- -- -- -- 5a -- -- -- -- --
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
70: -- -- -- -- -- -- 76 --
```

This stage is important as the default address for the BME/P 280 is 0x77 but in the CJMCU board it is as you can see above 0x76. Thankfully the Adafruit library comes with the ability to set the address on instantiation of the sensor class. See below...

```
    sensor = BME280(
        t_mode=BME280_OSAMPLE_8,
        p_mode=BME280_OSAMPLE_8,
        h_mode=BME280_OSAMPLE_8,
        address=0x76
    )
```