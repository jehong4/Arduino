char character;

void setup() {
    Serial.begin(9600);
    Serial.println("Jinseo is stupid");
}

void loop() {
    if (Serial.available()) {
        character = Serial.read();

        if (character == '1') {
            Serial.println("You entered 1!!");
        } else if (character == '2') {
            Serial.println("WOW! It's 2!");
        } else {
            Serial.println("Please enter 1 or two");
        }
    } else {
        // Serial.println("NA");
    }
}