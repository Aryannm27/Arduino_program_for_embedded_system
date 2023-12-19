#include <SPI.h>
char masterTXBuf[] = "THIS IS THE MASTER SEND";
byte masterTXBufLen = 23;
char masterRXBuf[128];
byte masterBufOffset = 0;
void setup (void)
{
 Serial.begin(115200);
 digitalWrite(SS,HIGH); 
 SPI.begin();
 pinMode(MOSI,OUTPUT);
 SPI.setClockDivider(SPI_CLOCK_DIV16);
}
void spiTXRX() {
 masterBufOffset = 0;
 byte i = 0;
 digitalWrite(SS,LOW);
 for (i = 0; i < masterTXBufLen; i++) {
 masterRXBuf[i] = SPI.transfer(masterTXBuf[i]);
 Serial.print("transmitted:");
 Serial.print(masterTXBuf[i]);
 Serial.print("received:");
 Serial.println(masterRXBuf[i]);
 }
 digitalWrite(SS,HIGH);
 masterRXBuf[i]='\0';
}
void loop(void)
{ 
 spiTXRX();
 Serial.print("Sent:");
 Serial.print(masterTXBuf);
 Serial.print("Received:");
 Serial.print(masterRXBuf);
 delay;
}

