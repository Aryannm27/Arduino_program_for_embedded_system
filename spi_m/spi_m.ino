#include <SPI.h>
//char val[]="Iammaster\n";       //master
char val='o';
char ch;
void setup (void) {
   Serial.begin(9600); //set baud rate to 115200 for usart
   digitalWrite(SS, HIGH); // disable Slave Select
   SPI.begin();
   SPI.beginTransaction(SPISettings(1500000, MSBFIRST, SPI_MODE0));
   //SPI.setClockDivider(SPI_CLOCK_DIV32);//divide the clock by 8 1000000
   
}

void loop (void) {
   digitalWrite(SS, LOW); // enable Slave Select
//   for (int i=0;i<sizeof(val);i++)
//   {
      ch=SPI.transfer(val);
     Serial.print(ch);
//     //delay(10);
//   }
   digitalWrite(SS, HIGH); // disable Slave Select
   delay(10);
}
