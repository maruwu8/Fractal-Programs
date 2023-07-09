#include<graphics.h>
#include<math.h>
float pi=3.14, alfa;
void koch(int n, int l)
{
    if (n==0)
        linerel(int(l*cos(alfa*pi/180)),int(l*sin(alfa*pi/180)));
    else
    {
        koch(n-1,l/3);
        alfa=alfa-60;
        koch(n-1,l/3);
        alfa=alfa+120;
        koch(n-1,l/3);
        alfa=alfa-60;
        koch(n-1,l/3);
    }
}
void fulg_koch(int n,int l)
{
    koch(n,l/3);
    alfa+=120;
    koch(n,l/3);
    alfa+=120;
    koch(n,l/3);
    alfa+=120;
}
int main()
{
    int n=1,l=900;
    int gd = DETECT, gm, errorcode;
    char driver[] = "";
    initgraph(&gd, &gm, driver);
    initwindow(1200,1000);
    int x=50,y=150;
    moveto(x,y);
    for(n=1; n<=4; n++)
    {
        fulg_koch(n,l);
        x+=310;
        moveto(x,y);
    }
    getch();
    closegraph();
    return 0;
}
