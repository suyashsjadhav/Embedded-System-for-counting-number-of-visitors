#include "change_pass.h"

/*
Structure of header files (info abt which header file include which header file)

	** this type of multi-level includeing of header file is done to include accept_pass.h which is required in many other function
	
		
		-> LCD_mega128.h
		   	-> AVR/io.h
			
			
		-> accept_pass.h	
			-> LCD_mega128.h
			
	
	  -> display.h
			
			-> accept_pass.h

	
	  -> reset.h
			-> display.h


		-> change_pass.h
			-> reset.h


		-> main
			-> change_pass.h
			
	** Program accept passWord of 3 digit max count of system is 999999...
	PORTA pin A0 to A7 Input
	PORTB pin B0 to B5 Input  Pin B6 and B7 Output
	


*/


int main(void)
{
	count=0;			//Initalization of count and password count and password get reseted after Power cut of.....
	count2=0;
	password=0;
	DDRA=0x00;			//PORT A input
	DDRB=0xC0;			//PORT B B0 to B5 Input B6 n B7 Output
	PORTB=(PORTB|0xFF);	//Pullup register   and  B6 n B7 contineously ON as B6 is LASER and B7 connected to indcator led
	PORTA=(PORTA|0xFF);	//pullup register
	
	while(PINB & 0x20)							//until the diode pin 
	{
		if((PINB & 0x04)==0)					//if B2 is grounded calls reset operation
			reset();
		else
			if((PINB & 0x08)==0)
				display();						//if B3 is grounded calls display operation
			else
				if((PINB & 0x10)==0)
					change_pass();				//if B4 is grounded calls change_pass operation
	}
	count++;
	if(count==999)
	{	
		if(count2==999)			// Checks if count reaches value 999999 if yes then reset itself by showing msg on LCD
		{
			
			lcd_init();
		
			lcd_gotoxy1(0);
		
			lcd_string("Count reached its max value!!!");
		
			count=0;
			count2=0;
		}
		else
		{
			count=0;
			count2++;
		}
	}
	while((PINB & 0x20)==0);		// Wait till diode input pin changes its status.....


}