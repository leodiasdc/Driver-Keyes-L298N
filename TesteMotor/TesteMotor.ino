#include <Preferences.h>

/*
Autor  : Leonardo Dias do Carmo
Data    : 13/01/2025
Descrição: Código simples para teste de funcionamento do Driver Keyes L298N
*/

#include <KeyesDriver.h>


void setup()
{
    Motor_Init();
    Serial.begin(9600);
}

void loop()
{
    Motor_Run(MOTORA, FORWARD, 50);
    Motor_Direction(MOTORA);
    delay(5000);
    Motor_Stop();
}