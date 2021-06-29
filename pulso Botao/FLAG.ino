// coded by Isaque AL

// o objetivo deste codigo é inverter o estado do led quando receber um pulso do botão

const int writePin = 13;
const int readPin = 7;

bool ledState = false;
bool buttonState;

bool functionExec = false;

void setup()
{
  Serial.begin(9600);
  pinMode(writePin, OUTPUT);
  pinMode(readPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(readPin);
  
  if (buttonState == 1 && functionExec == false){
    functionExec = true;
    ledState = !ledState;// inverter o ledState

  } else if (buttonState == 0 && functionExec == true ) {
    functionExec = false;
  }

  digitalWrite(writePin, ledState);
}

// 4