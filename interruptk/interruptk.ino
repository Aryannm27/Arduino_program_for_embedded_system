const byte led = 13;
const byte button = 2;
const byte by=3;
byte i = LOW;
byte j = LOW;
void blink13p(byte j){
  
}
void setup() {
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
  pinMode(by,INPUT);
  
}

void loop() { 
  j=digitalRead(by);
  i=digitalRead(button); 
  if(j){
    attachInterrupt(digitalPinToInterrupt(button),jgk,CHANGE);
  }
  else{
    detachInterrupt(digitalPinToInterrupt(button));
  }
  
}
void jgk(){
  if(i==HIGH){
    for(byte i=0;i<j;i++){
    digitalWrite(led,HIGH);
    for(int i=0;i<100;i++)delayMicroseconds(5000);
    digitalWrite(led,LOW);
    for(int i=0;i<100;i++)delayMicroseconds(5000);
    }
  }
}
