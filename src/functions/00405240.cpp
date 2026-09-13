// Adapted from pc_decomp_backup/src/functions/FUN_00405240.cpp
// Historical source SHA256: 21f0c49bb88c2bf0393bf06064222ab16f7afbc183570b52f512f17a49ae79d9
extern "C" {
extern "C" { extern int DAT_0045103C; }
extern "C" { extern int DAT_00451794; }
extern "C" { extern int DAT_00487F70; }
extern "C" { extern int DAT_00487F88; }
extern "C" void __cdecl FUN_004013E0(int);
extern "C" void __cdecl FUN_004048E0();
extern "C" void __cdecl FUN_00402E60();
extern "C" void __cdecl FUN_0040B380();

extern "C" void __cdecl GEX_Target()
{
    int* ppvVar1;
    int iVar2;
    int iVar3;

    if (DAT_00487F88 == 0) {
        if (DAT_00451794 != 0) {
            if (DAT_0045103C == 1) {
                FUN_004013E0(2);
            }
            FUN_004048E0();
            DAT_00487F88 = 1;
            return;
        }
        ppvVar1 = (int*)&DAT_00487F70;
        iVar3 = 0;
        do {
            for (iVar2 = 0xa0; iVar2 != 0; iVar2 = iVar2 - 1) {
                *(int*)((int)ppvVar1 + iVar3) = 0;
                iVar3 = iVar3 + 4;
            }
            iVar3 = iVar3 + 0x800 - 0xa0 * 4;
        } while (iVar3 != 0x78000);
        if (DAT_0045103C == 1) {
            FUN_004013E0(2);
        }
        FUN_00402E60();
        FUN_0040B380();
        DAT_00487F88 = 1;
    }
}
}
