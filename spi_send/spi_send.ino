#include<SPI.h>
void setup (void)
{
    Serial.begin(9600); 
    digitalWrite(SS,HIGH);
    SPI.begin(); 
    SPI.setClockDivider(SPI_CLOCK_DIV16); 
}
void loop(void)
{
    char x[6]="HELLO"; 
    //Mastersend;
    for (int i=0; i<6; i++)
    {
        digitalWrite(SS,LOW); 
        SPI.transfer(x[i]);
        Serial.print(x[i]);
    }
    digitalWrite(SS,HIGH);
    delay(2000);
}

