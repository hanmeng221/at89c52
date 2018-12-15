#include<reg52.h>
sbit f_1 = P2^0;
sbit f_2 = P2^1;
sbit f_3 = P2^2;
sbit f_4 = P2^3;

sbit s_1 = P3^0;
sbit s_2 = P3^1;
sbit s_3 = P3^2;
sbit 3_4 = P3^3;

unsigned char times;
unsigned char count;



void InitTimer0()
{
    TMOD = 0x01;
    TH0 = (65536-50000)/256;
    TL0 = (65536-50000)%256;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
    TR0 = 1;
}

void showfirstnumber(unsigned char t)
{
    f_1 = (t >> 3) & (0x0001);
    f_2 = (t >> 2) & (0x0001);
    f_3 = (t >> 1) & (0x0001);
    f_4 = (t >> 0) & (0x0001);
}

void showsecondnumber(unsigned char t)
{
    s_1 = (t >> 3) & (0x0001);
    s_2 = (t >> 2) & (0x0001);
    s_3 = (t >> 1) & (0x0001);
    s_4 = (t >> 0) & (0x0001);
}

void show(unsigned char t)
{
    showfirstnumber(t/10);
    showsecondnumber(t%10);
}


void main()
{
    times = 60;
    count = 0;
    InitTimer0();
    while(1)
    {}

}


void T0_INT() interrupt 1
{
    TH0 = (65536-50000)/256;
    TL0 = (65536-50000)%256;
    count ++;
    if(count == 20)
    {
        if(times == 0)
        {
            times = 0;
        }
        else
        {
            times --;
        }
        show(times);
        count = 0;
    }   
}