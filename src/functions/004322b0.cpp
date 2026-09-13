// Adapted from pc_decomp_backup/src/functions/FUN_004322B0.cpp
// Historical source SHA256: 8b87da16fe2af6243a90375b33ede8c34952f2cdd7ab6103d5b161a19477cd96
extern "C" {
extern "C" void __cdecl FUN_00431730(void**);
extern "C" void** __cdecl FUN_0041A380(void**);
extern "C" void __cdecl FUN_0041E7C0(void**);
extern "C" void __cdecl FUN_004322a0();

extern "C" void __cdecl GEX_Target(void** param1, int param2)
{
    if (param1[0x59] != 0) GEX_Target((void**)param1[0x59], param2);
    if (param1[0x58] != 0) GEX_Target((void**)param1[0x58], param2);
    FUN_00431730(param1);
    param1[0x17] = 0;
    param1[0x19] = 0;
    param1[0x26] = (void*)param2;
    param1[0x27] = 0;
    param1[0x18] = (void*)FUN_004322a0;
    param1[0x28] = 0;
    void** ppGVar1 = FUN_0041A380(param1);
    int g2, g3, g4, g5;
    if (((unsigned int)param1[0x1b] & 0x80000000) == 0) {
        g2 = (int)ppGVar1[0];
        g3 = (int)ppGVar1[2];
    } else {
        g2 = -(int)ppGVar1[2];
        g3 = -(int)ppGVar1[0];
    }
    if (((unsigned int)param1[0x1b] & 0x40000000) == 0) {
        g4 = (int)ppGVar1[1];
        g5 = (int)ppGVar1[3];
    } else {
        g4 = -(int)ppGVar1[3];
        g5 = -(int)ppGVar1[1];
    }
    g3 = (g3 + (1 - g2)) >> 1;
    g5 = (g5 + (1 - g4)) >> 1;
    param1[0x2a] = (void*)(g3 + (g2 - 1) + -0xc);
    param1[0x2b] = (void*)(g5 + (g4 - 1) + -0xc);
    param1[0x2c] = (void*)g3;
    param1[0x2d] = (void*)g5;
    FUN_0041E7C0(param1);
}
}
