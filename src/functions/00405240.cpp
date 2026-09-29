extern "C" {
extern int DAT_0045103C;
extern int DAT_00451794;
extern int *PTR_00487f70;
extern int DAT_00487F88;
extern void __cdecl FUN_004013E0(int);
extern void __cdecl FUN_004048E0();
extern void __cdecl FUN_00402E60();
extern void __cdecl FUN_0040B380();

void __cdecl GamePause_00405240()
{
    int *ppvVar1;
    int iVar2;
    int iVar3;
    int *puVar4;

    if (DAT_00487F88 == 0) {
        if (DAT_00451794 != 0) {
            if (DAT_0045103C == 1) {
                FUN_004013E0(2);
            }
            FUN_004048E0();
            DAT_00487F88 = 1;
            return;
        }
        iVar3 = 0;
        ppvVar1 = PTR_00487f70;
        do {
            puVar4 = (int *)((int)ppvVar1 + iVar3);
            for (iVar2 = 0xa0; iVar2 != 0; iVar2 = iVar2 - 1) {
                *puVar4 = 0;
                puVar4 = puVar4 + 1;
            }
            iVar3 = iVar3 + 0x800;
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