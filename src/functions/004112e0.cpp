// Adapted from pc_decomp_backup/src/functions/FUN_004112E0.cpp
// Historical source SHA256: 722c4093e824dcfbf4fd966c468457dd1a3f880a25991b4d8a6112b58fe6414b
extern "C" {
extern "C" { extern int DAT_00458B90; }
extern void* DAT_004A2864;
extern "C" void __cdecl FUN_00405350(int, int);
extern "C" int __cdecl FUN_00411230(void*, int**, int**, int**);

extern "C" void __cdecl GEX_Target(void** param_1, unsigned int param_2)
{
    int iVar1;
    int local_30;
    int local_2c;
    int local_28[6];
    int local_10;
    int local_c;
    int local_4;

    if (param_2 == 0xffffffff) {
        FUN_00405350((int)&DAT_00458B90, 0);
        return;
    }
    iVar1 = FUN_00411230(DAT_004A2864, (int**)local_28, (int**)&local_2c, (int**)&local_30);
    if (iVar1 != 0) {
        if ((param_2 & 1) != 0) {
            local_10 = local_c - 0x1f0000;
        }
        param_1[0x1e] = (void*)local_10;
        if ((param_2 & 0x10) != 0) {
            param_1[0x1f] = (void*)(local_4 - 0x1f0000);
            return;
        }
        if ((param_2 & 1) != 0) {
            param_1[0x1f] = (void*)local_30;
            return;
        }
        param_1[0x1f] = (void*)local_2c;
    }
}
}
