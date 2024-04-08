#include <iostream>
#include <ncurses.h>
#include <string>

using namespace std;

#include "puzzles.h"

int xpos = 0;
int ypos = 0;
int yoff = 2;
int xoff = 15;

char padder;
char pfield[9][9];
bool givens[9][9];

string s = "123456789";

#include "init.h"
#include "logic.h"
#include "draw.h"
#include "controls.h"

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