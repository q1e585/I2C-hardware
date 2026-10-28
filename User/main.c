#include "stm32f10x.h" 





char str2[20];

	  uint8_t str[20]="hello world ???????";
int main(void)
{
	 uint8_t str[20]="hello world ???";
	Int_Eeprom_Init();
	Dri_Usart_Init();
	Int_Eeprom_Writebyte(str,0x00,strlen(str));
	Int_Eeprom_Readebyte(str2,0x06,8);

	while (1)
	{
	}
}


