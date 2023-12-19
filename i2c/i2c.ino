/* This code is to use with Adafruit BMP280   (Imperial)
 * It measures   both temperature and pressure and it displays them on the Serial monitor with the   altitude
 * It's a modified version of the Adafruit example code
 * Refer   to www.surtrtech.com or SurtrTech Youtube channel
 */

#include <Adafruit_BMP280.h>

Adafruit_BMP280   bmp; // I2C

void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280   test"));

  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find   a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  /* Default   settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /*   Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp.   oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure   oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering.   */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void   loop() {
    
    float f = bmp.readTemperature()*9/5 + 32 ; //Conversion   from C to F
    Serial.print(F("Temperature = "));    
    Serial.print(f);
    Serial.println(" *F");
    
    float P = bmp.readPressure()/3386.39;    //displaying the Pressure in inches of mercury, you can change the unit
    Serial.print(F("Pressure   = "));
    Serial.print(P);
    Serial.println(" inHg");

    float   A = bmp.readAltitude(1019.66)*3.28084;   //The "1019.66" is the pressure(hPa)   at sea level in day in your region
    Serial.print(F("Approx altitude = "));         //If you don't know it, modify it until you get your current altitude
    Serial.print(A);
    Serial.println(" ft");

    Serial.println();
    delay(2000);
}

