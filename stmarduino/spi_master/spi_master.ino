#include <SPI.h>
char valo[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ\r\n";
char ch[sizeof(valo)];
int i=0;
void setup (void) {
   Serial.begin(9600); //set baud rate to 115200 for usart
   digitalWrite(SS, HIGH); // disable Slave Select
   SPI.begin ();
   //   SPI.setClockDivider(SPI_CLOCK_DIV4);//divide the clock by 8
//   SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
}

void loop (void) {
   digitalWrite(SS, LOW); // enable Slave Select
  for(int i=0; i<sizeof(valo);i++){
      ch[i]=SPI.transfer(valo[i]);
      Serial.print(ch[i]);
      delay(20);
  }
   digitalWrite(SS, HIGH); // disable Slave Select
}
