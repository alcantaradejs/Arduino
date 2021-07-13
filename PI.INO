const byte botao  = 7;
bool botaoBool = 0;
int x;

void setup()
{
    pinMode(botao, INPUT);
    Serial.begin(9600);
} 

void loop()
{
    botaoBool = digitalRead(botao);
    if (botaoBool == 1)
    {
        x = x+1;
        Serial.println(x);
        delay(300);
    }
}
