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

bool previousButtonState[] = {0, 0};
int gateState[] = {0, 0} ;
int previousGateState[] = {0, 0};

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

    gateState[0] = sensorListener(0, gateState[0]);
    gateState[1] = sensorListener(1, gateState[1]);

    controlePortao(0, gateState[0]);
    controlePortao(1, gateState[1]);

    delay(1500); // apenas para simulacao

}

int sensorListener(int gate, int gateState) {
    int buttonState = digitalRead(BT[gate]);
    int closedGate = digitalRead(SF[gate]);
    int openGate = digitalRead(SA[gate]);

    if ( buttonState && !previousButtonState[gate]) {
        if (closedGate) {
            gateState = 1;
        } else if (openGate) {
            gateState = 2;
        }
        previousGateState[gate] = gateState;
    } else if (buttonState && !previousButtonState[gate] && !closedGate && !openGate) {
        if (gateState != 0) {
            gateState = 0;
        } else {
            gateState = previousGateState[gate] == 1? 2 : 1;
            previousGateState[gate] = gateState ;
        }
    } else if ((openGate || closedGate) && !buttonState) {
        gateState = 0;
        previousGateState[gate] = gateState;
    }

    previousButtonState[gate] = buttonState ;
    return gateState;
}

void controlePortao(int gate, int gateState) { // 1 - abrindo, 2 - fechando, 0 - parado
    switch (gateState) {
        case 0:
            digitalWrite(MA[gate], false);
            digitalWrite(MF[gate], false);
            break;
        case 1:
            digitalWrite(MA[gate], true);
            digitalWrite(MF[gate], false);
            break;
        case 2:
            digitalWrite(MA[gate], false);
            digitalWrite(MF[gate], true);
            break;
    }
}