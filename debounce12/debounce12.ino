const int led=8;
const int button=3;
int ledstate=HIGH;
int buttonstate=LOW;
int laststate;
unsigned long lastdebounce=0;
unsigned long debouncedelay = 50;
void setup() {
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  int reading=digitalRead(button);
  if(reading!=laststate){
    lastdebounce=millis();
  }
  if((millis()-lastdebounce) > debouncedelay)
  {
    if(buttonstate!=reading){
      buttonstate=reading;
      if(buttonstate==HIGH){
      ledstate=!ledstate;
    } 
    }
  }
  digitalWrite(led,ledstate);
  laststate=reading;
}
