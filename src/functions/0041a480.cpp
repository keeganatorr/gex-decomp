// Adapted from pc_decomp_backup/src/functions/FUN_0041A480.cpp
// Historical source SHA256: fc63cb3013f45f2f59e9a8103b5ed85135b502f9ccfd93c92c46bd0801ccd42b
extern "C" {
extern "C" void __cdecl FUN_00405350(const char*, int);

extern "C" int __cdecl GEX_Target(int param_1)
{
    int* piVar1;
    int iVar2;
    int iVar3;
    int result;

    result = 0;
    piVar1 = *(int**)(param_1 + 0xc);
    if (piVar1 != 0) {
        iVar2 = *(int*)(param_1 + 0x54);
        if (iVar2 >= 0) {
            iVar3 = *(int*)(param_1 + 0x50);
            if (iVar3 >= 0) {
                if (piVar1[2] != 0) {
                    if (piVar1[3] <= iVar3) {
                        FUN_00405350((const char*)0x00458FB0, *(int*)(param_1 + 8));
                        return 0;
                    }
                    if (*(int*)(piVar1[4] + iVar3 * 4) < iVar2) {
                        FUN_00405350((const char*)0x00458F78, *(int*)(param_1 + 8));
                        return 0;
                    }
                }
                result = *(int*)(*(int*)(*piVar1 + iVar3 * 4) + iVar2 * 4);
            }
        }
    }
    return result;
}
}
