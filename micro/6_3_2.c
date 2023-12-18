int LED = 9;
int SW1 = 13;
int SW2 = 12;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
}

void loop() {
  if(digitalRead(SW1) == LOW && digitalRead(SW2) == LOW){
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
