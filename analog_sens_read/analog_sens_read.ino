void setup() {
  Serial.begin(9600);
}

void loop() {
  int sen=analogRead(A0);
  Serial.println(sen);
  delay(100);
}
