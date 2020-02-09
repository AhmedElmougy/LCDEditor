/*
 * File        : HLCD_Interface.h
 * Description : This interface file includes LCD editor application for Atmega32
 *				 you can write and edit a string displayed on LCD using a key pad
 *				 you can navigate through the line using two buttons and erase using a third one
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 9/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */




#include "LSTD_Types.h"
#include "LUTILS.h"
#include "LDELAY_Interface.h"
#include "MDIO_Interface.h"
#include "HKPD_Interface.h"
#include "HLCD_Interface.h"


int main(void)
{
	/*global variables*/
	volatile u8 character=' ',Data=' ';
	
	/*Initialize LCD*/    
	HLCD_voidInitializeLCD();
	/*Initialize Keypad*/
	HKPD_voidInitializeKeypad();
	
	HLCD_voidDisplayString("Write & Edit :",HLCD_STRING); // display welcome on first line
	HLCD_voidSelectLine(HLCD_LINE2);
	
	while (1) 
    {
		/*read inputed character*/
		character=HKPD_u8GetPressedKey();
		
		/*if any button pressed*/
		if(character!='?')
		{
			/*if number was pressed*/
			if((character>=0)&&(character<10))
			{
				Data=character+'0';
				HLCD_voidDisplayChar(Data);
				LDelay_voidDelay_ms(500);	
			}
			/*Move left*/
			else if(character=='#')
			{
				HLCD_voidCursorShiftLeft(1);
				LDelay_voidDelay_ms(500);	
			}
			/*Move right*/
			else if(character=='*')
			{
				HLCD_voidCursorShiftRight(1);
				LDelay_voidDelay_ms(500);	
			}
			/*erase character*/
			else if(character=='D')
			{
				HLCD_voidDisplayChar(' ');
				LDelay_voidDelay_ms(500);
			}
			/*Display pressed char*/
			else
			{
				Data=character;
				HLCD_voidDisplayChar(Data);
				LDelay_voidDelay_ms(500);
			
			}/*end of character type check*/
		
		}/*end of key pressed check*/
    
	}/*end of nfinite loop*/

}/*end of main()*/

