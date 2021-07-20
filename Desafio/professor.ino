/* =====================================================================
                        INSTITUTO FEDERAL DE SERGIPE
                             CURSO DE ELETRÔNICA
    ---------------------------------------------------------------------
    Disciplina: Sistemas Programáveis
    Professor : Fábio Prudente
    ---------------------------------------------------------------------
    Descrição : Controle para Portão Automático
    =====================================================================
*/

const int BT[] = {7, 4};      // Botão de Acionamento
const int SA[] = {6, 3};      // Sensor: Portão Aberto
const int SF[] = {5, 2};      // Sensor: Portão Fechado
const int MA[] = {13, 11};    // Motor: Acionar no sentido de Abrir
const int MF[] = {12, 10};    // Motor: Acionar no sentido de Fechar

int gateState[] = {0, 0};// 1 - abrindo, 2 - fechando, 0 - parado

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 2; i++) {
    pinMode (BT[i], INPUT);
    pinMode (SA[i], INPUT);
    pinMode (SF[i], INPUT);
    pinMode (MA[i], OUTPUT);
    pinMode (MF[i], OUTPUT);
  }
}

void loop() {

  gateState[0] = sensorListener(0);
  gateState[1] = sensorListener(1);

  controlePortao(0, 0);

  delay (1000); // necessário somente para melhorar a simulação
}

int sensorListener(int gate) {
  int buttonState = digitalRead(BT[gate]);
  int closedGate = digitalRead(SF[gate]);
  int openGate = digitalRead(SA[gate]);

  /*
  Serial.print(buttonState);
  Serial.print(openGate);
  Serial.println(closedGate);
  */

  return 0;
}

void controlePortao(int gate, int gateState) { //debugar!
  Serial.println(gateState);
  switch (gateState) {
    case 0:
      digitalWrite(MA[gate], false);
      digitalWrite(MF[gate], false);
    case 1:
      digitalWrite(MA[gate], true);
      digitalWrite(MF[gate], false);
    case 2:
      digitalWrite(MA[gate], false);
      digitalWrite(MF[gate], true);
  }
}