#include <Wire.h>
int addr=0x54;
char txBuffer[] = "0123456789";
int txBufferLen = 10;
char datab[20];
void setup() {
    Wire.begin();
    Serial.begin(9600);
}
void loop() {
//    delay(100);
    //Serial.print("\nSending Data to the I2C Slave");
    Wire.beginTransmission(addr);
    Wire.write(txBuffer);
    Wire.endTransmission();
    //delay(100);
    //Serial.print("\n\nReceiving Data to the I2C Slave");
    Wire.requestFrom(addr,1);
//    while(Wire.available()<0){
//        delay(1000);
//    }
    int i=0;
    //while(Wire.available()>0) {
          char op=Wire.read();
          //datab[i]=op;
         // i++;
          Serial.print(op);
          delay(10);
    //}
//    int t=sizeof(datab)/sizeof(datab[0]);
//    for(int i=0;i<t;i++){
//      Serial.println(datab[i]);
  //  }
}
