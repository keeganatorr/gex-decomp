// Adapted from pc_decomp_backup/src/functions/FUN_00421780.cpp
// Historical source SHA256: f5d9715cc12ff6192507a7b7336c02a1eeef997518d6232679ead469b2e6cf20
extern "C" {
extern "C" { extern int DAT_00463ACC; }
extern void* DAT_004A2990;
extern "C" int __cdecl FUN_0040F030(void*, unsigned int, unsigned int);

extern "C" void __cdecl FUN_00421780_pStateUnk_Fall(void** param_1)
{
    int iVar1;
    int iVar2;

    if (DAT_00463ACC != 0 && param_1[0x20] == (void*)0x0 && param_1[0x22] == (void*)0x0) {
        iVar1 = FUN_0040F030(DAT_004A2990, (unsigned int)((char*)param_1[0x1e] - 0xc0000), (unsigned int)param_1[0x1f]);
        iVar2 = FUN_0040F030(DAT_004A2990, (unsigned int)((char*)param_1[0x1e] + 0xc0000), (unsigned int)param_1[0x1f]);
        if (iVar1 < 0x100000 && iVar1 > -0x100000) {
            param_1[0x20] = (void*)0xfffe0000;
            return;
        }
        if (iVar2 < 0x100000 && iVar2 > -0x100000) {
            param_1[0x20] = (void*)0x20000;
        }
    }
}
}
