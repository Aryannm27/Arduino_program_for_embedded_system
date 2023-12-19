const int pin=5;
void setup(){
 Serial.begin(9600);
 pinMode(pin,OUTPUT);
}
byte i;
void loop() {
 for(i = 0; i < 256; i++) {
 Serial.print("Duty cycle of PWM: ");
 Serial.println((i*100)/255);
 analogWrite(pin, i);
 delay(50);
 }
 for (i = 255; i >= 0; i--) {
 Serial.print("Duty cycle of PWM: ");
 Serial.println((i*100)/255);
 analogWrite(pin, i);
 delay(50);
 }
}
