// Adapted from pc_decomp_backup/src/functions/FUN_0040C210.cpp
// Historical source SHA256: aa191d3cefec6e48d5bf18606cb0319a591e440b409ae4d5c0aaf0ebf6c6d3bb
extern "C" {
extern "C" { extern int DAT_004A2918; }
extern "C" { extern int DAT_004A291C; }
extern "C" { extern int DAT_004A2920; }
extern "C" { extern int DAT_004A2964; }
extern "C" { extern int DAT_004A2994; }
extern "C" { extern int DAT_004A2A7C; }
extern "C" void __cdecl FUN_0040C2C0(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    void* pGVar1;
    void* pGVar2;

    DAT_004A2A7C = 1;
    DAT_004A2994 = 0;
    pGVar1 = param_1[0x2b];
    if (pGVar1 == (void*)1) {
        pGVar2 = param_1[0x26];
        if (pGVar2 == (void*)2) {
            if (DAT_004A291C == 0) {
                param_1[0x2c] = (void*)0;
            } else {
                param_1[0x2c] = (void*)1;
            }
        } else if (pGVar2 == (void*)4) {
            if (DAT_004A2920 == 0) {
                param_1[0x2c] = (void*)0;
            } else {
                param_1[0x2c] = (void*)1;
            }
        } else if (pGVar2 == (void*)6) {
            if (DAT_004A2918 == 0) {
                param_1[0x2c] = (void*)0;
            } else {
                param_1[0x2c] = (void*)1;
            }
        } else {
            param_1[0x2c] = (void*)1;
        }
    } else if (pGVar1 == (void*)2) {
        param_1[0x2c] = (void*)0;
    } else {
        param_1[0x2c] = (void*)0;
    }
    if (DAT_004A2964 == 0x41 && (param_1[0x26] == (void*)2 || param_1[0x26] == (void*)1)) {
        param_1[0x15] = (void*)0;
    } else {
        param_1[0x15] = (void*)-1;
    }
    if (pGVar1 == (void*)3) {
        FUN_0040C2C0(param_1);
    }
}
}
