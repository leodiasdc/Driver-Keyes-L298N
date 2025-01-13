/*****************************************************************************
* | File        :   KeyesDriver.cpp
* | Author      :   Leonardo Dias do Carmo
* | Function    :   Drive Keyes L298N
*----------------
* |	This version:   V1.0
* | Date        :   2025-10-01
* | Info        :   Versão Básica
*
******************************************************************************/

#include "KeyesDriver.h"
#include "DEV_Config.h"

UWORD ain1_value, ain2_value; 
UWORD bin1_value, bin2_value;

void Motor_Init(void)
{
    pinMode(PINO_IN0, OUTPUT);  // Define o pino IN0 como saída
    pinMode(PINO_IN1, OUTPUT);  // Define o pino IN1 como saída
    pinMode(PINO_IN2, OUTPUT);  // Define o pino IN2 como saída
    pinMode(PINO_IN3, OUTPUT);  // Define o pino IN3 como saída
}

void Motor_Run(UBYTE motor, DIR dir, UWORD speed)
{   
    double pwmSpeed; 

    if(speed > 100)
        speed = 100;

    pwmSpeed = speed*(255.0/100.0); 

    if(motor == MOTORA) {
        DEBUG("Velocidade do Motor A = %d\r\n", speed);
        if(dir == FORWARD) {
            DEBUG("Frente..\r\n");
            analogWrite(PINO_IN1, pwmSpeed);    
            analogWrite(PINO_IN0, 0);    
            ain1_value = 0;
            ain2_value = 1;
        } else {
            DEBUG("Ré...\r\n");
            analogWrite(PINO_IN1, 0);    
            analogWrite(PINO_IN0, pwmSpeed);
            ain1_value = 1;
            ain2_value = 0;
        }
    } else {
        DEBUG("Velocidade do Motor B = %d\r\n", speed);
        if(dir == FORWARD) {
            DEBUG("Frente...\r\n");
            analogWrite(PINO_IN2, pwmSpeed);    
            analogWrite(PINO_IN3, 0);    
            bin1_value = 0;
            bin2_value = 1;
        } else {
            DEBUG("Ré...\r\n");
            analogWrite(PINO_IN2, 0);    
            analogWrite(PINO_IN3, pwmSpeed);
            bin1_value = 1;
            bin2_value = 0;
        }
    }
}

void Motor_Stop(UBYTE motor)
{
    if (motor == MOTORA){
        analogWrite(PINO_IN0, 0);
        analogWrite(PINO_IN1, 0); 
    }
    else if (motor == MOTORB){
        analogWrite(PINO_IN2, 0);
        analogWrite(PINO_IN3, 0);
    }
}

UBYTE Motor_Direction(UBYTE motor)
{
    if(motor == MOTORA) {
        if(ain1_value == 0 && ain2_value == 1)
            return 1;
        else if(ain1_value == 1 && ain2_value == 0)
            return 0;
    }
    else if (motor == MOTORB) {
        if(bin1_value == 0 && bin2_value == 1)
            return 1;
        else if(bin1_value == 1 && bin2_value == 0)
            return 0;
    }
}
