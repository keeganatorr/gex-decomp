// Adapted from pc_decomp_backup/src/functions/FUN_0043AC60.cpp
// Historical source SHA256: 0cff339132ffe073a3ffa4d1df0c3b4f690b6c83c46dcd9e7450d7ee60314ead
extern "C" {
extern "C" { extern int DAT_004593BC; }
extern "C" { extern int DAT_004593C4; }

extern "C" void __cdecl FUN_0043ac60_GameFuncUnk(int param_1)
{
    if (DAT_004593C4 == 2) {
        int iVar1 = *(int*)(param_1 + 0x9c) - 1;
        *(int*)(param_1 + 0x9c) = iVar1;
        if (iVar1 == 0) {
            DAT_004593BC -= 1;
            if (DAT_004593BC == 0) {
                DAT_004593C4 = 3;
            }
            *(int*)(param_1 + 0x9c) = 0x1e;
        }
    }
}
}
