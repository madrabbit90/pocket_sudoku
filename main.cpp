GNU nano 7.2                                                                                                      cues.cpp
#include <iostream>
#include <ncurses.h>
#include <string>
using namespace std;

int xpos = 0;
int ypos = 0;
int yoff = 2;
char padder;
char pfield[9][9];
string s = "123456789";

void redraw() {
    move(1, 0);
    printw("POCKET SuDoKu");
    for (int i = 0; i<403; i++)
    {
         move(i%13+yoff, i/13+0);
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
                move(v+yoff+1+v/3, o*3+2+o/3);
                addch(pfield[o][v]);
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
    if(s.find(padder)<s.length())
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
    initscr();
    while (5==5)
    {
        clear();
        controls();
        redraw();
        move(ypos+yoff+1+ypos/3, xpos*3+2+xpos/3);
        refresh();
        padder = getch();
    }
    endwin();
    return 0;
}
