#define echoPin 2
#define trigPin 3
#define led1 8
#define led2 9
#define led3 10
#define buzzer 11 
#define relay 12
long duration;
int distance;
void setup(){
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(buzzer,OUTPUT);
 }
void loop(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
 duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034/2);
  if(distance<15){
    digitalWrite(relay,HIGH);
  }
  if(distance<=18){
    digitalWrite(led1,HIGH);
    digitalWrite(buzzer,HIGH);
    
  }
  else {
    digitalWrite(led1,LOW);
    digitalWrite(buzzer,LOW);
  }
  if (distance<24 && distance >=18){
    digitalWrite(led2,HIGH);
  }
  else {
    digitalWrite(led2,LOW);
  }
  if (distance >24){
    digitalWrite(led3,HIGH);
  }
  else {
    digitalWrite(led3,LOW);
  }
  if(distance >28){
    digitalWrite(relay,LOW);
  }
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm ");
  delay(1000);
               
}
