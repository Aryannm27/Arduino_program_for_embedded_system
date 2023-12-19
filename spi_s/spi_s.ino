#include <SPI.h>
char val[]="abcdefghijklmnopqrstuvwxyz\n";
//char val='o';
char ch;
int i=0;
void setup()
{
Serial.begin(9600);
SPI.beginTransaction(SPISettings(10000, MSBFIRST, SPI_MODE0)) ;
pinMode(MISO,OUTPUT);  //MISO
SPCR |= _BV(SPE);
SPI.attachInterrupt();
}

ISR(SPI_STC_vect){
  Receive_Data();
//  delay(50);
//  Send_Data(val);
//  if(i>=sizeof(val))
//    i=0;
   Send_Data(val);
//   i++; 
 }
 
void loop() {
  //delay(1000);
}

void Receive_Data()
{
      ch=SPDR;
      Serial.print(ch); 
}
//void Send_Data(char val)
//{
////      SPDR=val[i];
//      SPDR=val;
//      delay(10);
//}
void Send_Data(char *val)
{
  for(int i=0;i<sizeof(val);i++)
      SPDR=val[i];
}
      
