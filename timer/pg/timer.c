#include<reg51.h>



void delay();
void main()
{
	while(1)
	{
	P2=0x00;
	delay();
	P2=0x01;
	delay();
	}
}
void delay()
{
	TMOD=0x01;
	TH0=0xDC;
	TL0=0x00;
	TR0=1;
	while(TF0==0);
	TF0=0;
	TR0=0;

}
