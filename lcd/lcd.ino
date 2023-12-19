#include<avr/io.h>
#include<util/delay.h>
#define LCD_RS 0
#define LCD_RW 1
#define LCD_E 2
void delay_us(unsigned int d){
  for(;d>=1;d--)
  delayMicroseconds(1);
}
void lcdcommand(unsigned char cmd){
  PORTD=cmd;
  PORTB&=~(1<<LCD_RS);
  PORTB&=~(1<<LCD_RW);
  PORTB|=(1<<LCD_E);
  delay_us(1);
  PORTB&=~(1<<LCD_E);
  delay_us(100);
}
void lcddata(unsigned char dta){
  PORTD=dta;
  PORTB|=(1<<LCD_RS);
  PORTB&=~(1<<LCD_RW);
  PORTB|=(1<<LCD_E);
  delay_us(1);
  PORTB&=~(1<<LCD_E);
  delay_us(100);
}
void lcd_init(){
  DDRB=0xFF;
  DDRB=0xFF;
  PORTB&=(1<<LCD_E);
  delay_us(2000);
  lcdcommand(0x38);
  lcdcommand(0x0F);
  lcdcommand(0x01);
  delay_us(2000);
  lcdcommand(0x06);
  lcdcommand(0xC0);
}
void lcd_gotoij(unsigned char i,unsigned char j){
  unsigned char addr[]={0x80,0xC0,0x94,0xD4};
  lcdcommand(addr[j-1]+i-1);
  delay_us(100);
}
void lcdprint(char *dat){
  unsigned char x=0;
  while(dat[x]!=0){
    lcddata(dat[x]);
    x++;
  }
}
void setup(){
  lcd_init();
  lcd_gotoij(2,1);
  lcdprint("HELLO");
}

