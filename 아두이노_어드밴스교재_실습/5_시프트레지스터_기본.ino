int dataPin = 2;        // 74HC595의 SER핀
int clockPin = 3;       // 74HC595의 SRCLK핀 
int latchPin = 4;       // 74HC595의 RCLK핀 

void setup() {
    Serial.begin(9600);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
}

void loop() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(latchPin, LOW);                        // 래치 비활성화
        shiftOut(dataPin, clockPin, MSBFIRST, 1 << i);      // 왼쪽으로 1이동
        Serial.println(1 << i, BIN);
        digitalWrite(latchPin, HIGH);                       // 래치 활성화
        delay(1000);     
    }
    // delay(500);
    digitalWrite(latchPin,LOW);                             // 래치 비활성화
    shiftOut(dataPin, clockPin, MSBFIRST, 0b00000000);      // 모든 LED OFF
    digitalWrite(latchPin, HIGH);                           // 래치 활성화
    delay(500);
}