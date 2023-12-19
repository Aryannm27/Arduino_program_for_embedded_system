#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 11

// Set up a new SoftwareSerial object
SoftwareSerial Serial11 =  SoftwareSerial(rxPin, txPin);
char txData[]="Ekarshi Opensource Foundation is a Public incorporated on 04 October 2020. It is classified as Non-govt company and is registered at Registrar of Companies, Ahmedabad.";
int txDataLen = sizeof(txData) / sizeof(txData[0]);
char rxData[241];
int rxDataLen = 240;
void setup()
{
    Serial.begin(9600);
    Serial11.begin(9600);
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    while (Serial.available()<0 || Serial11.available()<0) {
      delay(1000);
    }
}
//(if print buffer is enabled, then you will get wierd result at the destination)
void printBuffer (char *str1, int len, char *buf) {
    Serial.print(str1);
    for (int i = 0; i < len; i++) {
      Serial.print(*buf++);
    }
    Serial.print("\n  oo  ");
}
void writeUART(bool printBuf, int len, char *buf) {
    //Serial.write("sending:");
    Serial11.write(buf, len);
    Serial11.write("\n");
  //  delay(100);
    if (printBuf){
      printBuffer("Sending:", len, buf);
    }
}
void readUART(bool printRecvd) {
    int count = 0;
    while(true) {
        if (Serial11.available()>0) {
             char p=Serial11.read();
             rxData[count]=p;
             count++;
             if (p == '\n') break;
           //  if (count >= rxDataLen) break;
        }
    }
     //Terminate the string
    if (printRecvd) {
      printBuffer("Receiving:", count, rxData);
    }
}
void loop()
{
    readUART(true);
    delay(1000);
    writeUART(false,txDataLen, txData);
    delay(1000);
    
}
