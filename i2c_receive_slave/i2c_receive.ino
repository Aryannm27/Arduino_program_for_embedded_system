#include <Wire.h>
char rx_data[10];
void receiveEvent()
{
    while (Wire.available())
    {
        for (int i=0; i<5; i++)
        {
            char d=Wire.read();
            //delay(100);
            Serial.print(d);
        }
    }
    delay(100);
}
void setup()
{
    Wire.begin(0x23);
    Wire.onReceive(receiveEvent);
    Serial.begin(9600);
}
void loop()
{
    delay(100);
}


