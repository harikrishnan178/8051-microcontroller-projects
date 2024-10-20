#include<reg51.h>

sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
void lcd_init();
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_string(char *str);
void delay(int a);

void main()
{
  lcd_init();
	lcd_string("Electronics");
	lcd_cmd(0xc0);
	lcd_string("projects");
	delay(2500);
	lcd_cmd(0x01);
	lcd_string("WELCOME");
	while(1)
	{
	}
}
void lcd_init()
{
lcd_cmd(0x38);
lcd_cmd(0x0c);
lcd_cmd(0x01);
lcd_cmd(0x80);
}
void lcd_cmd(unsigned char ch)
{
  P2=ch;
	rs=0;
	rw=0;
	en=1;
	delay(10);
	en=0;
}
void lcd_string(char *str)
{
int k=0;
while(str[k]!='\0')
{
lcd_data(str[k]);
k++;
}
}

void lcd_data(unsigned char ch)
{
  P2=ch;
	rs=1;
	rw=0;
	en=1;
	delay(10);
	en=0;
}
void delay(int a)
{
  int i,j;
	for(i=0;i<a;i++)
	{
	for(j=0;j<250;j++)
		{
		}
	}
}