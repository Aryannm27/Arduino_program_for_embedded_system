#include<Wire.h>
char tx_data[]="HELLO";
void setup()
{ 
    Wire.begin();
}
void loop()
{
    Wire.beginTransmission(5);
    Wire.write(tx_data);
    Wire.endTransmission();
    delay(100);
}

