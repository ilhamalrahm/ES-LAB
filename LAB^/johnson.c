#include <LPC17xx.h>
unsigned int i=0;
unsigned int count=0;
unsigned long int sh=0;
unsigned int flag=1;
 int main()
 {
	 SystemInit();
	 SystemCoreClockUpdate();
	 LPC_PINCON->PINSEL0=0;
	 
	 LPC_GPIO0->FIODIR=0X000000FF;
	 
	 
	 sh=0X00000080;
	 while(1)
	 {
		 if(sh<=0x000000000)
		 {
			 sh=0X00000080;
			 if(flag==1)
			 {
				 flag=0;
			 }
			 else
			 {
				 flag=1;
			 }

		 }
		 if(flag==1)
		 {
			  LPC_GPIO0->FIOSET=sh;
		 for(i=0;i<100000;i++);
		 
		 sh>>=1;
		 LPC_GPIO0->FIOSET=sh;
		 for(i=0;i<100000;i++);
		
		 sh>>=1;
		 }
		 else
		 {
			 LPC_GPIO0->FIOCLR=sh;
		 for(i=0;i<100000;i++);
		 
		 sh>>=1;
		 LPC_GPIO0->FIOCLR=sh;
		 for(i=0;i<100000;i++);
		
		 sh>>=1;
		 }

		 
	
		 
		 
	 }
	 
	 
 }
 
 
	 