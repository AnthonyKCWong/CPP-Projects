// Lib for Dallas temperature sesnor
#include <OneWire.h>
#include <DallasTemperature.h>
//----------

// Lib for DF Robot LCD
//----------
#include <Wire.h>
#include "DFRobot_RGBLCD.h"

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
DFRobot_RGBLCD lcd(16,2);  //16 characters and 2 lines of show
char C = "Welcome!!!";

#define ONE_WIRE_BUS 2                // Data wire is plugged into digital pin 2 on the Arduino
OneWire oneWire(ONE_WIRE_BUS);        // Setup a oneWire instance to communicate with any OneWire device
DallasTemperature sensors(&oneWire);  // Pass oneWire reference to DallasTemperature library



void setup() {
    lcd.init();

    lcd.setRGB(colorR, colorG, colorB);

    sensors.begin();  // Start up the library
    Serial.begin(9600);
}

void loop() {
    // Send the command to get temperatures
  sensors.requestTemperatures(); 

  //print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
 // Serial.print(char(176));//shows degrees character
 // Serial.print("C  |  ");
 
/*
lcd.print(sensors.getTempCByIndex(0));
lcd.print("/n");
*/

  lcd.setCursor(0,0);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print(C);
  lcd.setCursor(0,1);
  lcd.print("Gravity: RGB LCD");

}
lcd.print(sensors.getTempCByIndex(0));
//   lcd.setCursor(0,0); this sets the cursor
