#include <LPC17xx.h>
unsigned int i=0;
unsigned long int sh=0;
 int main()
 {
	 SystemInit();
	 SystemCoreClockUpdate();
	 LPC_PINCON->PINSEL0=0;
	 
	 LPC_GPIO0->FIODIR=0X000000FF;
	 
	 
	 sh=0X00000080;
	 while(1)
	 {
		 if(sh==0)
		 {
			 sh=0X00000080;
		 }
		 
		 LPC_GPIO0->FIOSET=sh;
		 for(i=0;i<100000;i++);
		 LPC_GPIO0->FIOCLR=sh;
		 sh>>=1;
		 LPC_GPIO0->FIOSET=sh;
		 for(i=0;i<100000;i++);
		 LPC_GPIO0->FIOCLR=sh;
		 sh>>=1;
		 
		 
	 }
	 
	 
 }
 
 
	 