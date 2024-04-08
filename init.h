void puzzinit()
{
    for (int i; i<81; i++)
    {
        pfield[i%9][i/9]=initpuzz(1)[i];
        if(s.find(initpuzz(1)[i])<s.length())
                givens[i%9][i/9]=true;
        else
                givens[i%9][i/9]=false;
    }
}
