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
	 LPC_PINCON->PINSEL4=0;
	 
	 
	 LPC_GPIO0->FIODIR=0X000000FF;
	 LPC_GPIO2->FIODIR=0X00000000;
	 LPC_GPIO2->FIOPIN=0X00000000;
	 
	 
	 x=LPC_GPIO2->FIOPIN;
	 x=x>>12;
	 x&=1;
	 
	 if(x==1)
	 {
		 sh=0x00000000;
	 }
	 else
	 {
		 sh=0X000000FF;
	 }
	 
	 while(1)
	 {
		 
		 if(x==1)
		 {
			LPC_GPIO0->FIOPIN=sh;
		 sh+=0x00000001;
		 for(i=0;i<100000;i++);
			 x=LPC_GPIO2->FIOPIN;
			 x=x>>12;
			 x&=1;
			 if(x==0)
			 {
				 continue;
			 }
		 }
		 else
		 {
			 	LPC_GPIO0->FIOPIN=sh;
		 sh-=0x00000001;
		 for(i=0;i<100000;i++);
			 x=LPC_GPIO2->FIOPIN;
			 x=x>>12;
			 x&=1;
			 if(x==1)
			 {
				 continue;
			 }
		 }
		 
		
		
		 
	 }
	 
	 
 }
 
 
	 