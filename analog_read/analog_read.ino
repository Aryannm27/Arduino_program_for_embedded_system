int prevValue;
int currValue;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,OUTPUT);
 prevValue = currValue = 0;
}
void loop() {
 currValue = analogRead(A0);
 if (currValue != prevValue) {
    Serial.println(currValue);
    analogWrite(A1,currValue);
    prevValue = currValue;
 }
 delay;
}
