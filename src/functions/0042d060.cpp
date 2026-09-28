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
int __cdecl CLD_ComputeAngleEdges_0041cb80(int *, int *);
unsigned char *__cdecl TILES_GetBlockAddress_0042ce70(int, int, int, int);
void __cdecl TILES_CheckHorizForcedScroll_0042cc90(int *, TileFunction);
extern int DAT_004A01EC;
extern int DAT_004A01F0;
extern int DAT_004A01E4;
extern int DAT_004A01E8;
extern int DAT_004A01E0;
extern int *M1_CurrentLevel_004a2990;
extern unsigned char DAT_0045B9AC[];
extern unsigned char DAT_0045B9B0[];
}

extern "C" int __cdecl GEX_Target(void *unused, int *object, TileFunction callback)
{
    int end;
    int right;
    int edges[10];
    int x, y, type;
    unsigned char *block;
    TileFunction handler;

    DAT_004A01EC = 0;
    DAT_004A01F0 = 0;
    DAT_004A01E4 = 0;
    DAT_004A01E8 = -1;
    if (!CLD_ComputeAngleEdges_0041cb80(object, edges))
        return 0;
    right = (object[0x1e] - object[0x35]) >= 0;
    y = edges[8] + 0x80000;
    end = edges[9] - 0x80000;
    for (;;) {
        DAT_004A01EC++;
        CLD_ComputeAngleEdges_0041cb80(object, edges);
        if (right)
            x = edges[7];
        else
            x = edges[6];
        block = TILES_GetBlockAddress_0042ce70(M1_CurrentLevel_004a2990[1], M1_CurrentLevel_004a2990[5], x, y);
        if (block) {
            object[0x61] = x;
            object[0x62] = y;
            type = *(unsigned short *)(block + 6);
            if (type <= 125) {
                if (right)
                    handler = *(TileFunction *)(DAT_0045B9B0 + type * 32);
                else
                    handler = *(TileFunction *)(DAT_0045B9AC + type * 32);
                if (handler && handler(object, block) && callback) {
                    DAT_004A01E4 = 1;
                    if (!callback(object, block))
                        break;
                }
            }
        }
        if (DAT_004A01EC == 1 && !DAT_004A01E0)
            DAT_004A01F0 = 1;
        if (y == end)
            break;
        y += 0x200000;
        if (y > end)
            y = end;
    }
    y = edges[8] + 0x80000;
    for (;;) {
        CLD_ComputeAngleEdges_0041cb80(object, edges);
        if (right)
            x = edges[6];
        else
            x = edges[7];
        block = TILES_GetBlockAddress_0042ce70(M1_CurrentLevel_004a2990[1], M1_CurrentLevel_004a2990[5], x, y);
        if (block) {
            object[0x61] = x;
            object[0x62] = y;
            type = *(unsigned short *)(block + 6);
            if (type <= 125) {
                if (right)
                    handler = *(TileFunction *)(DAT_0045B9AC + type * 32);
                else
                    handler = *(TileFunction *)(DAT_0045B9B0 + type * 32);
                if (handler && handler(object, block) && callback)
                    callback(object, block);
            }
        }
        if (y == end)
            break;
        y += 0x200000;
        if (y > end)
            y = end;
    }
    DAT_004A01E4 = 0;
    CLD_ComputeAngleEdges_0041cb80(object, edges);
    if (right)
        object[0x61] = edges[7];
    else
        object[0x61] = edges[6];
    TILES_CheckHorizForcedScroll_0042cc90(object, callback);
    return 0;
}
