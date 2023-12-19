#define MQ2 A0
void setup() {
  Serial.begin(9600);
  Serial.println("sensor is start");
  delay(20000);
  pinMode(7,INPUT);
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
  
}
int sensorv,abc;
void loop() {
  // put your main code here, to run repeatedly:
  sensorv=analogRead(MQ2);
  abc=digitalRead(7);
  Serial.print("sensor value: ");
  Serial.print(sensorv);
  Serial.print(abc);
  digitalWrite(13,abc);
  analogWrite(9,sensorv);
  if(sensorv>200){
    Serial.print("   active");
  }
  Serial.println(" ");
  delay(2000);
}
