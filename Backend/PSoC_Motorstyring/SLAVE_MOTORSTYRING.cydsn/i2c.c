#include "i2c.h"

void I2C_Read(void) {
    uint32 status;
    
    /* Wait for the write (from master) to finish */
    status = I2CS_I2CSlaveStatus();
    if (0u != (status & I2CS_I2C_SSTAT_WR_CMPLT)) {
        /* Clean-up status and buffer pointer */
        I2CS_I2CSlaveClearWriteStatus();
        I2CS_I2CSlaveClearWriteBuf();
    }
}