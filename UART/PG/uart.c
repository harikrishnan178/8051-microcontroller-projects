#include<reg51.h>

void uart_init();
void uart_tx(char ch);
char uart_rx();

void main()

{
	uart_init();
	uart_tx('f');
	uart_tx('l');
	while(1)
	{
		uart_tx(uart_rx());
	}

}
void uart_init()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=0xfd;
	TR1=1;
}	

void uart_tx(char ch)
{
	SBUF=ch;
	while(TI==0);
	TI=0;
}

char uart_rx()
{
	while(RI==0);
	RI=0;
	return SBUF;
}


