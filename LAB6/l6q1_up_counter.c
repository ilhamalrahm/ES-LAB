#include <LPC17xx.h>
unsigned int i=0;
unsigned int x=0;
unsigned long int sh=0;
unsigned int flag=1;
 int main()
 {
	 SystemInit();
	 SystemCoreClockUpdate();
	 LPC_PINCON->PINSEL0=0;
	 
	 
	 
	 LPC_GPIO0->FIODIR=0X000000FF;
	 
	 
	 sh=0X00000000;
	 while(1)
	 {
		
		 LPC_GPIO0->FIOPIN=sh;
		 sh+=0x00000001;
		 for(i=0;i<100000;i++);
		 
		
		 
	 }
	 
	 
 }
 
 
	 