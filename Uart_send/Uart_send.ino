#include <SoftwareSerial.h>
SoftwareSerial UART0(10,11);
char a;
void setup() {
 UART0.begin(9600);
 Serial.begin(9600);
 
}
void loop() {
 while(UART0.available()>0){
  a=UART0.read();
  Serial.print(a);
 }
 delay(100);
 UART0.write("Somjak\n");                                                                                                     
 delay(100);
}
