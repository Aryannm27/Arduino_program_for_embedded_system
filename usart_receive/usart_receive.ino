void setup() {
 Serial.begin(115200);
}
void loop() {
 char str1[256];
 byte strLen = 0;
 while (Serial.available()>0) {
    str1[strLen]=Serial.read();
    strLen++;
 }
 str1[strLen] = '\0';
 byte i=0;
 while(str1[i]!='\0'){
  Serial.print((char)str1[i]);
  i++;
 }
 delay(100);
}
