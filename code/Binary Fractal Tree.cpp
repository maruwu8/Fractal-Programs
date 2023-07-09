#include <math.h>
#include <graphics.h>
#define pi 180

void arbore(int x0,int y0,int l,int u,int n)
{
    int x1,y1;
    if(n==0)
        return;
    else
    {
        x1=x0+l*cos(u);
        y1=y0-l*sin(u);
        line(x0,y0,x1,y1);
        arbore(x1,y1,l/2,u-pi/4,n-1);
        arbore(x1,y1,l/2,u+pi/4,n-1);
    }
}
int main(void)
{
    int n=10;
    int gd = DETECT, gm, errorcode;
    char driver[] = "";
    initgraph(&gd, &gm, driver);
    arbore(550,700,400,90,n);
    getch();
    closegraph();
    return 0;
}

