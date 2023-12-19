#include <avr/io.h>
#include <avr/interrupt.h>

const int LED_pin = 13; 
unsigned int reload = 0xF424; 
volatile int count;

ISR(TIMER1_COMPA_vect)
{
count++;
flash();
}
void setup()
{
Serial.begin(115200);
pinMode(LED_pin, OUTPUT);
digitalWrite(LED_pin, LOW);
cli();
TCCR1A = 0;
TCCR1B = 0; 
OCR1A = reload;
TCCR1B = (1<<WGM12) | (1<<CS12); 
TIMSK1 = (1<<OCIE1A); 
sei(); 
Serial.println("TIMER1 Setup Finished.");
}
void loop()
{
Serial.println(count); // do anything
delay(200);
}
void flash()
{
static boolean output = HIGH;
digitalWrite(LED_pin, output);
output = !output;
}
