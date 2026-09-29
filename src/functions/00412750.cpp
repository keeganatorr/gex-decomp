extern "C" {
void __cdecl FUN_00420BC0(void**);
void __cdecl FUN_00412630(void**);
int __cdecl FUN_00420c40_CheckWallCollision(int, unsigned int, unsigned int);
extern int FUN_004A2990;
extern int FUN_004A2864;
extern int DAT_004586d8[];
extern int DAT_004586dc[];
}

extern "C" void __cdecl InitPlayerSideUTurn_00412750(void** param_1)
{
    unsigned int uVar1;
    unsigned int uVar2;

    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x47;
    param_1[0x14] = (void*)0x4e;
    uVar2 = ((((unsigned int)param_1[0x1b] & 0x80000000) ? 8 : 0)) | ((int)param_1[0x31] >> 0x15);
    param_1[0x26] = (void*)0;
    param_1[0x27] = (void*)0;
    param_1[0x15] = (void*)0;
    if (((uVar2 & 1) == 0) && (FUN_004A2864 == 0)) {
        uVar1 = FUN_00420c40_CheckWallCollision(
            FUN_004A2990,
            (unsigned int)((int)param_1[0x1e] + DAT_004586d8[uVar2 * 2] * 0x2D0000),
            (unsigned int)((int)param_1[0x1f] + DAT_004586dc[uVar2 * 2] * 0x2D0000));
        if (uVar1 == 0x15) {
            param_1[0x27] = (void*)(uVar2 | 0x10);
        }
    }
    FUN_00412630(param_1);
}
