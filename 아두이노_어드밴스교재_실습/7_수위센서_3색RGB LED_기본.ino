int Sound_Sensor = A0;
int Sensor_val;
int LED_R = 4;
int LED_G = 3;
int LED_B = 2;

void setup() {
    pinMode(LED_R,OUTPUT);
    pinMode(LED_G,OUTPUT);
    pinMode(LED_B,OUTPUT);
}

void loop() {
    Sensor_val = analogRead(Sound_Sensor);
    if(Sensor_val <= 500) {
        digitalWrite(LED_R,LOW);
        digitalWrite(LED_G,HIGH);
        digitalWrite(LED_B,LOW);
    } else if(Sensor_val <= 600) {
        digitalWrite(LED_R,LOW);
        digitalWrite(LED_G,LOW);
        digitalWrite(LED_B,HIGH);
    } else {
        digitalWrite(LED_R,HIGH);
        digitalWrite(LED_G,LOW);
        digitalWrite(LED_B,LOW);
    }    
}