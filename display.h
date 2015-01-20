
#include "accept_pass.h"	//Accepts passWord from user and return a unsigned double char value
void display(void)
{
	lcd_init();
	
	lcd_gotoxy1(0);

	lcd_string("Enter PassWord:");
	
	if(accept_pass()==password)				// Ask for PassWord for authorised access to data...
	{
		lcd_showvalue(count2);
		lcd_showvalue(count);
	}
	else
	{
			
		lcd_gotoxy1(0);
			
		lcd_string("Wrong PassWord!!!");

	}
	return;
}