// Definições GLOBAIS
// Todas as definições feitas aqui (fora do ESCOPO de qualquer função) será global - visível por TODAS as funções 
const byte LED1 = 13;
const byte LED2 = 12; 
const byte BOTAO1 = 7;
const byte BOTAO2 = 6;

bool button1State;
bool button2State;


void setup() {
    Serial.begin(9600);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(BOTAO1, INPUT); 
    pinMode(BOTAO2, INPUT); 
}

void loop() {
  
    button1State = digitalRead(BOTAO1);
    button2State = digitalRead(BOTAO2);

    if (button1State == 1 && button2State == 1) {
        Serial.println("botao1precionado");
        digitalWrite(LED1, HIGH);
    } else {
        digitalWrite(LED1, LOW);
    }

    if (button1State == 1 || button2State == 1) {
        Serial.println("botao2precionado");
        digitalWrite(LED2, HIGH);
    } else {
        digitalWrite(LED2, LOW);
    }
}