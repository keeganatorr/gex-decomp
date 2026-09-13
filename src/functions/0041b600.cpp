// Adapted from pc_decomp_backup/src/functions/FUN_0041B600.cpp
// Historical source SHA256: 454434ec3847923d5d5125b738a66d264058c2b46fd183cf4ccd15f729f4c9d9
extern "C" {
extern "C" void __cdecl FUN_0041b6d0_ObjCallUnkInner4(int, int, int);
extern "C" { extern int DAT_004592b8; }
extern "C" { extern int DAT_00459338; }
extern "C" { extern int DAT_00459398; }
extern "C" void __cdecl GEX_Target(int p1, int p2, int p3, int p4, int p5) {
    int* piVar7 = (int*)((int)&DAT_00459338 + (p4 * 3 + p5) * 0x10);
    int* piVar4 = (int*)((int)&DAT_004592b8 + p3 * 0x20);
    int* piVar6 = piVar7;
    int local_4 = 4;
    do {
        int val = *piVar6++;
        FUN_0041b6d0_ObjCallUnkInner4(*piVar4 + p1, piVar4[1] + p2, val);
        local_4--;
        piVar4 += 2;
    } while (local_4 != 0);
    if (p3 != 3) {
        int iVar1 = *(int*)((int)&DAT_00459398 + p3 * 8);
        int iVar2 = *(int*)((int)&DAT_00459398 + 4 + p3 * 8);
        int iVar5 = 4;
        piVar4 = (int*)((int)&DAT_004592b8 + p3 * 0x20);
        do {
            int iVar3 = *piVar7++;
            FUN_0041b6d0_ObjCallUnkInner4(*piVar4 + p1 + iVar1, piVar4[1] + p2 + iVar2, iVar3);
            iVar5--;
            piVar4 += 2;
        } while (iVar5 != 0);
    }
}
}
