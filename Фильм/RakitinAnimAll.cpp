#include "TXLib.h"                  //завершение програмы - ESC

void DrawNam       (int x, int y, int s, int r, int g, int b, int syc);
void DrawHouse     (int x, int y, int s, int r, int g, int b);
void DrawSetAnim   (int x, int y, int s, int r, int g, int b);
void DrawStar      (int x, int y, int s, int r, int g, int b);
void Draw1Xebet    (int x, int y, int s, int r, int g, int b);
void DrawTextStart (int x, int y);
void DrawTextEnd   (int x, int y);
void DrawScene1    (int x, int y);
void DrawScene2    (int x, int y);

int main()
{
    txCreateWindow (1280, 800);

    DrawTextStart (150, 180);
    DrawScene1 (10, 10);
    txSleep (1000);
    DrawScene2 (10, 250);
    DrawTextEnd (10, 10);

    return 0;
}

void DrawScene1 (int x, int y)
{
    int cli;
    int house = 0;
    int houseR = 300;
    int housetrue = 0;
    int num = 0;
    int xdub = 0;
    int xdubdub = 0;

    for(cli = 0; cli <= 664; cli++)
    {
        if(GetAsyncKeyState(VK_ESCAPE)) break;

        if(num < 30)
        {
            DrawNam(x + xdub, y, 25, 0, 0, 180, 0);
            if (housetrue == 0) DrawHouse(500, houseR, 25, 50, 255, 0);
            txSleep(17);
            txSetFillColor(RGB(0,0,0));
            txClear();

            Draw1Xebet (900, 600, 25, 100, 200, 200);
        }
        else if(num > 30)
        {
            DrawNam(x + xdub, y, 25, 1, 0, 180, 0);
            if (housetrue == 0) DrawHouse(500, houseR, 25, 50, 255, 0);
            txSleep(17);
            txSetFillColor(RGB(0,0,0));
            txClear();

            Draw1Xebet (900, 600, 25, 100, 100, 200);
        }

        if(num < 60) num++;
        else if(num == 60) num = 0;

        if(xdubdub + 288 >= 1280)
        {
            xdubdub = 1280;
            if(xdub <= 0)
            {
                xdubdub = 0;
                x = x + 3;
            }
            else xdub = xdub - 3;
        }
        else if(xdubdub+144 >= 640 && xdubdub+144 <= 643)
        {
            txSetFillColor(RGB(0,0,0));
            txClear();

            Draw1Xebet (900, 600, 25, 100, 200, 200);

            DrawHouse(500, houseR, 25, 50, 255, 0);
            DrawNam(x + xdub, y, 25, 1, 0, 180, 0);
            DrawSetAnim (xdub+135, y+170, 25, 1, 0, 0);
            xdubdub = xdubdub + 3;
            housetrue = 1;

            for (house = 0; house < 500; house++)
            {
                if(GetAsyncKeyState(VK_ESCAPE)) break;
                txSetFillColor(RGB(0,0,0));
                txClear();

                Draw1Xebet (900, 600, 25, 100, 100, 200);

                DrawNam(x + xdub, y, 25, 1, 0, 180, 0);
                DrawHouse(500, houseR, 25, 50, 255, 0);
                houseR++;
                txSleep(10);
            }
        }
        else
        {
            xdub = xdub + 3;
            xdubdub = xdub;
        }
    }
}

void DrawScene2(int x, int y)
{
    int cil;
    int s;
    int num = 0;
    int xdub = x;
    int xdubdub = 990;

    for (cil = 0; cil <= 177; cil++)
    {
        if(GetAsyncKeyState(VK_ESCAPE)) break;
        if(num < 30)
        {
            DrawNam(x, y, 25, 0, 0, 180, 0);
            DrawNam(xdub+xdubdub, y, 25, 0, 0, 180, 0);
            txSleep(17);
            txSetFillColor(RGB(0,0,0));
            txClear();
        }
        else if(num > 30)
        {
            DrawNam(x, y, 25, 1, 0, 180, 0);
            DrawNam(xdub+xdubdub, y, 25, 1, 0, 180, 0);
            txSleep(17);
            txSetFillColor(RGB(0,0,0));
            txClear();
        }

        if(num < 60)
        {
            num++;
            x = x+2;
            xdubdub = xdubdub-2;
        }
        else if(num == 60)
        {
            num = 0;
            x = x+2;
            xdubdub = xdubdub-2;
        }
    }

    for (cil = 0, s = 0; cil <= 10; cil++, s++)
    {
        if(GetAsyncKeyState(VK_ESCAPE)) break;
        txSetFillColor(NULL);
        txClear();
        DrawStar (640, 425, s, 255, 0, 0);
        txSleep (500);
    }
    txSetFillColor(NULL);
    txClear();
    txSetColor (RGB(255,0,0));
    txSelectFont("Comic Sans MS", 100);
    txTextOut (200, 200, "Так и появился СССР");
    txSleep (2000);
    txSetFillColor(NULL);
    txClear();
}

