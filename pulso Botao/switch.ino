// coded by Isaque Alcantara

const int writePin = 13;
const int readPin = 7;

bool ledState = false;
int buttonState;
bool previousButtonState = 0;

void setup() {
  pinMode(writePin, OUTPUT);
  pinMode(readPin, INPUT);
}

void loop() {

    buttonState = digitalRead(readPin);

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
    digitalWrite(writePin, ledState);

}
