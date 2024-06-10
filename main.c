
#include <avr/io.h>
#include "lcd.h"
#include "HC-SR04.h"
#include "std_types.h"

int main(void)
{
	SREG|=(1<<7);
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("   OMAR TALAAT");
	LCD_moveCursor(1,0);
	LCD_displayString("Distance = ");
	LCD_moveCursor(1,14);
	LCD_displayString("cm");
	uint16 dis=0;

	while(1)
	{
		dis = Ultrasonic_readDistance();
		LCD_moveCursor(1,11);
		LCD_intgerToString(dis);
		if(dis<100)LCD_displayCharacter(' ');
		if (dis<20)
		{
			LCD_moveCursor(2,0);
			LCD_displayString("     Stop!!     ");
			LCD_moveCursor(3,0);
			LCD_displayString("   Too Close!   ");

		}
		else if (dis<50)
		{
			LCD_moveCursor(2,0);
			LCD_displayString("    Warning!    ");
			LCD_moveCursor(3,0);
			LCD_displayString(" Close Distance ");
		}
		else
		{
			LCD_moveCursor(2,0);
			LCD_displayString("                ");
			LCD_moveCursor(3,0);
			LCD_displayString("                ");
		}
	}

}




