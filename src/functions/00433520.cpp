extern "C" {
extern "C" int __cdecl FUN_0041E9D0(void**, int);
extern "C" void __cdecl FUN_00433370_Stub(void**);
extern "C" void __cdecl FUN_00419520(void**);

extern "C" void __cdecl ob369Clid_00433520(void** param_1, int* param_2)
{
    int iVar1;
    unsigned int uVar2;

    if (*param_2 != 0) {
        iVar1 = FUN_0041E9D0(param_1, (int)param_2);
        if (iVar1 == 0) {
            uVar2 = *(unsigned int*)param_1[0x5d] & 0xffff;
            if (uVar2 != 5) {
                if (uVar2 == 2 || uVar2 == 0) {
                    *(int*)((char*)param_1[0x5e] + 0xe0) |= 0x8000;
                    FUN_00433370_Stub(param_1);
                }
                FUN_00419520(param_1);
            }
        }
    }
}
}
