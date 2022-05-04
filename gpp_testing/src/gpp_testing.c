/*
===============================================================================
 Name        : GPP testing.c
 Author      :Palash
 Version     : 1
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <stdio.h>

//Initialize the port and pin as outputs.
void GPIOinitOut(uint8_t portNum, uint32_t pinNum)
{
	if (portNum == 0)
	{
		LPC_GPIO0->FIODIR |= (1 << pinNum);
	}
	else if (portNum == 1)
	{
		LPC_GPIO1->FIODIR |= (1 << pinNum);
	}
	else if (portNum == 2)
	{
		LPC_GPIO2->FIODIR |= (1 << pinNum);
	}
	else
	{
		puts("Not a valid port!\n");
	}
}

void GPIOinitInput(uint8_t portNum, uint32_t pinNum)
{
	if (portNum == 0)
	{
		LPC_GPIO0->FIODIR |= (0 << pinNum);
	}
	else if (portNum == 1)
	{
		LPC_GPIO1->FIODIR |= (0 << pinNum);
	}
	else if (portNum == 2)
	{
		LPC_GPIO2->FIODIR |= (0 << pinNum);
	}
	else
	{
		puts("Not a valid port!\n");
	}
}
void setGPIO(uint8_t portNum, uint32_t pinNum)
{
	if (portNum == 0)
	{
		LPC_GPIO0->FIOSET = (1 << pinNum);
		printf("Pin 0.%d has been set.\n",pinNum);
	}
	//Can be used to set pins on other ports for future modification
	else
	{
		puts("Only port 0 is used, try again!\n");
	}
}

//Deactivate the pin
void clearGPIO(uint8_t portNum, uint32_t pinNum)
{
	if (portNum == 0)
	{
		LPC_GPIO0->FIOCLR = (1 << pinNum);
		printf("Pin 0.%d has been cleared.\n", pinNum);
	}
	//Can be used to clear pins on other ports for future modification
	else
	{
		puts("Only port 0 is used, try again!\n");
	}
}

int main(void)
{

	GPIOinitOut(0,21);    	//Set pin p0.21 as output
	GPIOinitInput(2,13); 	// set pin p2.13 as input

	setGPIO(0,21); 			// give logic 1 on pin p0.21 // LED ON

	uint32_t switch_status; // switch status variable
	uint32_t curr,prev;
	switch_status = LPC_GPIO2->FIOPIN>>13;	// read register FIOPIN pin 13th

	printf("Switch current status is logic %d \n",switch_status);

	prev = switch_status;
	while(1)
	{
		curr = LPC_GPIO2->FIOPIN>>13; // check  current status

		if(curr != prev){			// if switch is toggled
			printf(" Switch status is changed to logic %d \n",curr);
			prev = curr;
		}
	}

    return 0;
}
