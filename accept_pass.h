#include "LCD_mega128.h"	//LCD display functions
unsigned char count,count2,password;		//Global variables used for storing PassWord and Count of visitors .
		
// Function for accepting PassWord.....
/*
	PORT A pins 0 to 7 and PORT B 0 and 2 pins are used to accept pass-word
	A0="0"
	A1="1"
	A2="2"
	A3="3"
	A4="4"
	A5="5"
	A6="6"
	A7="7"
	B0="8"
	B1="9"

  */
unsigned char accept_pass(void)
{
	unsigned char i=0,temp=0;
	
	while(i<3)
	{
		while((PINA==0xFF)&&((!(PINB & 0x03))==0));
		if(PINA==0xFE)
		{
			temp=(temp*10)+0;
			while(!PINA);
		}
		if(PINA==0xFD)
		{
			temp=(temp*10)+1;
			while(!PINA);
		}
		if(PINA==0xFB)
		{
			temp=(temp*10)+2;
			while(!PINA);
		}
		if(PINA==0xF7)
		{
			temp=(temp*10)+3;
			while(!PINA);
		}
		if(PINA==0xEF)
		{
			temp=(temp*10)+4;
			while(!PINA);
		}
		if(PINA==0xDF)
		{
			temp=(temp*10)+5;
			while(!PINA);
		}
		if(PINA==0xBF)
		{
			temp=(temp*10)+6;
			while(!PINA);
		}
		if(PINA==0x7F)
		{
			temp=(temp*10)+7;
			while(!PINA);
		}
		if((PINB & 0x03)==0x02)
		{
			temp=(temp*10)+8;
			while((PINB & 0x03)!=0x03);
		}
		if((PINB & 0x03)==0x01)
		{
			temp=(temp*10)+9;
			while((PINB & 0x03)!=0x03);
		}
		i++;
	}
	return(temp);
}