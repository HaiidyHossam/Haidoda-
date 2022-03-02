
#include "GPIO.h"

void Port_Direction(u8 base , u8 state)  //DDR
{
	if(state==output)
	{
		(*(volatile unsigned char *)(base+1))=0xff;
	}else
	{
		(*(volatile unsigned char *)(base+1))=0x00;
	}
}

/*******************************************************/
void Pin_Direction(u8 base , u8 pin , u8 state)    
{
	if(state==output)
	{
		(*(volatile unsigned char *)(base+1)) |= (1<<pin);
	}else
	{
		(*(volatile unsigned char *)(base+1)) &= ~(1<<pin);
	}
}
/******************************************************/
void Pin_Reset(u8 base , u8 pin)
{
	(*(volatile unsigned char *)(base+2)) &= ~(1<<pin);
}
/*******************************************************/

void Pin_Set(u8 base ,u8 pin)
{
	(*(volatile unsigned char *)(base+2)) |= (1<<pin);
}
 /*******************************************************/
 
 void Port_Write(u8 base ,u8 value)
 {
	 (*(volatile unsigned char *)(base+2))=value;
	
 }
  /*******************************************************/

 u8 Port_Read(u8 base)
 {
	 u8 R_value;
	 R_value =(*(volatile unsigned char *)(base));
	 return R_value;
 }
 
 /*******************************************************/

void Pin_Write(u8 base ,u8 pin ,u8 value)
{
	if(value==1)
	*(volatile u8*)(base+2)|=(1<<pin);
	else
	*(volatile u8*)(base+2)&=~(1<<pin);
}
 
 /*******************************************************/
 u8 Pin_Read(u8 base ,u8 pin)
 {
	 u8 Pin_value;
	 Pin_value=(*(volatile unsigned char *)(base)) && (1<<pin);
	 if (Pin_value==0) return 0;
	 else return 1;
	
 }


