#include<SPI.h>
char masterTXBuf[] = "THIS IS our MASTER\n";
byte masterTXBufLen = 20;
char masterRXBuf[20];
byte masterBufOffset = 0;
void setup (void)
{
    Serial.begin(9600); 
    digitalWrite(SS,HIGH); 
    SPI.begin();
    pinMode(MOSI,OUTPUT);
    SPI.setClockDivider(SPI_CLOCK_DIV64);
}
void spiTXRX() {
      masterBufOffset = 0;
      int i = 0;
      digitalWrite(SS,LOW);
      for (i = 0; i < masterTXBufLen; i++) {
          masterRXBuf[i] = SPI.transfer(masterTXBuf[i]);
//          Serial.print("\ntransmitted:");
//          Serial.print(masterTXBuf[i]);
//          Serial.print("\nreceived:");
//          Serial.print(masterRXBuf[i]);
      }
      digitalWrite(SS,HIGH);
      masterRXBuf[i]='\0';
}
void loop(void)
{ 
    spiTXRX();
//    Serial.print("\nSent:");
//    Serial.print(masterTXBuf);
    Serial.print("\nReceived:");
    Serial.println(masterRXBuf);
}

