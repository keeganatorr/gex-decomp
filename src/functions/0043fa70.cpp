extern "C" {
    extern int gFontX_004a2af0;
    extern int gFontY_004a2aec;
    extern void TXT_DrawPrint_0043f7f0(int, int);
}

extern "C" void GEX_Target(int xpos, int ypos, int a3, int a4)
{
    gFontX_004a2af0 = xpos >> 16;
    gFontY_004a2aec = ypos >> 16;
    TXT_DrawPrint_0043f7f0(a3, a4);
}
