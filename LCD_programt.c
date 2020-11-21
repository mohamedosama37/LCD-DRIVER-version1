#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "Delay.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"











void LCD_voidInitalize (void)
{
	
  delay_ms(40);
  LCD_voidWriteCommand(0b00111000);
  delay_ms(2);
  LCD_voidWriteCommand(0b00001100);
  delay_ms(2);
  LCD_voidWriteCommand(0b00000001);
  delay_ms(10);
	
	
}	




u8 LCD_voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_ErrorState=0;
	DIO_u8SetPinValue (RS_PIN  , COMMAND_MODE );
    DIO_u8SetPinValue (RW_PIN  , LCD_u8_WRITE ); 
    DIO_u8SetPinValue (	d0 ,  get_bit(Copy_u8Command,0)  );
	DIO_u8SetPinValue (	d1 ,  get_bit(Copy_u8Command,1)  );
	DIO_u8SetPinValue (	d2 ,  get_bit(Copy_u8Command,2)   );
	DIO_u8SetPinValue (	d3 ,  get_bit(Copy_u8Command,3)   );
	DIO_u8SetPinValue (	d4 ,  get_bit(Copy_u8Command,4)   );
	DIO_u8SetPinValue (	d5 ,  get_bit(Copy_u8Command,5)   );
	DIO_u8SetPinValue (	d6 ,  get_bit(Copy_u8Command,6)   );
	DIO_u8SetPinValue (	d7 ,  get_bit(Copy_u8Command,7)   );
	DIO_u8SetPinValue  (E_PIN,ENABLE);
	delay_ms(2);
	DIO_u8SetPinValue   (E_PIN,DISENABLE);
	
	
	return Local_ErrorState;
	
}


u8 LCD_VoidWriteData   (u8 Copy_u8Data)
{
	
	u8 Local_ErrorState=0;
	DIO_u8SetPinValue (RS_PIN  , DATA_MODE );
    DIO_u8SetPinValue (RW_PIN  , LCD_u8_WRITE ); 

    DIO_u8SetPinValue (	d0 ,  get_bit(Copy_u8Data,0)    );
	DIO_u8SetPinValue (	d1 ,  get_bit(Copy_u8Data,1)  );
	DIO_u8SetPinValue (	d2 ,  get_bit(Copy_u8Data,2)   );
	DIO_u8SetPinValue (	d3 ,  get_bit(Copy_u8Data,3)   );
	DIO_u8SetPinValue (	d4 ,  get_bit(Copy_u8Data,4)    );
	DIO_u8SetPinValue (	d5 ,  get_bit(Copy_u8Data,5)   );
	DIO_u8SetPinValue (	d6 ,  get_bit(Copy_u8Data,6)   );
	DIO_u8SetPinValue (	d7 ,  get_bit(Copy_u8Data,7)   );


	DIO_u8SetPinValue  (E_PIN,ENABLE);
	delay_ms(2);
	DIO_u8SetPinValue  (E_PIN,DISENABLE);
	
	
	return Local_ErrorState;
	
}
