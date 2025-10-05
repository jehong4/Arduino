int LED_R = 2;
int LED_G = 4;
int LED_B = 6;

String inputString = "";  // 입력 저장용
bool inputComplete = false;

void setup() {
  Serial.begin(9600);

  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  rgb_on(0, 255, 0, 2000);
}

void loop() {
  if (inputComplete) {
    // 입력된 문자열 파싱
    int r, g, b, ontime;
    sscanf(inputString.c_str(), "%d %d %d %d", &r, &g, &b, &ontime);

    rgb_on(r, g, b, ontime);
    
    inputString = "";
    inputComplete = false;
  }
}

// Serial 입력 받기
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      inputComplete = true;
    } else {
      inputString += inChar;
    }
  }
}

// ontime : 유지시간
void rgb_on(int R, int G, int B, int ontime) {
  analogWrite(LED_R, R);
  analogWrite(LED_G, G);
  analogWrite(LED_B, B);
  delay(ontime);
  rgb_off();
}

void rgb_off() {
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 0);
  analogWrite(LED_B, 0); 
}