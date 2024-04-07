#include <iostream>
#include <ncurses.h>
#include <string>

using namespace std;

char initpuzz[] = "070000043040009610800634900094052000358460020000800530080070091902100005007040802";

int xpos = 0;
int ypos = 0;
int yoff = 2;
int xoff = 15;

char padder;
char pfield[9][9];
bool givens[9][9];

string s = "123456789";

void puzzinit()
{
    for (int i; i<81; i++)
    {
        pfield[i%9][i/9]=initpuzz[i];
        if(s.find(initpuzz[i])<s.length())
                givens[i%9][i/9]=true;
        else
                givens[i%9][i/9]=false;
    }
}

bool rules()
{
    for (int i=0; i<9; i++)
    {
        if (pfield[i][ypos] == padder)
            return false;
        if (pfield[xpos][i] == padder)
            return false;
        if (pfield[((xpos/3)*3)+i%3][((ypos/3)*3)+i/3] == padder)
            return false;
    }
    return true;
}

void redraw() {
    move(1, 0);
    printw("POCKET SuDoKu");
    for (int i = 0; i<403; i++)
    {
         move(i%13+yoff, i/13+xoff);
         if ((((i%13)%4)==0) && (((i/13)%10)==0)){addch('+');}
         else {if (((i%13)%4)==0){addch('-');}
         if (((i/13)%10)==0){addch('|');}}
     }
    for (int o = 0; o<9; o++)
    {
        for (int v = 0; v<9; v++)
        {
            if(s.find(pfield[o][v])<s.length())
            {
                move(v+yoff+1+v/3, o*3+2+o/3+xoff);
                addch(pfield[o][v]);
            }
            if(givens[o][v])
            {
                move(v+yoff+1+v/3, o*3+1+o/3+xoff);
                addch('(');
                move(v+yoff+1+v/3, o*3+3+o/3+xoff);
                addch(')');
            }
        }
    }

}
void controls() {
    switch (padder)
    {
        case 'k': ypos=ypos-1;
            break;
        case 'j': ypos=ypos+1;
            break;
        case 'h': xpos=xpos-1;
            break;
        case 'l': xpos=xpos+1;
            break;
    }
    if(s.find(padder)<s.length() && givens[xpos][ypos] == false && rules())
    {
        pfield[xpos][ypos] = padder;
    }
    if (ypos > 8)
        ypos = 8;
    if (ypos < 0)
        ypos = 0;
    if (xpos > 8)
        xpos = 8;
    if (xpos < 0)
        xpos = 0;
}

int main(int argc, char ** argv)
{
    puzzinit();
    initscr();
    while (5==5)
    {
        clear();
        controls();
        redraw();
        move(ypos+yoff+1+ypos/3, xoff+xpos*3+2+xpos/3);
        refresh();
        padder = getch();
    }
    endwin();
    return 0;
}
