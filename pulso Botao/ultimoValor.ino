// coded by Isaque AL

// o objetivo deste codigo é inverter o estado do led quando receber um pulso do botão

const int writePin = 13;
const int readPin = 7;

bool ledState = false;
bool buttonState;
bool previousButtonState;
int buttonCliks = 0;

int buttonCounter ( int buttonCliks ) {
    buttonCliks += 1;
    Serial.print("vc clicou ");
    Serial.print(buttonCliks);
    Serial.println(" vezes ");
    return buttonCliks;
}

void setup() {
  Serial.begin(9600);
  pinMode(writePin, OUTPUT);
  pinMode(readPin, INPUT);
}

void loop() {
  buttonState = digitalRead(readPin);
  
  if (buttonState == 1 && previousButtonState == 0) {
    buttonCliks = buttonCounter(buttonCliks);
    ledState = !ledState;
  }

  previousButtonState = buttonState;
  digitalWrite(writePin, ledState);
}