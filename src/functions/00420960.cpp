extern "C" {
int __cdecl CLD_ComputeAngleEdges_0041cb80(int *, int *);
int __cdecl FUN_004207e0_GOB_KeepOutOfTiles_Inner(int, int);
void __cdecl GOB_KeepRight_004208a0(int *, int *);
void __cdecl GOB_KeepLeft_004208d0(int *, int *);
void __cdecl FUN_004208f0_ypos(int *, int *);
void __cdecl FUN_00420920_ypos(int *, int *);
void __cdecl assertfail_00405350(char *, ...);
extern char s_GOB_KeepOutOfTiles_ERROR_0045aa9c[];

void __cdecl GOB_KeepOutOfTiles_00420960(int *gob)
{
    int edges[10];
    unsigned int hits;
    if (!CLD_ComputeAngleEdges_0041cb80(gob, edges))
        return;
    hits = FUN_004207e0_GOB_KeepOutOfTiles_Inner(edges[6], edges[8]) ? 1 : 0;
    hits |= FUN_004207e0_GOB_KeepOutOfTiles_Inner(edges[7], edges[8]) ? 0x10 : 0;
    hits |= FUN_004207e0_GOB_KeepOutOfTiles_Inner(edges[6], edges[9]) ? 0x100 : 0;
    hits |= FUN_004207e0_GOB_KeepOutOfTiles_Inner(edges[7], edges[9]) ? 0x1000 : 0;
    switch (hits) {
    case 0x1:
    case 0x100:
    case 0x101:
        GOB_KeepRight_004208a0(gob, edges);
        break;
    case 0x10:
    case 0x1000:
    case 0x1010:
        GOB_KeepLeft_004208d0(gob, edges);
        break;
    case 0x11:
        FUN_004208f0_ypos(gob, edges);
        break;
    case 0x110:
    case 0x111:
        GOB_KeepRight_004208a0(gob, edges);
        FUN_004208f0_ypos(gob, edges);
        break;
    case 0x1001:
    case 0x1011:
        GOB_KeepLeft_004208d0(gob, edges);
        FUN_004208f0_ypos(gob, edges);
        break;
    case 0x1100:
        FUN_00420920_ypos(gob, edges);
        break;
    case 0x1101:
        GOB_KeepRight_004208a0(gob, edges);
        FUN_00420920_ypos(gob, edges);
        break;
    case 0x1110:
        GOB_KeepLeft_004208d0(gob, edges);
        FUN_00420920_ypos(gob, edges);
        break;
    case 0x1111:
        assertfail_00405350(s_GOB_KeepOutOfTiles_ERROR_0045aa9c);
        break;
    }
}
}
