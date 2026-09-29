typedef int (__cdecl *TileFunction)(int *, unsigned char *);

extern "C" {
int __cdecl CLD_ComputeAngleEdges_0041cb80(int *, int *);
unsigned char *__cdecl TILES_GetBlockAddress_0042ce70(int, int, int, int);
extern int DAT_004a01e4;
extern int *M1_CurrentLevel_004a2990;
extern int DAT_00455b8c_CamX2;
extern int CAMERA_XPos_004a2a38;
extern unsigned char DAT_0045B9AC[];
extern unsigned char DAT_0045B9B0[];
}

extern "C" int __cdecl TILES_CheckOneXPoint_0042cec0(void *unused, int *object, TileFunction callback, int yOffset)
{
    int edges[10];
    int x, y, right, type;
    unsigned char *block;
    TileFunction handler;

    if (!CLD_ComputeAngleEdges_0041cb80(object, edges))
        return 0;

    right = (object[0x1e] - object[0x35]) >= 0;
    DAT_004a01e4 = 0;
    if (right)
        x = edges[7];
    else
        x = edges[6];
    y = object[0x1f] + yOffset;

    block = TILES_GetBlockAddress_0042ce70(M1_CurrentLevel_004a2990[1],
                                          M1_CurrentLevel_004a2990[5], x, y);
    if (block) {
        object[0x61] = x;
        object[0x62] = y;
        type = *(unsigned short *)(block + 6);
        if (type <= 125) {
            if (right)
                handler = *(TileFunction *)(DAT_0045B9B0 + type * 32);
            else
                handler = *(TileFunction *)(DAT_0045B9AC + type * 32);
            if (handler && handler(object, block)) {
                DAT_004a01e4 = 1;
                if (callback)
                    callback(object, block);
            }
        }
    }

    DAT_004a01e4 = 0;
    if (DAT_00455b8c_CamX2) {
        if (!CLD_ComputeAngleEdges_0041cb80(object, edges))
            return 0;
        if (right)
            x = edges[7];
        else
            x = edges[6];
        x -= CAMERA_XPos_004a2a38;
        if (right) {
            if (x >= 0x1300000) {
                object[0x1e] += 0x12f0000 - x;
                DAT_004a01e4 = 1;
                if (callback) {
                    callback(object, 0);
                    return 0;
                }
            }
        } else {
            if (x < 0x100000) {
                object[0x1e] += 0x110000 - x;
                DAT_004a01e4 = 1;
                if (callback)
                    callback(object, 0);
            }
        }
    }
    return 0;
}
