int LED_R = 2;
int LED_G = 4;
int LED_B = 6;

int DELAY_TIME = 1000;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);


}

void loop() {
  // 호출
  rgb_on(255, 255, 255, 1500);

}

// 정의
void rgb_on(int R, int G, int B, int ontime) {

  // 호출
  analogWrite(LED_R, R);
  delay(ontime);
  rgb_off();

  analogWrite(LED_G, G);
  delay(ontime);
  rgb_off();

  analogWrite(LED_B, B);
  delay(ontime);
  rgb_off();
}

// 정의
void rgb_off() {
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 0);
  analogWrite(LED_B, 0);
  delay(DELAY_TIME);

}