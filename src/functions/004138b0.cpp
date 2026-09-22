struct SideJumpData
{
    unsigned int flags;
    int value;
    int extra;
};

extern "C" void __cdecl FUN_00420BC0(int *);
extern "C" unsigned int __cdecl FUN_004218a0_CheckWallCollision(int *);
extern "C" int __cdecl FUN_00421f90(int *);
extern "C" void __cdecl FUN_0041FA80(int);
extern "C" void __cdecl PlayerSideJump_00413730(int *);

extern "C" SideJumpData DAT_004587D8[];
extern "C" unsigned char DAT_004A0280;
extern "C" unsigned char DAT_004A0281;
extern "C" unsigned char DAT_004A0282;
extern "C" int DAT_004A0264;
extern "C" int DAT_004A2864;
extern "C" int DAT_004A025C;

extern "C" void __cdecl GEX_Target(int *param_1)
{
    int bVar1;
    unsigned int uVar2;
    int iVar3;
    unsigned int uVar4;

    FUN_00420BC0(param_1);
    uVar2 = FUN_004218a0_CheckWallCollision(param_1);
    if (uVar2 != 0 && FUN_00421f90(param_1) != 0)
        return;

    param_1[28] = 77;
    param_1[20] = 86;
    param_1[21] = 0;
    param_1[38] = 0;
    param_1[40] = 0;
    param_1[32] = 0;
    param_1[35] = 0;
    param_1[34] = 0;
    param_1[33] = 0xA0000;

    uVar4 = (((unsigned int)param_1[27] & 0x80000000U) >> 28) |
            (unsigned int)(param_1[49] >> 21);

    param_1[37] = 0x14000;
    param_1[36] = 0xE0000;

    uVar2 = DAT_004587D8[uVar4].flags;
    iVar3 = DAT_004587D8[uVar4].value;

    if ((((uVar2 & 0x1000U) == 0) || (DAT_004A0280 == 0)) &&
        (((uVar2 & 0x100U) == 0) || (DAT_004A0281 == 0)))
        bVar1 = 0;
    else
        bVar1 = 1;

    param_1[41] = DAT_004587D8[uVar4].extra;

    if ((uVar2 & 0x1000U) != 0)
        param_1[32] = bVar1 ? -0xA0000 : -0x10000;

    if ((uVar2 & 0x100U) != 0)
        param_1[32] = bVar1 ? 0xA0000 : 0x10000;

    if ((uVar2 & 0x10U) != 0)
        param_1[35] = bVar1 ? -0x100000 : -0x80000;

    if ((uVar2 & 1U) != 0)
        param_1[35] = bVar1 ? 0xA0000 : 0x80000;

    if ((uVar2 & 0x10000U) != 0)
        param_1[35] += DAT_004A0282 ? -0x100000 : -0x80000;

    if (DAT_004A0264 != 0)
    {
        param_1[32] = (param_1[32] >> 8) * 0x180;
        param_1[35] = (param_1[35] >> 8) * 0x180;
    }

    param_1[39] = (iVar3 * 0x10000) / 8;
    FUN_0041FA80(12);

    DAT_004A2864 = 0;
    param_1[42] = param_1[32];
    param_1[43] = param_1[35];
    DAT_004A025C = -0x20000;
    param_1[55] = -0x20000;
    PlayerSideJump_00413730(param_1);
}
