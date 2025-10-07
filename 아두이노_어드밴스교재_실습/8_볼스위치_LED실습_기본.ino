int LED_A = 3;
int LED_B = 2;
int BallSW_A = 6;
int BallSW_B = 5;

void setup() {
    pinMode(LED_A, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(BallSW_A, INPUT_PULLUP);
    pinMode(BallSW_B, INPUT_PULLUP);
}

void loop() {
    if(digitalRead(BallSW_A) == LOW) {
        digitalWrite(LED_A, HIGH);
        
    }
    
    else {
        digitalWrite(LED_A,LOW);
    }
    
    if(digitalRead(BallSW_B) == LOW) {
        digitalWrite(LED_B, LOW);
    }

    else {
        digitalWrite(LED_B, HIGH);
    }

}