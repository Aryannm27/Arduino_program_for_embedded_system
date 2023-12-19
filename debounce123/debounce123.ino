const int led=13;
const int button=2;
int prev2=LOW;
int curr2;
unsigned long lastChangeTime=0;
void setup() {
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}
unsigned long debounceDelay = 50;
bool checkDebounce(int prev) {
 int currReading;
 lastChangeTime = millis();
 while(true) {
 currReading = digitalRead(button);
 if(currReading != prev) {
 lastChangeTime = millis();
 prev = currReading;
 }
 if((millis()-lastChangeTime) > debounceDelay) {
 return true;
 }
}
 delay(100);
}
void toggleLED() {
 digitalWrite(led,HIGH);
 delay(1000);
 digitalWrite(led,LOW);
 delay(1000);
}
void loop() {
 curr2 = digitalRead(button);
 if(curr2 != prev2) {
 if(checkDebounce(curr2)) {
 prev2 = curr2;
 toggleLED ();
 }
 }
 delay (100);
}
