/*
 * Dio.c
 *
 * Created: 11/6/2019 10:23:17 PM
 *  Author: AVE-LAP-025
 */ 

#include "Dio.h"
#include "Std_Types.h"

/**
 * 	
 *	This file is a source file that contains MCAL functions'
 *	prototypes and description.
 */

/*===========================PORT Control===============================*/

/*Configure the direction of the whole port*/

void gpioPortDirection(uint8 port, uint8 direction)
{
	switch(port)
	{
		
		case PORTA:
		PORTA_DIR = direction;
		break;
		
		case PORTB:
		PORTB_DIR = direction;
		break;
		
		case PORTC:
		PORTC_DIR = direction;
		break;
		
		case PORTD:
		PORTD_DIR = direction;
		break;
		
		default:
		break;
	}
}

/*Write to the whole port*/

void gpioPortWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		case PORTA:
		PORTA_DATA = value;
		break;
		
		case PORTB:
		PORTB_DATA = value;
		break;
		
		case PORTC:
		PORTC_DATA = value;
		break;
		
		case PORTD:
		PORTD_DATA = value;
		break;
		
		default:
		break;
	}
}

/*Toggle the whole port after the user sets the direction of port*/

void gpioPortToggle(uint8 port)
{
	switch(port)
	{
		case PORTA:
		PORTA_DATA ^= 0xff;
		break;
		
		case PORTB:
		PORTB_DATA ^= 0xff;
		break;
		
		case PORTC:
		PORTC_DATA ^= 0xff;
		break;
		
		case PORTD:
		PORTD_DATA ^= 0xff;
		break;
		
		default:
		break;
	}
}

/*Read the whole port*/

uint8 gpioPortRead(uint8 port)
{
	switch(port)
	{
		case PORTA:
		return PORTA_PIN;
		break;
		
		case PORTB:
		return PORTB_PIN;
		break;
		
		case PORTC:
		return PORTC_PIN;
		break;
		
		case PORTD:
		return PORTD_PIN;
		break;
		
		default:
		return -1;
		break;
	}
}

/*===========================PIN Control===============================*/

/*set direction of  certain pins in certain port*/

void gpioPinDirection(uint8 port, uint8 pins, uint8 direction){
	
	switch(port)
	{
		case PORTA:
		if(direction == OUTPUT)
		{
			PORTA_DIR |= (pins);
		}
		else
		{
			PORTA_DIR &=~ (pins);
		}
		break;
		
		case PORTB:
		if(direction == OUTPUT)
		{
			PORTB_DIR |= (pins);
		}
		else
		{
			PORTB_DIR &=~ (pins);
		}
		break;
		
		case PORTC:
		if(direction == OUTPUT)
		{
			PORTC_DIR |= (pins);
		}
		else
		{
			PORTC_DIR &=~ (pins);
		}
		break;
		
		case PORTD:
		if(direction == OUTPUT)
		{
			PORTD_DIR |= (pins);
		}
		else
		{
			PORTD_DIR &=~ (pins);
		}
		break;
	}
} 

/*write a certain value either 1 or 0 in certain pins*/

void gpioPinWrite(uint8 port, uint8 pins, uint8 value)
{
	switch(port)
	{
		case PORTA:
		if(value == HIGH)
		{
			PORTA_DATA |= (pins);
		}
		else
		{
			PORTA_DATA &=~ (pins);
		}
		break;
		
		case PORTB:
		if(value == HIGH)
		{
			PORTB_DATA |= (pins);
		}
		else
		{
			PORTB_DATA &=~ (pins);
		}
		break;
		
		case PORTC:
		if(value == HIGH)
		{
			PORTC_DATA |= (pins);
		}
		else
		{
			PORTC_DATA &=~ (pins);
		}
		break;
		
		case PORTD:
		if(value == HIGH)
		{
			PORTD_DATA |= (pins);
		}
		else
		{ 
			PORTD_DATA &=~ (pins);
		}
		break;
	}
}

/*toggle certain pins in certain port */

void gpioPinToggle(uint8 port, uint8 pins)
{
	switch(port)
	{
		case PORTA:
		PORTA_DATA ^= (pins);
		break;
		
		case PORTB:
		PORTB_DATA ^= (pins);
		break;
		
		case PORTC:
		PORTC_DATA ^= (pins);
		break;
		
		case PORTD:
		PORTD_DATA ^= (pins);
		break;
	}
}

/*Read certain pin value in certain port */

uint8 gpioPinRead(uint8 port, uint8 pin)
{
	switch(port)
	{
		
		case PORTA:
		return (READ_BIT(PORTA_PIN,pin))>>pin;
		break;
		
		case PORTB:
		return (READ_BIT(PORTB_PIN,pin))>>pin;
		break;
		
		case PORTC:
		return (READ_BIT(PORTC_PIN,pin))>>pin;
		break;
		
		case PORTD:
		return (READ_BIT(PORTD_PIN,pin))>>pin;
		break;
		
		default:
		return -1;
		break;
	}
	
}

/*===========================Upper Nibble Control===============================*/

/*set the direction of upper nibble  */

void gpioUpperNibbleDirection(uint8 port, uint8 direction)
{
	switch(port)
	{
		
		case PORTA:
		if(direction == OUTPUT)
		{
			PORTA_DIR = (PORTA_DIR&0x0f)|0xf0;
		}
		else
		{
			PORTA_DIR = PORTA_DIR&0x0f;
		}
		break;
		
		case PORTB:
		if(direction == OUTPUT)
		{
			PORTB_DIR = (PORTB_DIR&0x0f)|0xf0;
		}
		else
		{
			PORTB_DIR = PORTB_DIR&0x0f;
		}
		break;
		
		case PORTC:
		if(direction == OUTPUT)
		{
			PORTC_DIR = (PORTC_DIR&0x0f)|0xf0;
		}
		else
		{
			PORTC_DIR = PORTC_DIR&0x0f;
		}
		break;
		
		case PORTD:
		if(direction == OUTPUT)
		{
			PORTD_DIR = (PORTD_DIR&0x0f)|0xf0;
		}
		else
		{
			PORTD_DIR = PORTD_DIR&0x0f;
		}
		break;
	}
}

