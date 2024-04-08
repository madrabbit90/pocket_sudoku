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
