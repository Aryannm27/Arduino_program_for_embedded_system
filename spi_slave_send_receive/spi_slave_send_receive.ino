#include<SPI.h>
bool rxDone;
byte slaveRX;
byte slaveTX;
char slaveTXBuf[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
byte slaveTXBufLen = 62;
byte slaveTXOffset;
char slaveRXBuf[256];
byte slaveRXBufLen = 256;
byte slaveRXOffset = 0;
char getslaveSend(void) {
 slaveTX = slaveTXBuf[slaveTXOffset];
 slaveTXOffset++;
 if (slaveTXOffset == slaveTXBufLen) slaveTXOffset = 0;
 return slaveTX;
}
byte prevIfNum;
byte loopNum;
void setslaveReceived() {
 if (slaveRXOffset >= slaveRXBufLen-1) {
 slaveRXOffset = 0;
 for (int i = 0; i < slaveRXBufLen; i++) {
 slaveRXBuf[i] = 0;
 }
 }
 slaveRXBuf[slaveRXOffset] = slaveRX;
 slaveRXOffset++;
}
void setup()
{
 Serial.begin(115200);
 SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
 pinMode(MISO,OUTPUT); 
 SPCR |= _BV(SPE);
 rxDone = false;
 SPI.attachInterrupt();
 slaveTXOffset = 0;
 slaveRXOffset = 0;
 SPDR = getslaveSend();
 prevIfNum = 0;
 loopNum = 0;
}
ISR (SPI_STC_vect) 
{
 slaveRX = SPDR;
 setslaveReceived();
 SPDR = getslaveSend();
 rxDone = true;
}
void loop()
{
 if (rxDone) {
 rxDone = false;
 Serial.print("RX:");
 Serial.print(slaveRX);
 }
 
 //print if a character has been received
 if (slaveRXOffset > 0 &&(slaveRXOffset != prevIfNum)) {
 prevIfNum = slaveRXOffset;
 Serial.print("RXBUF:");
 Serial.print(slaveRXOffset, DEC);
 Serial.print(slaveRXBuf);
 }
}
