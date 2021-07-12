// coded by @B4tataFitas

const int LED = 13;
const int button = 7;

bool ledState = false;
bool buttonState = false;

void setup() {
    Serial.begin(9600)
    pinMode(LED, OUTPUT);
    pinMOde(button, INPUT);
}

void loop() {

    buttonState = digitalRead(button);

    switch (buttonState) {
    case 1:
        if (previousButtonState == 0) {
            ledState = !ledState;
        }
        break;
    
    default:
        break;
    }

    previousButtonState = buttonState;
    digitalWrite(LED, ledState);

}