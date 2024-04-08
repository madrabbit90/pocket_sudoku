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
        pfield[xpos][ypos] = padder;
    if(padder == '0' && givens[xpos][ypos] == false)
        pfield[xpos][ypos] = padder;
    if (ypos > 8)
        ypos = 8;
    if (ypos < 0)
        ypos = 0;
    if (xpos > 8)
        xpos = 8;
    if (xpos < 0)
        xpos = 0;
}
