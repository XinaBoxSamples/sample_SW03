/**************************************************************************/
/*!
    @file     Adafruit_MPL3115A2.cpp
    @author   K.Townsend (Adafruit Industries)
    @license  BSD (see license.txt)

    Example for the MPL3115A2 barometric pressure sensor

    This is a library for the Adafruit MPL3115A2 breakout
    ----> https://www.adafruit.com/products/1893

    Adafruit invests time and resources providing this open source code,
    please support Adafruit and open-source hardware by purchasing
    products from Adafruit!

    @section  HISTORY

    v1.0 - First release
*/
/**************************************************************************/

#include <xCore.h> //include the core library @ https://github.com/xinabox/xCore
#include <Adafruit_MPL3115A2.h> //include the Adafruit library @ https://github.com/adafruit/Adafruit_MPL3115A2_Library
#include <xOD01.h> //include the sensor library @ https://github.com/xinabox/xOD01

// Power by connecting Vin to 3-5V, GND to GND
// Uses I2C - connect SCL to the SCL pin, SDA to SDA pin
// See the Wire tutorial for pinouts for each Arduino
// http://arduino.cc/en/reference/wire
Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();

void setup() {
  Wire.begin(2, 14);
  OLED.begin();
  Serial.begin(115200);
  OD01.println("Adafruit_MPL3115A2 test!");
}

void loop() {
  if (! baro.begin()) {
    OD01.println("Couldnt find sensor");
    return;
  }
  
  float pascals = baro.getPressure();
  // Our weather page presents pressure in Inches (Hg)
  // Use http://www.onlineconversion.com/pressure.htm for other units
  OD01.print(pascals/3377); OD01.println(" Inches (Hg)");

  float altm = baro.getAltitude();
  OD01.print(altm); OD01.println(" meters");

  float tempC = baro.getTemperature();
  OD01.print(tempC); OD01.println("*C");

  delay(250);
}
