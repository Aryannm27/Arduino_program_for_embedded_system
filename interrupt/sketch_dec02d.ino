const byte led = 13;
const byte button = 2;
const byte button2=3;
byte i = LOW;
byte j = LOW;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
  pinMode(button2,INPUT);
}
void loop() { 
  attachInterrupt(digitalPinToInterrupt(button),jgk,HIGH);
  for(int i=0;i<100;i++)delayMicroseconds(5000);
  detachInterrupt(digitalPinToInterrupt(button));
  
}
void jgk(){

    digitalWrite(led,HIGH);
    for(int i=0;i<100;i++)delayMicroseconds(5000);
    digitalWrite(led,LOW);
    for(int i=0;i<100;i++)delayMicroseconds(5000);
}
