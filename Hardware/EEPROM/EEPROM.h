#ifndef _EEPROM_H
#define _EEPROM_H

#include "I2C.h"

void Int_Eeprom_Init(void);

void Int_Eeprom_Writebyte( uint8_t byte[], uint8_t address,uint8_t len);


void Int_Eeprom_Readebyte(uint8_t byte[], uint8_t address,uint8_t len);




#endif /* _EEPROM_H */


