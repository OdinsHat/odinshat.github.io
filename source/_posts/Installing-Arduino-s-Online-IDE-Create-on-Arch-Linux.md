---
title: Installing Arduino's Online IDE Create on Arch Linux
tags:
  - arduino
  - arch linux
  - arch
date: 2018-05-09 14:02:12
---


[Arduino Create](https://create.arduino.cc/) is the online sketch editor available for writing you sketches online for uploading to whatever [Arduino](https://www.arduino.cc) tech you may have. Your sketches are kept safely in the cloud acessible form anywhere you have a PC and an Arduino. Once you get used to the workflow its handy to be able to keep a dev board handy on you and login in whjen you have 5 mins during a lunch break to fiddle with your sketch after having an idea or two.

It does all this by installing a plugin dependent on the OS you're runnning. They support Windows, OSX, Linux & ChromeOS.

In this blog I'll concentrate on **Arch Linux**. As it's got a reputation for being prickly and I did have a couple of errors on install so I thought I'd share the soilutions so you can get the benefits of using Arduino Create on your Arch install like I am.

All in all the Arduino people have done a great job of making this plugin and incredibly easy piece of kit to get running. But as wiuth everything Linux its hard to cover every base.

So lets get started and by the end you should have a working Arduino Create account thgat can iupload sketches to your board.

**If you have any problems feel free to leave a comment with your problem and I'll see what I can do.**

### 1. Install Dependencies

These are Arch-sepcific and were the first hurdle I hit when I simply followed the instructions. Be sure to run the following:

`yaourt -S lib32-libindicator-gtk3 lib32-libappindicator-sharp lib32-libindicator-gtk2 libindicator-gtk2 libindicator-gtk3 libindicator-sharp python-libindicator`

### 2. Setup Arduino Create Account

Follow the online instrucvtions to setup your account and after confirming your email at the end you'll be given a download file in `tar.gz` format containing a single .run file. At the time of writing my archive contained the file: `ArduinoCreateAgent-1.1-linux-x64-installer.run`. This file should already have its permissions set to be able to run but if not then siple `chmod +x [FILENAME]` then run it on the terminal as so `./ArduinoCreateAgent-1.1-linux-x64-installer.run` - don't forget your filename will be different so **don't** just copy/paste mine verbatim.

### 3. Complete Installation

Once the installation is complete you can either continue form here or shutdown the installation file (this required me to manually kill the process). To later launch the client for future use you will run the `Arduino_Create_Bridge` executable file from the installation directory you chose upon install. This defaults to something like `~/ArduinoCreateAgent-1.1/Arduino_Create_Bridge`.

When you run this and visit the Arduino Create online editor its advisable to follow the on-screen tour to get a feel for whats available and how to manage libraries and examples.