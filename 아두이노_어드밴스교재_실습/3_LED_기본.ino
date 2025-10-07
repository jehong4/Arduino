int led0_pin=2;
int button0_pin=3;

void setup() {
  // put your setup code here, to run once:

  pinMode(led0_pin, OUTPUT);
  pinMode(button0_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(button0_pin) == LOW) {
    digitalWrite(led0_pin, HIGH);
  } else { 
    digitalWrite(led0_pin, LOW);
  }
  
  Serial.print("LED 상태: ");
  Serial.println(digitalRead(led0_pin));
}