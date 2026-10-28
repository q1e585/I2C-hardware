#include "stm32f10x.h" 

#include "EEPROM.h"
#include "string.h"
#include "usart.h"


uint8_t str2[20]={0};

	  uint8_t str[20]="hello world ƒ„∫√ ¿ΩÁ";
int main(void)
{
	Int_Eeprom_Init();
	Dri_Usart_Init();

	uint8_t chr='A';
	// Dri_Usart_SendChr(chr);
	Int_Eeprom_Writebyte(chr,0x01);
	//  Int_Eeprom_Writebytes(chr,0x01,strlen(chr));

	Int_Eeprom_Readbyte(0x01);
	//  uint8_t str[20];
	// Int_Eeprom_Readebytes(str,0x01,3);
	// Dri_Usart_SendStr(str);
	


	while (1)
	{
	}
}


