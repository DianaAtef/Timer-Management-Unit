/*
 * Dio.h
 *
 * Created: 11/6/2019 10:24:01 PM
 *  Author: AVE-LAP-025
 */ 


#ifndef DIO_H_
#define DIO_H_


/**
 * 	
 *	This file is a header file that contains prototypes of MCAL functions'
 *	prototypes and description.
 */

#include "Std_Types.h"
#include "Registers.h"


#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define INPUT  0x00
#define OUTPUT 0XFF


/************************************************************************/
/*				 Enum for defining bit numbers                          */
/************************************************************************/
typedef enum EN_bits
{
	BIT0 = 0x01,	// defines BIT0 in a register
	BIT1 = 0x02,	// defines BIT1 in a register
	BIT2 = 0x04,	// defines BIT2 in a register
	BIT3 = 0x08,	// defines BIT3 in a register
	BIT4 = 0x10,	// defines BIT4 in a register
	BIT5 = 0x20,	// defines BIT5 in a register
	BIT6 = 0x40,	// defines BIT6 in a register
	BIT7 = 0x80,	// defines BIT7 in a register
}EN_bits;

/************************************************************************/
/*				 Dio functions' prototypes	                            */
/************************************************************************/

/*===========================PORT Control===============================*/
/**
 * Description: Configure the direction of the whole port
 * @param port: PORT A,PORT B,PORT C,or PORT D 
 * @param direction: INPUT or OUTPUT
 */
void gpioPortDirection(uint8 port, uint8 direction);

/**
 * Description:Write to the whole port
 * @param port: PORT name A,B,C or D
 * @param value: value to be written to port ALL_LOW or ALL_HIGH
 */
void gpioPortWrite(uint8 port, uint8 value);

/**
 * Description:Toggle the whole port after the user sets the direction of port
 * @param port: PORT name A,B,C or D
 */
void gpioPortToggle(uint8 port);

/**
 * Description:Read the whole port
 * @param port:PORT name A,B,C or D
 * @return: Reading value of port
 */
uint8 gpioPortRead(uint8 port);

/*===========================PIN Control===============================*/
/**
 * Description:set direction of  certain pins in certain port
 * @param port: PORT name 
 * @param pins: pins required to set direction
 * @param direction: setting direction either INPUT or OUTPUT
 */
void gpioPinDirection(uint8 port, uint8 pins, uint8 direction);

/**
 * Description:write a certain value either 1 or 0 in certain pins
 * @param port: PORT name
 * @param pins: pins number
 * @param value: specified pins either HIGH OR LOW
 */
void gpioPinWrite(uint8 port, uint8 pins, uint8 value);

/**
 * Description:toggle certain pins in certain port 
 * @param port:certain port
 * @param pins: certain pins
 */
void gpioPinToggle(uint8 port, uint8 pins);

/**
 * Description:read certain pin value in certain port
 * @param port: PORT name
 * @param pin: pin number
 * @return: value of pin 
 */
uint8 gpioPinRead(uint8 port, uint8 pin);

/*===========================Upper Nibble Control===============================*/
/**
 * Description:set the direction of upper nibble 
 * @param port:port name
 * @param direction:direction either INPUT  or OUTPUT
 */
void gpioUpperNibbleDirection(uint8 port, uint8 direction);

/**
 * Description:write certain value in upper nibble
 * @param port:port name
 * @param value:value to be written HIGH or LOW
 */
void gpioUpperNibbleWrite(uint8 port, uint8 value);

/**
 * Description:toggle upper nibble
 * @param port: Port number
 */
void gpioUpperNibbleToggle(uint8 port);

/**
 * Description:read upper nibble of certain port
 * @param port: port name
 * @return reading 
 */
uint8 gpioUpperNibbleRead(uint8 port);

/*===========================Lower Nibble Control===============================*/
/**
 * Description:set direction of lower nibble of certain port
 * @param port:port name
 * @param direction:direction required either INPUT or OUTPUT
 */
void gpioLowerNibbleDirection(uint8 port, uint8 direction);

/**
 * Description:write certain value in lower nibble
 * @param port: port name
 * @param value: value to be written HIGH or LOW
 */
void gpioLowerNibbleWrite(uint8 port, uint8 value);

/**
 * Description:toggle lower nibble
 * @param port:Port number
 */
void gpioLowerNibbleToggle(uint8 port);

/**
 * Description:read lower nibble of certain port
 * @param port: port name
 * @return: reading
 */
uint8 gpioLowerNibbleRead(uint8 port);






#endif /* DIO_H_ */