#include <project.h>
#include "stepmotor.h"
#include "i2c.h"

#define BUFFER_SIZE 2u

uint16 steps = 0u;
uint16 position = 0u;

uint8 writeBuf[BUFFER_SIZE];

CY_ISR(ISR_STEP) 
{
    if (steps > position)
        --steps;
    else if (steps < position)
        ++steps;
}

int main(void)
{
    // Stepmotor
    Timer_Step_Start();
    isr_Step_StartEx(ISR_STEP);
    
    // I2C
    I2CS_I2CSlaveInitWriteBuf((uint8 *)writeBuf, BUFFER_SIZE);
    I2CS_Start();

        
    CyGlobalIntEnable;
    for(;;)
    {
        I2C_Read();
        position = writeBuf[0]*64*8;
        stepmotor();
    }
    
    return 0;
}

void stepmotor(void) 
{
    switch(steps % 8) 
    {
        case 0:
            ln_1_Write(1);
            ln_2_Write(0);
            ln_3_Write(0);
            ln_4_Write(0);
            break;
        case 1:
            ln_1_Write(1);
            ln_2_Write(1);
            ln_3_Write(0);
            ln_4_Write(0);
            break;
        case 2:
            ln_1_Write(0);
            ln_2_Write(1);
            ln_3_Write(0);
            ln_4_Write(0);
            break;
        case 3:
            ln_1_Write(0);
            ln_2_Write(1);
            ln_3_Write(1);
            ln_4_Write(0);
            break;
        case 4:
            ln_1_Write(0);
            ln_2_Write(0);
            ln_3_Write(1);
            ln_4_Write(0);
            break;
        case 5:
            ln_1_Write(0);
            ln_2_Write(0);
            ln_3_Write(1);
            ln_4_Write(1);
            break;
        case 6:
            ln_1_Write(0);
            ln_2_Write(0);
            ln_3_Write(0);
            ln_4_Write(1);
            break;
        case 7:
            ln_1_Write(1);
            ln_2_Write(0);
            ln_3_Write(0);
            ln_4_Write(1);
            break;
        default:
            break;
    }
}