#include <math.h>
#include <winbgim.h>
#define Y 700
#define X 700
void triangle(float x, float y,float h)
{
    for (float delta = 0; delta > -5; delta--)
    {
        line(x - (h + delta) / sqrt(3), y - (h + delta) / 3, x + (h + delta) / sqrt(3), y - (h + delta) / 3);
        line(x - (h + delta) / sqrt(3),y - (h + delta) / 3, x,y + 2 * (h + delta) / 3);
        line(x,y + 2 * (h + delta) / 3,x + (h + delta) / sqrt(3),y - (h + delta) / 3);
    }
}
void trianglev2(float x, float y,float h)
{
    for (float delta = 0; delta > -5 ; delta --)
    {
        line(x - (h + delta) / sqrt(3),y + (h + delta) / 3,x + (h + delta) / sqrt(3), y + (h + delta) / 3);
        line(x - (h + delta) / sqrt(3),y + (h + delta) / 3, x, y - 2 * (h + delta) / 3);
        line(x, y - 2 * (h + delta) / 3, x + (h + delta) / sqrt(3),y + (h + delta) / 3);
    }
}
int drawTriangles(float x = X / 2, float y = 2 * Y / 3, float h = Y / 2)
{
    if (h < 5) return 0;
    if (x > 0 && y > 0 && x < X && y < Y)
    {
        triangle(x, y, h);
    }
    drawTriangles(x,y - 2 * h / 3, h / 2);
    drawTriangles(x - h / sqrt(3), y + h / 3, h / 2);
    drawTriangles(x + h / sqrt(3), y + h / 3, h / 2);
    return 0;
}
int main()
{
    initwindow(700, 700);
    trianglev2(X / 2, 2 * Y / 3, Y);
    drawTriangles();
    getch();
    closegraph();
    return 0;
}
