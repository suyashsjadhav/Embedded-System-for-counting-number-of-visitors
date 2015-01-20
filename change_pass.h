#include "reset.h"

// Function for Chanding PassWord....
void change_pass(void)
{
	

	lcd_init();
	
	lcd_gotoxy1(0);

	lcd_string("Enter Old password:"); // Ask for old password so authoruzed person can cahange the PassWord
	


	if(accept_pass()==password)
	{
		lcd_gotoxy1(0);

		lcd_string("Enter New password:");

		
		password=accept_pass();					//Accept new PassWord...

		
		lcd_gotoxy1(0);

		lcd_string("New Password Set!!!");

		
		return;
		
	}
	else
	{
		lcd_gotoxy1(0);

		lcd_string("Wrong password!!!");
	
	}
}