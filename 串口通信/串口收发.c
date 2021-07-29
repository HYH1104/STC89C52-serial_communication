#include <REG52.H>
sbit LED = P1^0;
sbit key = P3^3;
unsigned char UART_buff;
bit New_rec = 0, Send_ed = 1, Money = 0;
//----------------------------------------------
void main (void)
{
    SCON = 0x50;   //���ڷ�ʽ1, 8-n-1, �������.
    TMOD = 0x20;   //T1��ʽ2
    TH1 = 0xFD;    //[url=]//9600bps@11.0592MHz[/url]
    TL1 = 0xFD;
    TR1 = 1;                        
    ES  = 1;       //���ж�.
    EA  = 1;
while(1)  { 
			SBUF = '1'; //�Ǿͷ���
		}
			
//      if ((New_rec == 1) && (Send_ed == 1))  {  //����յ������ݼ��������
//        SBUF = UART_buff; //�Ǿͷ���.
//        New_rec = 0;
//        Send_ed = 0;
//				break;
//    }
			}

//----------------------------------------------
void ser_int (void) interrupt 4 
{
    if(RI == 1) {  //����յ�.
      RI = 0;      //�����־.
      New_rec = 1;
      UART_buff = SBUF;  //����.
      if(UART_buff == '1')  LED = 1;
      if(UART_buff == '0')  LED = 0;
      if(UART_buff == '$')  Money = 1;
    }
    else  {        //����ͱ�.
      TI = 0;      //�����־.
      Send_ed = 1;
    }
} 
//----------------------------------------------
