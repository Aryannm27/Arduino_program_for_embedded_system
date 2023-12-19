byte mode=0;
byte preScaler;
int initValue=0;
int matchValue=46445;
void setTimer1InitValue(int initValue){
TCNT1 = initValue;
}
void setTimer1CompareValue(int matchValue){
OCR1A = matchValue;
}
void setupTimer1(int mode,int preScaler,int initValue,int matchValue){
noInterrupts();
TCCR1B=0;
TCCR1A=0;
setTimer1InitValue (initValue);
//set the prescaler
setTimer1CompareValue(matchValue);
TCCR1B |=(1 << CS12);
//set the mode of operation
if (mode == 0) {
 //enable timer overflow interrupt
 TIMSK1 |= (1 << TOIE1); 
 }
 else {
 //enable timer compare
 TIMSK1 |= (1 << OCIE1A);
 }
interrupts(); 
}
void toggleLED(){
 digitalWrite(13,HIGH);
 delay(1000);
 digitalWrite(13,LOW);
 delay(1000);
}
//interrupt service routine
ISR(TIMER1_OVF_vect){
 setTimer1InitValue(0);
 toggleLED();
}
void setup(){
 Serial.begin(9600);
 pinMode(13,OUTPUT);
 setupTimer1(0, 0, 0, 0);
}
void loop(){
 delay(100);
}
