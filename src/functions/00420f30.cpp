// Adapted from pc_decomp_backup/src/functions/FUN_00420F30.cpp
// Historical source SHA256: c31ddca8b8600bf75b6fd42174e44915ef0b32e984e12c4187afdb9ff01141f4
extern "C" {
extern "C" { extern int DAT_004A23F0; }
extern "C" unsigned int __cdecl FUN_00428C60();
extern "C" void** __cdecl FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_0041FA80(int);
extern "C" void __cdecl FUN_00419BE0(void**, void**);
extern "C" { extern int DAT_004A2AC8; }

extern "C" void __cdecl FUN_00420f30(void** param_1)
{
    unsigned int uVar1;
    void** ppGVar2;

    if (DAT_004A23F0 != 0) {
        uVar1 = FUN_00428C60();
        if ((uVar1 & 3) == 0) {
            ppGVar2 = FUN_004195D0(0x5c, (int)param_1[0x1e], (int)param_1[0x1f] + 0x40000, DAT_004A23F0);
            if (ppGVar2 != (void**)0) {
                ppGVar2[0x18] = (void*)0x00420E60;
                if ((DAT_004A2AC8 & 0xf) == 0) {
                    FUN_0041FA80(0x19);
                }
                FUN_00419BE0(ppGVar2, param_1);
            }
        }
    }
}
}
