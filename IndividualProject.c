#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#define HEART_SCALE 5
#define VIBRATION_AMPLITUDE 0.1
void heartShape(double time)
{
    char character;
    double vibration;
    for(double y=1.5;y>-1.5;y=y-0.1)
    {
        for(double x=-2.8;x<2.8;x=x+0.05)
        {
            double a=x*x+y*y-1;
            character=(a*a*a-x*x*y*y*y)<=0.0?'*':' ';
            vibration=VIBRATION_AMPLITUDE*sin(time);
            printf("%c",character);
            usleep(10000);
        }
            printf("\n");

    }
}
int main()
{
    double time=0.0;
    while(1)
    {
        system("cls");
        heartShape(time);
        time=time+0.1;
        usleep(10000);

    }
}
