#include <LPC17xx.h>
unsigned int delay, count=0, Switchcount=0,j, i, n, k, ele, row, col, flag;
int x;
unsigned int Disp[4][4] = {
{0x000003f0, 0x00000060, 0x000005b0, 0x000004f0}, 
{0x00000660,0x000006d0,0x000007d0, 0x00000070}, 
{0x000007f0, 0x000006f0,0x00000770,0x000007c0},
{0x00000390, 0x000005e0,0x00000790, 0x00000710}
};
int number = 0, one_sec_flag = 0;


int main (void)
{
	SystemInit();
	SystemCoreClockUpdate();
  LPC_PINCON->PINSEL0 = 0x00000000;
  LPC_PINCON->PINSEL3 = 0x00000000;
	LPC_PINCON->PINSEL1 = 0x0;
	LPC_PINCON->PINSEL4 = 0x0;
  LPC_GPIO0->FIODIR = 0x00078ff0;
  LPC_GPIO1->FIODIR = 0x0;
	LPC_GPIO2->FIODIR = 0xF<<10;
 
 
 while(1)
 {
	for(row=0;row<4;row++){
		LPC_GPIO2->FIOPIN = 1<<(10+row);
		flag = 0;
		x = LPC_GPIO1->FIOPIN& 0xf <<23;
		if(x)
		{
			flag = 1;
			if(x == 1<<23)
				col = 0;
			else if(x == 1<<24)
					col = 1;
			else if(x == 1<<25)
				col = 2;
			else if(x == 1<<26)
					col = 3;
			
		}
		LPC_GPIO0->FIOPIN = 0;
		if(flag == 1)
		{
			LPC_GPIO0->FIOMASK = 0xfffff00f;
			LPC_GPIO0->FIOPIN = Disp[row][col];
			for(j=0;j<100000;j++);
			break;
		}
	}
		
 
 }
}