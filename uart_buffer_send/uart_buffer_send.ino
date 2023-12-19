char txData[]="hello";
byte txDataLen=strlen(txData);
void setup()
{
 Serial.begin(9600);
 while(Serial.available()<0) {
 delay(100);
 }
}
void printBuffer (int len, char *buf) {
 Serial.print(len);
 for(int i = 0; i < len; i++) {
 Serial.print(*buf);
 buf++;
 }
 Serial.print(" hj ");
}
void writeUART(int len,char *buf) {
  Serial.write('\n');
  printBuffer(len, buf);
  Serial.write('\n');
  while(len!=0){
    Serial.write(*buf);
    buf++;
    len--;
  }

}
void loop()
{
 for(int i = 0; i < 10; i++) {
  writeUART(txDataLen, txData);
 delay(100);
 }
}