/*write certain value in upper nibble */

void gpioUpperNibbleWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		
		case PORTA:
		
		if(value == HIGH)
		{
			PORTA_DATA = (PORTA_DATA&0x0f)|0XF0;
		}
		else{
			PORTA_DATA = PORTA_DATA&0x0f;
		}
		break;
		
		case PORTB:
		if(value == HIGH)
		{
			PORTB_DATA = (PORTB_DATA&0x0f)|0XF0;
		}
		else
		{
			PORTB_DATA = PORTB_DATA&0x0f;
		}
		break;
		
		case PORTC:
		if(value == HIGH)
		{
			PORTC_DATA = (PORTC_DATA&0x0f)|0XF0;
		}
		else
		{
			PORTC_DATA = PORTC_DATA&0x0f;
		}
		
		break;
		case PORTD:
		if(value == HIGH)
		{
			PORTD_DATA = (PORTD_DATA&0x0f)|0XF0;
		}
		else
		{
			PORTD_DATA = PORTD_DATA&0x0f;
		}

		break;
	}
}

/*toggle upper nibble */

void gpioUpperNibbleToggle(uint8 port)
{
	switch(port)
	{
		case PORTA:
		PORTA_DATA ^= 0xf0;
		break;
		
		case PORTB:
		PORTB_DATA ^= 0xf0;
		break;
		
		case PORTC:
		PORTC_DATA ^= 0xf0;
		break;
		
		case PORTD:
		PORTD_DATA ^= 0xf0;
		break;
	}
}

/*read upper nibble of certain port */

uint8 gpioUpperNibbleRead(uint8 port)
{
	switch(port)
	{
		case PORTA:
		return (PORTA_PIN&0xf0)>>4;
		break;
		
		case PORTB:
		return (PORTB_DATA&0xf0)>>4;
		break;
		
		case PORTC:
		return (PORTC_PIN&0xf0)>>4;
		break;
		
		case PORTD:
		return (PORTD_PIN&0xf0)>>4;
		break;
		
		default:
		return -1;
		break;
	}
}

/*===========================Lower Nibble Control===============================*/

/*set direction of lower nibble of certain port */

void gpioLowerNibbleDirection(uint8 port, uint8 direction)
{
	switch(port)
	{
		
		case PORTA:
		if(direction == OUTPUT)
		{
			PORTA_DIR = PORTA_DIR|0x0f;
		}
		else
		{
			PORTA_DIR = PORTA_DIR&0xf0;
		}
		break;
		
		case PORTB:
		if(direction == OUTPUT)
		{
			PORTB_DIR = PORTB_DIR|0x0f;
		}
		else{
			PORTB_DIR = PORTB_DIR&0xf0;
		}
		break;
		
		case PORTC:
		if(direction == OUTPUT)
		{
			PORTC_DIR = PORTC_DIR|0x0f;
		}
		else{
			PORTC_DIR = PORTC_DIR&0xf0;
		}
		break;
		
		case PORTD:
		if(direction == OUTPUT)
		{
			PORTD_DIR = PORTD_DIR|0x0f;
		}
		else
		{
			PORTD_DIR = PORTD_DIR&0xf0;
		}
		break;
	}
}

/*write certain value in lower nibble */

void gpioLowerNibbleWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		
		case PORTA:
		if(value == HIGH)
		{
			PORTA_DATA = (PORTA_DATA&0xF0)|0X0F;
		}
		else
		{
			PORTA_DATA = PORTA_DATA & 0xf0;
		}
		
		break;
		
		case PORTB:
		if(value == HIGH)
		{
			PORTB_DATA = (PORTB_DATA&0xf0)|0X0F;
		}
		else
		{
			PORTB_DATA = PORTB_DATA&0xf0;
		}
		break;

		case PORTC:
		if(value == HIGH)
		{
			PORTC_DATA = (PORTC_DATA&0xf0)|0X0F;
		}
		else
		{
			PORTC_DATA = PORTC_DATA&0xf0;
		}

		break;
		case PORTD:
		if(value == HIGH)
		{
			PORTD_DATA = (PORTD_DATA&0xf0)|0X0F;
		}
		else
		{
			PORTD_DATA = PORTD_DATA&0xf0;
		}

		break;
	}
}

/*toggle lower nibble*/

void gpioLowerNibbleToggle(uint8 port)
{
	switch(port)
	{
		case PORTA:
		PORTA_DATA ^= 0x0f;
		break;
		
		case PORTB:
		PORTB_DATA ^= 0x0f;
		break;
		
		case PORTC:
		PORTC_DATA ^= 0x0f;
		break;
		
		case PORTD:
		PORTD_DATA ^= 0x0f;
		break;
	}
}

/*read lower nibble of certain port*/

uint8 gpioLowerNibbleRead(uint8 port)
{
	switch(port)
	{
		case PORTA:
		return (PORTA_PIN&0x0f);
		break;
		
		case PORTB:
		return (PORTB_PIN&0x0f);
		break;
		
		case PORTC:
		return (PORTC_PIN&0x0f);
		break;
		
		case PORTD:
		return (PORTD_PIN&0x0f);
		break;
		
		default:
		return -1;
		break;
	}
}