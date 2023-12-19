#include<SPI.h>
bool received;
byte Slavereceived;
char c;
void setup()
{
    //Set the clock frequency, mode of transmission and MSB or LSB first
    Serial.begin(9600); 
    pinMode(MISO,OUTPUT); 
    SPCR |= _BV(SPE);
    received = false;
    SPI.attachInterrupt(); 
}
ISR(SPI_STC_vect) 
{
    Slavereceived = SPDR;
    received = true;
}
void loop()
{
    if(received) 
    {
        received = false;
        Serial.println((char)Slavereceived);
        //delay(100);
    }
    for (const char * p = "Hello, world!\r" ; c = *p; p++) {
      SPI.transfer (c);
      Serial.print(c);
   }
}

