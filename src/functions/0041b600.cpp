extern "C" {
extern int DAT_004592b8[4][4][2];
extern int DAT_00459338[][4];
extern int DAT_00459398[3][2];
void __cdecl FUN_0041b6d0_ObjCallUnkInner4(int x, int y, int tile);
void __cdecl GEX_Target(int x, int y, int dir, int row, int col)
{
    int n;
    int *off;
    int *tile;
    int *o;
    int *t;

    off = DAT_004592b8[dir][0];
    tile = DAT_00459338[row * 3 + col];
    o = off;
    t = tile;
    n = 4;
    do {
        FUN_0041b6d0_ObjCallUnkInner4(o[0] + x, o[1] + y, *t);
        o += 2;
        t++;
    } while (--n);
    if (dir != 3) {
        x += DAT_00459398[dir][0];
        y += DAT_00459398[dir][1];
        n = 4;
        do {
            FUN_0041b6d0_ObjCallUnkInner4(off[0] + x, off[1] + y, *tile);
            off += 2;
            tile++;
        } while (--n);
    }
}
}
