#include <Wire.h>
int addr=0x24;
char rxBuffer;
char ror[]="1232";
char datap[15];
int txBufferLen = 10;
void setup() {
    Serial.begin(9600);
    Wire.begin(addr);
    Wire.onReceive(rxEvent);
    Wire.onRequest(rqEvent);
}
void rxEvent()
{
    while( Wire.available()>0) {
      for(int i=0;i<5;i++){
        rxBuffer=Wire.read();
        datap[i]=rxBuffer;
      }
    }
    Serial.println(datap);
}  

void rqEvent(){
  char a[]="war";
   Wire.write(a);
}
void loop() {
}