void DrawNam(int x, int y, int s, int syc, int r, int g, int b)
{
    txSetColor(TX_NULL);
    txSetFillColor(RGB(r,g,b));
    txRectangle(x+2*s, y+2*s, x+9*s, y+6*s);           //тело

    txSetFillColor(RGB(0,0,0));
    txRectangle(x+3*s, y+3*s, x+4*s, y+4*s);           //глаз правый
    txRectangle(x+7*s, y+3*s, x+8*s, y+4*s);           //глаз левый

    txSetFillColor(RGB(r,g,g));
    txRectangle(x+2*s, y+0*s, x+3*s, y+1*s);           //рога правые
    txRectangle(x+3*s, y+1*s, x+4*s, y+2*s);           //рога правые
    txRectangle(x+9*s, y+0*s, x+8*s, y+1*s);           //рога левые
    txRectangle(x+8*s, y+1*s, x+7*s, y+2*s);           //рога левые

    txRectangle(x+1*s,  y+3*s,  x+2*s,  y+5*s);        //рука правая
    txRectangle(x+0*s,  y+4*s,  x+1*s,  y+7*s);        //рука правая
    txRectangle(x+9*s,  y+3*s,  x+10*s, y+5*s);        //рука левая
    txRectangle(x+10*s, y+4*s,  x+11*s, y+7*s);        //рука левая

    if(syc == 0)
        {
            txRectangle(x+2*s, y+6*s, x+3*s, y+7*s);   //нога правая
            txRectangle(x+3*s, y+7*s, x+5*s, y+8*s);   //нога правая
            txRectangle(x+9*s, y+6*s, x+8*s, y+7*s);   //нога левая
            txRectangle(x+8*s, y+7*s, x+6*s, y+8*s);   //нога левая
        }
        else if( syc == 1)
            {
                txRectangle(x+2*s, y+6*s, x+3*s, y+7*s);            //нога правая
                txRectangle(x+3*s, y+7*s, x+4*s, y+8*s);            //нога правая
                txRectangle(x+9*s, y+6*s, x+8*s, y+7*s);            //нога левая
                txRectangle(x+8*s, y+7*s, x+7*s, y+8*s);            //нога левая
            }
}

void DrawSetAnim(int x, int y, int s, int r, int g, int b)             //рисует снаряд
{
    int dlina;
    int ydub = y;
    int R = 0;
    int G = 0;
    int B = 0;

    for (dlina = 0; dlina <= 256; dlina++)
    {
        if(GetAsyncKeyState(VK_ESCAPE)) break;

        txSetColor (RGB(R,G,B));
        txLine (x, ydub, x+1*s, ydub);
        ydub++;
        R = R + r;
        G = G + g;
        B = B + b;
        txSleep(5);
    }
}

void DrawHouse(int x, int y,int s, int r, int g, int b)          //рисует дом
{
    int num;
    int copyx = 0;
    int copyy = 0;
    int cir = 10;
    int corx = 12*s;
    int cory = 20*s;

    txSetFillColor(RGB(100,200,200));
    txRectangle(x, y, x+corx+2, y+cory+2);

    txSetColor(RGB(r,g,b));
    for(num = 0; num <= corx; num++)
    {
        txLine(x, y+copyy, x+corx, y+copyy);
        if(copyy < cory) copyy = copyy+cir;
    }

    for(num = 0; num <= cory; num++)
    {
        txLine(x+copyx, y, x+copyx, y+cory);
        if(copyx < corx) copyx = copyx+cir;
    }
    txSetColor (RGB(150,50,200));
    txSelectFont("Comic Sans MS", 60);
    txTextOut (x+60, y+50, "Царская");
    txTextOut (x+60, y+100, "Власть");
}

void Draw1Xebet(int x, int y, int s, int r, int g, int b)
{
    txSetFillColor (RGB(r,g,b));
    txSetColor (TX_NULL);
    txRectangle (x, y, x+12*s, y+6*s);
    txSetColor(RGB(255,255,255));
    txSelectFont("Comic Sans MS", 100);
    txTextOut (x+2*s, y+s,"1Xebet");
    txSetColor(RGB(255,255,255));
    txSelectFont("Comic Sans MS", 25);
    txTextOut (x+2*s, y+0.1*s,"Спонсор нашей программы");
}

void DrawStar(int x, int y, int s, int r, int g, int b)
{
    txSetColor(RGB(0,0,0));
    txSetFillColor(RGB(r,g,b));

    POINT num[10] = {{x+s*25, y+s*34}, {x+s*15, y+s*5}, {x+s*40, y-s*13}, {x+s*9, y-s*13}, {x, y-s*40}, {x-s*9, y-s*13}, {x-s*40, y-s*13}, {x-s*15, y+s*5}, {x-s*25, y+s*34}, {x, y+s*16}};
    txPolygon(num, 10);
}

void DrawTextStart(int x, int y)
{
    txSetColor (RGB(255,50,255));
    txSelectFont("Comic Sans MS", 200);
    txTextOut (x, y, "Упорот");
    txSetColor (RGB(0,255,200));
    txTextOut (x+500, y, "Film");
    txSetColor (RGB(0,255,100));
    txTextOut (x+100, y+225, "Представляет");
    txSleep (3000);

    txSetFillColor(NULL);
    txClear();

    txSetColor (RGB(255,0,0));
    txSelectFont("Comic Sans MS", 200);
    txTextOut (x+100, y-100, "Появление");
    txTextOut (x+100, y+50, "Советского");
    txTextOut (x+100, y+200, "Союза");
    txSleep(3000);
    txSetFillColor(NULL);
    txClear();
}

void DrawTextEnd(int x, int y)
{
    txSetColor (RGB(255,255,255));
    txSelectFont("Comic Sans MS", 100);
    txTextOut (x, y, "В роли СССР - СССР.");
    txTextOut (x, y+100, "Сценарист - FireKOT");
    txTextOut (x, y+200, "СЪёмка - никто");
    txTextOut (x, y+300, "Монтаж - никто");
    txTextOut (x, y+400, "Автор идеи - кто-то упоротый");
    txTextOut (x, y+500, "Режисер - FireKOT");
    txTextOut (x, y+600, "Создатель - FireKOT");

    txSleep(10000);
    txSetFillColor(NULL);
    txClear();

}
