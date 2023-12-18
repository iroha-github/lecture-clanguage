int LED1 = 9; 
int SW1 = 13;
int LED2 = 10;
int SW2 = 12;

void setup()
{
    pinMode(LED1, OUTPUT);
    pinMode(SW1, INPUT);
    pinMode(LED2, OUTPUT);
    pinMode(SW2, INPUT);
}

void loop()
{
    if(digitalRead(SW1) == HIGH){
        digitalWrite(LED1, LOW);
    } else {
        digitalWrite(LED1, HIGH);
    }
    if(digitalRead(SW2) == HIGH){
        digitalWrite(LED2, LOW);
    } else {
        digitalWrite(LED2, HIGH);
    }
}