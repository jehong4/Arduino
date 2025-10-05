int led0_pin = 2;
int button0_pin = 3;

bool ledState = false;           // 현재 LED 상태
bool prevButtonState = LOW;      // 이전 버튼 상태

void setup() {
  pinMode(led0_pin, OUTPUT);
  pinMode(button0_pin, INPUT);   // 외부 풀다운 저항 사용 중이므로 INPUT 모드

  digitalWrite(led0_pin, LOW);   // LED 초기 상태 OFF

  Serial.begin(9600);
}

void loop() {
  bool currentButtonState = digitalRead(button0_pin);

  // 버튼이 LOW → HIGH로 변할 때 (즉, 버튼을 누르는 순간)
  if (currentButtonState == HIGH && prevButtonState == LOW) {
    ledState = !ledState;  // LED 상태 토글
    digitalWrite(led0_pin, ledState ? HIGH : LOW);  // LED 상태 반영

    Serial.print("LED 상태: ");
    Serial.println(ledState);

    delay(50);  // 간단한 디바운싱
  }

  prevButtonState = currentButtonState;  // 이전 상태 갱신
}
