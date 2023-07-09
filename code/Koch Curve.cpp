#include <math.h>
#include <graphics.h>
#define pi 3.14
void koch(float x0, float y0,float l,float u,int n)
{
    float xa,ya,xb,yb,xc,yc,x1,y1;
//daca nu suntem pe nivelul n==1 (cel de baza, cand fractalul se reduce la un segment
    if(n!=1)
    {
//altfel calculam coordonatele punctelor A,B si C
        xa=x0+l/3*cos(u);
        ya=y0-l/3*sin(u);
        xb=xa+l/3*cos(u+pi/3);
        yb=ya-l/3*sin(u+pi/3);
        xc=xb+l/3*cos(u-pi/3);
        yc=yb-l/3*sin(u-pi/3);
//Si apelam recursiv desenarea fractalului pe nivelele urmatoare:
        koch(x0,y0,l/3,u,n-1);
        koch(xa,ya,l/3,u+pi/3,n-1);
        koch(xb,yb,l/3,u-pi/3,n-1);
        koch(xc,yc,l/3,u,n-1);
    }
    else
    {
//iar daca suntem pe nivelul 1, desenam pur si simplu segmentul:
        x1=x0+l*cos(u); y1=y0-l*sin(u); line(x0,y0,x1,y1);
    }
}
int main(void)
{
    int gd = DETECT, gm, errorcode;
    int n=10;
    char driver[] = "";
    initgraph(&gd, &gm, driver);
    initwindow(1400,1400);
    koch(10,475,1400,0,n);
    getch();
    closegraph();
    return 0;
}
