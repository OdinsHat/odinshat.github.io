/**
 * Breathalyser Circuit using the following items:
 * 1. An Arduino Nano (AtMega 328P).
 * 2. MQ-3 Ethanol sensor
 * 3. Single red LED
 *
 * This is all pre-calibration so one of the main bugs currently need
 * attention is the LED lights on detection of ethanol and goes out when
 * ethanol removed.
 *
 * However the analogue sensor is detecting correctly.
 */

#include <Arduino.h>
/**
 * The digital and analog pins of the sensor ad where they go on the Arduino   * Nano
 */
const int DOUTpin=8;
const int AOUTpin=0;

//The digital pin assigned to the LED output
const int ledPin=13;

int limit;
int sensorValue;  // Between 0 - 1023

/**
 * Setting up serial caud rate as 115200
 * Setting the pinMode for pin 8 to INPUT (it will recieve 1 or 0 dependent on  * alcohol dtection)
 * Setting digital pin 13 as the OUTPUT pin for the LED to show if ethanol is  * detected.
 */
void setup() {
  Serial.begin(115200);
  pinMode(DOUTpin, INPUT);
  pinMode(ledPin, OUTPUT);
}

/**
 *
 *
 */ 
void loop()
{
  sensorValue = analogRead(AOUTpin);
  limit = digitalRead(DOUTpin);
  Serial.print("Alcohol sensorValue: ");
  Serial.println(sensorValue);

  delay(100);
  if (limit == HIGH){
    Serial.print("Detetcted Alcohol: ");
    Serial.print(limit);
    Serial.println("\n");
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.print("No Detetcted Alcohol");
    Serial.print(limit);
    Serial.println("\n");
    digitalWrite(ledPin, LOW);
  }
}
