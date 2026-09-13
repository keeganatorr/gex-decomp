// Adapted from pc_decomp_backup/src/functions/FUN_00431830.cpp
// Historical source SHA256: 92b3016342ce617791fcc4933203a87efb72b8c2943b2eebc6af8f99c9efa5da
extern "C" {
extern "C" int __cdecl FUN_0040F170(int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_0042CEC0(int, void**, void*, int);
extern "C" { extern int FUN_004A2990; }
extern "C" { extern unsigned int DAT_0045B9A0[]; }
extern "C" { extern int DAT_00463FE0; }

extern "C" void __cdecl GEX_Target(void** param1, unsigned int param2, unsigned int param3) {
    DAT_00463FE0 = 0;
    unsigned int uVar5 = FUN_0040F170(FUN_004A2990, param2, param3);
    if ((DAT_0045B9A0[uVar5 * 8] & 0x80000000) != 0) {
        void* pGVar1 = param1[0x1e];
        void* pGVar2 = param1[0x1f];
        void* pGVar3 = param1[0x35];
        void* pGVar4 = param1[0x36];
        param1[0x1e] = (void*)param2;
        param1[0x1f] = (void*)param3;
        param1[0x35] = (void*)(param2 - (unsigned int)param1[0x20]);
        param1[0x36] = (void*)(param3 - (unsigned int)param1[0x23]);
        DAT_00463FE0 = 0;
        FUN_0042CEC0(FUN_004A2990, param1, 0, 0);
        param1[0x1e] = pGVar1;
        param1[0x1f] = pGVar2;
        param1[0x35] = pGVar3;
        param1[0x36] = pGVar4;
    }
}
}
