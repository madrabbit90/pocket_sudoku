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
