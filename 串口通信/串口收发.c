#include <REG52.H>
sbit LED = P1^0;
sbit key = P3^3;
unsigned char UART_buff;
bit New_rec = 0, Send_ed = 1, Money = 0;
//----------------------------------------------
void main (void)
{
    SCON = 0x50;   //串口方式1, 8-n-1, 允许接收.
    TMOD = 0x20;   //T1方式2
    TH1 = 0xFD;    //[url=]//9600bps@11.0592MHz[/url]
    TL1 = 0xFD;
    TR1 = 1;                        
    ES  = 1;       //开中断.
    EA  = 1;
while(1)  { 
			SBUF = '1'; //那就发送
		}
			
//      if ((New_rec == 1) && (Send_ed == 1))  {  //如果收到新数据及发送完毕
//        SBUF = UART_buff; //那就发送.
//        New_rec = 0;
//        Send_ed = 0;
//				break;
//    }
			}

//----------------------------------------------
void ser_int (void) interrupt 4 
{
    if(RI == 1) {  //如果收到.
      RI = 0;      //清除标志.
      New_rec = 1;
      UART_buff = SBUF;  //接收.
      if(UART_buff == '1')  LED = 1;
      if(UART_buff == '0')  LED = 0;
      if(UART_buff == '$')  Money = 1;
    }
    else  {        //如果送毕.
      TI = 0;      //清除标志.
      Send_ed = 1;
    }
} 
//----------------------------------------------
