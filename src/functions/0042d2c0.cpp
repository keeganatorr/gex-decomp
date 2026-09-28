typedef int (__cdecl *TileFunction)(int *, unsigned char *);

extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
int __cdecl CLD_ComputeAngleEdges_0041cb80(int *, int *);
unsigned char *__cdecl TILES_GetBlockAddress_0042ce70(int, int, int, int);
void __cdecl FUN_0042CD90(int *, TileFunction);
extern int DAT_004A01EC;
extern int *M1_CurrentLevel_004a2990;
extern unsigned char DAT_0045B9B0[];
}

extern "C" int __cdecl GEX_Target(void *unused, int *object, TileFunction callback)
{
    int end;
    int down;
    int edges[10];
    int x, y, type;
    unsigned char *block;
    TileFunction handler;

    DAT_004A01EC = 0;
    if (!CLD_ComputeAngleEdges_0041cb80(object, edges))
        return 0;
    down = (object[0x1f] - object[0x36]) >= 0;
    y = edges[6] + 0x80000;
    end = edges[7] - 0x80000;
    for (;;) {
        DAT_004A01EC++;
        CLD_ComputeAngleEdges_0041cb80(object, edges);
        if (down)
            x = edges[8];
        else
            x = edges[9];
        block = TILES_GetBlockAddress_0042ce70(M1_CurrentLevel_004a2990[1], M1_CurrentLevel_004a2990[5], y, x);
        if (block) {
            object[0x61] = y;
            object[0x62] = x;
            type = *(unsigned short *)(block + 6);
            if (type <= 125) {
                if (down)
                    handler = *(TileFunction *)(DAT_0045B9B0 + 4 + type * 32);
                else
                    handler = *(TileFunction *)(DAT_0045B9B0 + 8 + type * 32);
                if (handler && handler(object, block) && callback && !callback(object, block))
                    break;
            }
        }
        if (y == end)
            break;
        y += 0x200000;
        if (end < y)
            y = end;
    }
    y = edges[6] + 0x80000;
    for (;;) {
        DAT_004A01EC++;
        CLD_ComputeAngleEdges_0041cb80(object, edges);
        if (down)
            x = edges[9];
        else
            x = edges[8];
        block = TILES_GetBlockAddress_0042ce70(M1_CurrentLevel_004a2990[1], M1_CurrentLevel_004a2990[5], y, x);
        if (block) {
            object[0x61] = y;
            object[0x62] = x;
            type = *(unsigned short *)(block + 6);
            if (type <= 125) {
                if (down)
                    handler = *(TileFunction *)(DAT_0045B9B0 + 8 + type * 32);
                else
                    handler = *(TileFunction *)(DAT_0045B9B0 + 4 + type * 32);
                if (handler && handler(object, block) && callback && !callback(object, block))
                    break;
            }
        }
        if (y == end)
            break;
        y += 0x200000;
        if (end < y)
            y = end;
    }
    CLD_ComputeAngleEdges_0041cb80(object, edges);
    if (down)
        object[0x62] = edges[9];
    else
        object[0x62] = edges[8];
    FUN_0042CD90(object, callback);
    return 0;
}
