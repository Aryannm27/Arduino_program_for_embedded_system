void setup(){
  Serial.begin(9600);
}
void loop(){
  for (int i=30;i<=39;i++){ 
    Serial.write(i);
  }
  delay(100);
}

