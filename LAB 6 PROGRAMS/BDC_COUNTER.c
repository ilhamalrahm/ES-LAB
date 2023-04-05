#include <LPC17xx.h>
unsigned int delay, count=0, Switchcount=0,i,j,k,l,a,n,number=0,one_sec_flag=0;

unsigned int Disp[16]={0x000003f0, 0x00000060,
                                       0x000005b0, 0x000004f0,
                                       0x00000660,0x000006d0,
                                       0x000007d0, 0x00000070,
                                       0x000007f0, 0x000006f0,
                                      0x00000770,0x000007c0,
                                      0x00000390, 0x000005e0,
                                      0x00000790, 0x00000710 };

#define ALLDISP  0x00180000 //Select all display
#define DATAPORT 0x00000ff0 //P0.4 to P0.11 : Data lines connected to drive Seven Segments

int main (void)
{
 LPC_PINCON->PINSEL0 = 0x00000000;
 
 LPC_PINCON->PINSEL3 = 0X00000000;
 LPC_GPIO0->FIODIR = 0xFF<<4;
 LPC_GPIO1->FIODIR = 0xF<<23;
 
 
 
/*for(i=0;i<=9;i++)
	{
					LPC_GPIO1->FIOSET = 3<<23;
					LPC_GPIO0->FIOPIN = Disp[i];
					for(a=0;a<10000000;a++);
		for(j=0;j<=9;j++)
		{
					LPC_GPIO1->FIOSET = 2<<23;
					LPC_GPIO0->FIOPIN = Disp[j];
					for(a=0;a<10000000;a++);
			for(k=0;k<=9;k++)
			{
				  LPC_GPIO1->FIOSET = 1<<23;
					LPC_GPIO0->FIOPIN = Disp[k];
					for(a=0;a<10000000;a++);
				for(l=0;l<=9;l++)
				{
					LPC_GPIO1->FIOSET = 0x00000000;
					LPC_GPIO0->FIOPIN = Disp[l];
					for(a=0;a<10000000;a++);
					
				}
				 
				
				
			}
		}
	}
	*/
	
	
	while(1)
	{
		n=number;
		if(one_sec_flag==1)
		{
			one_sec_flag=0;
			number=(number+1)%10000;
		}
		
		for(i=0;i<4;i++)
		{
			LPC_GPIO1->FIOPIN=i<<23;
			LPC_GPIO0->FIOPIN=Disp[n%10]<<4;
			n=n/10;
			for(j=0;j<500000;j++);
			if(count==1000)
			{
				one_sec_flag=1;
				count=0;
			}
			else
			{
				count++;
			}
			
		}
	}
}