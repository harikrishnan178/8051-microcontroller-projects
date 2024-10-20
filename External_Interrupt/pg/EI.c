#include<reg51.h>

sbit led1=P2^0;
void delay(int a);

void main()
{
	P2=0x00;
	TCON=0x01;
	IE=0x81;
	while(1)
	{
	}
}

void ISR_ex0() interrupt 0
{
	led1=~led1;
	delay(10);
}

void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
	}
}





