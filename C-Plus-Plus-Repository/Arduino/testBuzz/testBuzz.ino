//Buzzer with tone().
//sketch created by Akshay Joseph
void setup() {
pinMode(11,OUTPUT);
}

void loop() {
tone(11,5000);
delay(500);
noTone(11);
 delay(500);
}
