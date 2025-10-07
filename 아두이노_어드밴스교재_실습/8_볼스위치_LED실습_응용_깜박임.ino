int LED_A = 3;
int LED_B = 2;
int BallSW_A = 6;
int BallSW_B = 5;

const unsigned long blinkInterval = 500; // 깜박임 주기 (500ms)
unsigned long lastBlinkTime = 0;
bool ledAState = false;

void setup() {
    pinMode(LED_A, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(BallSW_A, INPUT_PULLUP);
    pinMode(BallSW_B, INPUT_PULLUP);

    // LED 상태 초기화
    digitalWrite(LED_A, LOW);
}

void loop() {
    // 기울어졌다면
    if (digitalRead(BallSW_A) == HIGH) {
        unsigned long currentTime = millis();   // 현재 시간 기록

        // 마지막 깜박임으로부터 500ms가 지났다면
        if (currentTime - lastBlinkTime >= blinkInterval) {
            // LED 상태 변경
            ledAState = !ledAState;
            digitalWrite(LED_A, (ledAState ? HIGH : LOW));    // 깜박

            // 마지막으로 '깜박' 한 시간 업데이트
            lastBlinkTime = currentTime;
        }
    } else {
        // 안 기울어졌다면 -> LED 끄기
        digitalWrite(LED_A, LOW);
        ledAState = false;
    }

    // 기본 버전
    if(digitalRead(BallSW_B) == LOW) {
        digitalWrite(LED_B, HIGH);
    } else {
        digitalWrite(LED_B, LOW);
    }

}