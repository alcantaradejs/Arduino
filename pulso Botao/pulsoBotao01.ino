// coded by Isaque AL

// o objetivo deste codigo é inverter o estado do led quando receber um pulso do botão

const int writePin = 13;
const int readPin = 5;

bool ledState = false;
bool buttonState;

void setup()
{
  Serial.begin(9600);
  pinMode(writePin, OUTPUT);
  pinMode(readPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(readPin);
  if (buttonState == 1){
    while (digitalRead(readPin) == 1) {}
    ledState = !ledState;// inverter o ledState
  }
  
  if (ledState == 1){
    Serial.println("[+] Led ligado");
  	digitalWrite(writePin, HIGH);
  } else {
    Serial.println("[+] Led desligado");
  	digitalWrite(writePin, LOW); 
  }
}