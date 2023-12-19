#include<SPI.h>
bool rxDone;
char slaveRX;
char slaveTX;
byte prevIfNum;
char slaveTXBuf[]="hello_you_are_world";
byte slaveTXBufLen = 20;
byte slaveTXOffset=0;
char slaveRXBuf[20];
byte slaveRXBufLen = 20;
byte slaveRXOffset=0;
char getslaveSend(){
    slaveTX = slaveTXBuf[slaveTXOffset];
    slaveTXOffset++;
    if (slaveTXOffset == slaveTXBufLen) 
    slaveTXOffset = 0;
    return slaveTX;
}
void setslaveReceived(){
     if (slaveRXOffset >= slaveRXBufLen-1) {
          slaveRXOffset = 0;
          for (int i = 0; i < slaveRXBufLen; i++){
              slaveRXBuf[i] = 0;
          }
    }
    slaveRXBuf[slaveRXOffset] = slaveRX;
    slaveRXOffset++;
}
ISR (SPI_STC_vect) 
{
     slaveRX = SPDR;
     setslaveReceived();
     SPDR = getslaveSend();
     rxDone = true;
}
void setup()
{
     Serial.begin(9600);
     SPI.beginTransaction(SPISettings(20000,MSBFIRST,SPI_MODE0));
     pinMode(MISO,OUTPUT);
     SPCR |= _BV(SPE); 
     rxDone = false;
     SPI.attachInterrupt();
     slaveTXOffset = 0;
     slaveRXOffset = 0;
     SPDR = getslaveSend();
     prevIfNum = 0;
}

void loop()
{
    if(rxDone) {
        rxDone = false;
//        Serial.print("\nRX:");
//        Serial.print(slaveRX);
    }
//    if (slaveRXOffset > 0 &&(slaveRXOffset != prevIfNum)) {
//        prevIfNum = slaveRXOffset;
        Serial.println("RXBUF: ");
//        Serial.println(slaveRXOffset, DEC);
        Serial.println(slaveRXBuf);
//    }
}
