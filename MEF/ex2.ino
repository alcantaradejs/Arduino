// coded by @B4tataFitas

const int LED = 13;
const int button = 7;

bool ledState = false;
bool buttonState = false;
bool previousButtonState = false;
int buttonCounter = 0;

void setup() {
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    pinMode(button, INPUT);
}

int buttonActionCounter(int buttonCounter) {
    buttonCounter++ ;
    Serial.print("[+] voce clicou ");
    Serial.print(buttonCounter);
    Serial.println(" vezes");
    return buttonCounter;
}

void loop() {

    buttonState = digitalRead(button);

    switch (buttonState) {
    case 1:
        if (previousButtonState == 0) {
            buttonCounter = buttonActionCounter(buttonCounter);
            ledState = !ledState;// solução 1.exercicio
        }
        break;
    
    default:
        break;
    }

    previousButtonState = buttonState;
    digitalWrite(LED, ledState);

}