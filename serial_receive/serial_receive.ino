int St=0;
void setup(){
  Serial.begin(9600);
}
void loop(){
  while(Serial.available()>0){
    St=Serial.read();
    Serial.print(St);
  }
  delay(200);
}
