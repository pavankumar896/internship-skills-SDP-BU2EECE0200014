# include<reg51.h>

#include<stdio.h>


#define lcdport P1  //lcd connection

//LED connections assignment
sbit L1 = P0^3;
sbit L2 = P2^6;
sbit L3 = P2^7;

// LCD connection
sbit rs=P2^0;
sbit en=P2^1;

//ADC connections
 sbit SC = P2^2;
 sbit ALE = P2^3;
 sbit OE = P2^4;
 sbit EOC = P2^5; 
 
//Declaring the input selection pin
 sbit ADDR_A = P1^0;
 sbit ADDR_B = P1^1;
 sbit ADDR_C = P1^2;

unsigned int result[3];
unsigned char number;
unsigned int MyData = 20;

void delay(unsigned int t)////Function for setting 1ms delay
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	for(j=0;j<1275;j++);
}


void daten()

{

    rs=1;

    //rw=0;

    en=1;

    delay(1);

    en=0;

}


void lcd_data(unsigned char ch)

{

    lcdport=ch & 0xF0;

    daten();

    lcdport=ch<<4 & 0xF0;

    daten();

}



void cmden(void)

{

    rs=0;

    en=1;

    delay(1);

    en=0;

}


void lcdcmd(unsigned char ch)

{


    lcdport=ch & 0xf0;

    cmden();

    lcdport=ch<<4 & 0xF0;

    cmden();

}



lcdprint(unsigned char *str)  //Function to send string data to LCD.

{

    while(*str)

    {

        lcd_data(*str);

        str++;

    }

}


void lcd_ini()  //Function to inisialize the LCD

{

    lcdcmd(0x02);

    lcdcmd(0x28);

    lcdcmd(0x0e);

    lcdcmd(0x01);

}


void show()

{ 

   sprintf(result,"%d",number);

   lcdprint(result);

   lcdprint("  ");

}




void main()

{
//P2 = 0x00;
 int i=0;
	unsigned char ADC_Value = 0;
	P2 = 0xFF; 
	EOC = 1;
	ALE = 0;
	OE = 0;
	SC = 0;
	

lcd_ini();

lcdprint(" ADC 0808/0809  ");

lcdcmd(192);

lcdprint("  Interfacing   ");

//delay(500);

//lcdcmd(1);

//lcdprint("Ch1   Ch2   Ch3 ");


while(1)

{
			//delay(200);
	//P3 = 0xFF;
	ADDR_C = 0;
	ADDR_B = 0; 
	ADDR_A = 0; 
	delay(10); 
	ALE = 1; 
	delay(10); 
	SC = 1; 
	delay(10);
	ALE = 0;
	SC = 0;
	while(EOC==1); 
	//while(EOC==0); 
	OE=1;
	delay(10); 
	number = P3; 
	P0 = number;
	
	delay(10);
	OE = 0 ;
	
	delay(200);
			lcdcmd(0x01); //Clear display screen
			lcdcmd(0x80); //Force cursor to the beginning ( 1st line)
			lcdprint("CLASS STRENGTH");//Sending String to LCD
			lcdcmd(0xc0); //Force cursor to the beginning ( 2nd line)
			
			//lcd_data((MyData/ 10) + 48);//seperating the first digit of MyData
			//lcd_data((MyData% 10) + 48);//seperating the first digit of MyData
			
			sprintf(result,"%03d",number);
			lcdprint(result);
			//lcdprint(" STUDENTS"); //Sending String to LCD

}

}