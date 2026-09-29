// Reconstructed from pinned assembly / pseudocode for PlayerStandJumpStart_00424ae0
extern "C" {
extern void* DAT_004A2990;
extern "C" void __cdecl FUN_004213F0(int*);
extern "C" void __cdecl FUN_004213C0(void*, int*);
extern "C" int  __cdecl FUN_00421560(void*, int*);
extern "C" void __cdecl FUN_00424E50(int*);

// Fields are 32-bit; indices are byte-offset/4:
//   0x26 -> 0x98, 0x15 -> 0x54, 0x20 -> 0x80
extern "C" void __cdecl PlayerStandJumpStart_00424ae0(int* param_1)
{
    int pGVar2;
    int iVar1;

    if (param_1[0x26] != 0) {
        param_1[0x26]--;
    } else {
        param_1[0x26] = 0;
        if (++param_1[0x15] == 2) {
            FUN_00424E50(param_1);
            return;
        }
    }

    pGVar2 = param_1[0x20];
    param_1[0x20] = (pGVar2 > 0) - (pGVar2 < 0);

    FUN_004213F0(param_1);
    FUN_004213C0(DAT_004A2990, param_1);
    param_1[0x20] = pGVar2;

    iVar1 = FUN_00421560(DAT_004A2990, param_1);
    if (iVar1 == 0) {
        FUN_00424E50(param_1);
    }
}
}
