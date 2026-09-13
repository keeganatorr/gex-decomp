// Adapted from pc_decomp_backup/src/functions/FUN_00428FA0.cpp
// Historical source SHA256: f601b0831fcaec8841f48066a5f9c772229604896d8dc1f846390eb53a8d387d
extern "C" {
extern "C" void __cdecl FUN_00428cf0(int *);
extern "C" void __cdecl FUN_00428e50(int *);

extern "C" void __cdecl GEX_Target(unsigned short *param_1, unsigned short *param_2, int param_3, int param_4, int param_5)
{
    unsigned short uVar1;
    int iVar2, iVar3, iVar4, iVar5;
    unsigned int local_18, local_14, local_10;
    int local_c, local_8, local_4;

    iVar2 = (param_4 * 0xff) / 100;
    iVar3 = (param_5 * 0xff) / 100;

    *(unsigned int *)(param_2 - 2) = *(unsigned int *)(param_1 - 2) | 0xffffff00;

    if ((param_3 != 0 || iVar2 != 0 || iVar3 != 0) &&
        (iVar5 = (-(unsigned int)((char)*(param_2 - 2) == 0) & 0xffffff10) + 0x100, iVar5 > 0))
    {
        do {
            uVar1 = *param_1;
            param_1 = param_1 + 1;
            if (uVar1 == 0) {
                *param_2 = 0;
            } else {
                local_18 = ((unsigned int)(uVar1 & 0x1f) * 0xff) / 0x1f;
                local_14 = ((unsigned int)((uVar1 & 0x3e0) >> 5) * 0xff) / 0x1f;
                local_10 = ((unsigned int)((uVar1 & 0x7c00) >> 10) * 0xff) / 0x1f;

                FUN_00428cf0((int *)&local_18);

                local_c = (local_c + 0x168 + param_3) % 0x168;

                iVar4 = local_8;
                if (iVar2 >= 0) {
                    iVar4 = 0xff - local_8;
                }
                local_8 = local_8 + (iVar2 * iVar4) / 0xff;
                if (local_8 > 0xfe) local_8 = 0xff;
                if (local_8 < 1) local_8 = 0;

                iVar4 = local_4;
                if (iVar3 >= 0) {
                    iVar4 = 0xff - local_4;
                }
                local_4 = local_4 + (iVar3 * iVar4) / 0xff;
                if (local_4 > 0xfe) local_4 = 0xff;
                if (local_4 < 1) local_4 = 0;

                FUN_00428e50((int *)&local_18);

                *param_2 = (unsigned short)(
                    ((((unsigned short)local_10 & 0xfff8) << 5 | (unsigned short)local_14 & 0xfff8 | 0xe000) << 2) |
                    (unsigned short)((int)local_18 >> 3)
                );
            }
            param_2 = param_2 + 1;
            iVar5 = iVar5 - 1;
        } while (iVar5 != 0);
    }
}
}
