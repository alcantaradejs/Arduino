// coded by Isaque AL
// o objetivo deste codigo é inverter o estado do led quando receber um pulso do botão

const int pinOut = 13;
bool pinState = 0;

void setup() {
  pinMode(pinOut, OUTPUT);
}

void loop() {
    digitalWrite(13, 1);
    delay(500);
    digitalWrite(13, 0);
}