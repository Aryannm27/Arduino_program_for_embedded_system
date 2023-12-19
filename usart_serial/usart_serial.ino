include <SoftwareSerial.h>
rxData[101];
rxDataLen = 100;
void setup()
{
 Serial.begin(9600);
}
void printBuffer(reverse, *str, len, *buf) {
    Serial.print("\n");
    Serial.print("the string and its length");
    int ofset;
    for (i = 0; i < len; i++) {
        if (reverse) ofset = len-i-1;
        else ofset = i;
        Serial.print(buf[ofset]);
    }
    Serial.print(buf);
    Serial.print("\n");
}
void writeUART(reverse, printBuf, len, *buf) {
    int ofset;
    for (i = 0; i < len; i++) {
        if (reverse) ofset = len-i-1;
        else ofset = i;
    Serial.write(buf[ofset]);
    }
    Serial.write('\n');
    delay(100);
    if (printBuf) printBuffer(reverse, "RecvSend::Sending", len, buf);
}
int readUART (printRecvd) {
    count = 0
    if (Serial.available()<0) return count;
    while (true) {
       if (Serial.available()>0) {
          read the data
          if('\n') break;
          count++;
          if (count >= rxDataLen) break;
       }
    }
 //Terminate the string
     if (printRecvd) {
          printBuffer (false, "RecvSend::Received", count, rxData)
     }
     return count;
}
void loop()
{
    count = 0
    if (Serial.available()>0) {
       count = readUART(false);
    }
    if (count>0) {
       writeUART(true, false, count, rxData)
    }
    else {
       Serial.print("Nothing");
    }
    delay(1000);
}

