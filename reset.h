#include "display.h"

void reset(void)
{
	lcd_init();
	
	lcd_gotoxy1(0);

	lcd_string("Enter PassWord");
	
	if(accept_pass()==password)					//Checks password for secured pass to stored data
	{
		count=0;
		count2=0;
		
		lcd_gotoxy1(0);

		lcd_string("Counter reseted");

	}
	else
	{
		
		lcd_gotoxy1(0);

		lcd_string("Wrong PassWord");

	}
}
