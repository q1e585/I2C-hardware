#include "stm32f10x.h" 

#include "EEPROM.h"
#include "string.h"
#include "usart.h"


char str2[20];

int main(void)
{
	 uint8_t str[20]="hello world ÄãºÃ";
	Int_Eeprom_Init();
	Dri_Usart_Init();
	Int_Eeprom_Writebyte(str,0x00,strlen(str));
	Int_Eeprom_Readebyte(str2,0x06,8);

	while (1)
	{
	}
}


