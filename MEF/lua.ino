const int ledGreen = 13;
const int ledYellow = 12;
const int ledRed = 11;
int currentLED = 1;

const int buttonRight = 8;
const int buttonLeft = 7;

bool buttonRightState = 0;
bool buttonLeftState = 0;
bool previousRightButtonState = 0;
bool previousLeftButtonState = 0;

void setup() {
    pinMode(buttonRight, INPUT);
    pinMode(buttonLeft, INPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(ledYellow, OUTPUT);
    pinMode(ledRed, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    buttonRightState = digitalRead(buttonRight);
    buttonLeftState = digitalRead(buttonLeft);

    if (buttonRightState && !previousRightButtonState && currentLED < 3) {
        currentLED++ ;
        Serial.print("currentLED: ");
        Serial.println(currentLED);
    }
    
    if (buttonLeftState && !previousLeftButtonState && currentLED > 1) {
        currentLED-- ;
        Serial.print("currentLED: ");
        Serial.println(currentLED);
    }

    switch (currentLED)
    {
    case 1:
        digitalWrite(ledGreen, 1);
        digitalWrite(ledYellow, 0);
        digitalWrite(ledRed, 0);
        break;
        
    case 2:
        digitalWrite(ledGreen, 0);
        digitalWrite(ledYellow, 1);
        digitalWrite(ledRed, 0);
        break;

    case 3:
        digitalWrite(ledGreen, 0);
        digitalWrite(ledYellow, 0);
        digitalWrite(ledRed, 1);
        break;
    
    }

    previousRightButtonState = buttonRightState;
    previousLeftButtonState = buttonLeftState;
}