int LED_R = 2;
int LED_G = 4;
int LED_B = 6;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);


}

void loop() {
  // 호출
  rgb_on(255, 255, 255, 3000);
  rgb_off(0, 0, 0, 100);

}

// 정의
void rgb_on(int R, int G, int B, int ontime) {
  // 호출
  analogWrite(LED_R, R);
  delay(3000);
  analogWrite(LED_G, G);
  delay(3000);
  analogWrite(LED_B, B);

  delay(ontime);
}

// 정의
// 정의
void rgb_off(int R, int G, int B, int ontime) {

  analogWrite(LED_R, R);
  analogWrite(LED_G, G);
  analogWrite(LED_B, B);

  delay(ontime);
}