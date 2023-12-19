char rxData[256];
int rxDataLen = 100;
int count;
void setup() {
 Serial.begin(9600);
}
void printBuffer(int len,char *buf) {
 while(len!=0){
   Serial.print(*buf);
   buf++; 
   len--;
 }
 Serial.print("\n");
}
void readUART(bool printRecvd){
 count = 0;
 while(true) {
  if(Serial.available()>0){
    rxData[count]=Serial.read();
    if(rxData[count]=='\n') break;
    count++;
    if (count >= rxDataLen) break;
  }
 }
 rxData[count]='\0';
 if(printRecvd) {
 printBuffer(count, rxData);
 }
}
void loop()
{
 count = 0;
 if (Serial.available()>0) {
 readUART(true);
 }
 delay(100);
}

