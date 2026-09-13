// Adapted from pc_decomp_backup/src/functions/FUN_00411A90.cpp
// Historical source SHA256: d14d0277a129292d339ef38a505d604cf1bb2d25aaf1d10d3ea928f35e717a38
extern "C" {
extern "C" int __cdecl FUN_00421f20_pStateUnk_Side(void**);
extern "C" void __cdecl FUN_00411160(void**);
extern "C" { extern int DAT_004580a8; }
extern "C" { extern int DAT_00458148; }
extern "C" { extern int DAT_004581c8; }
extern "C" { extern int DAT_00457fe8; }
extern "C" void __cdecl GEX_Target(void** param1) {
    int iVar2 = FUN_00421f20_pStateUnk_Side(param1);
    if (iVar2 != 0) {
        void* pGVar3 = param1[0x26];
        void* pGVar5 = (void*)((int)pGVar3 + 0x40);
        param1[0x26] = pGVar5;
        if ((int)pGVar5 > 0x10000) {
            unsigned int uVar4 = ((unsigned int)param1[0x1b] & 0x80000000) >> 0x1c | (int)param1[0x31] >> 0x15;
            void* pGVar6 = (void*)((int)param1[0x15] + 1);
            param1[0x26] = (void*)((int)pGVar3 + -0x40);
            param1[0x15] = pGVar6;
            pGVar5 = (void*)((int)param1[0x1e] + *(int*)((int)&DAT_004580a8 + ((int)pGVar6 + *(int*)((int)&DAT_00458148 + uVar4 * 8) * 5 + -0x1c) * 4) + -0x1c);
            param1[0x1e] = pGVar5;
            pGVar3 = (void*)((int)param1[0x1f] + *(int*)((int)&DAT_004580a8 + ((int)pGVar6 + *(int*)((int)&DAT_00458148 + 4 + uVar4 * 8) * 5 + -0x1c) * 4) + -0x1c);
            param1[0x1f] = pGVar3;
            if ((int)pGVar6 > 3) {
                uVar4 = *(unsigned int*)((int)&DAT_004581c8 + uVar4 * 4);
                pGVar6 = (void*)((unsigned int)param1[0x1b] & 0x7fffffff);
                param1[0x1b] = pGVar6;
                param1[0x31] = (void*)((uVar4 & 7) << 0x15);
                if ((uVar4 & 8) != 0) param1[0x1b] = (void*)((unsigned int)pGVar6 | 0x80000000);
                int pGVar5_int = (int)pGVar5 & 0xffe00000;
                int pGVar3_int = (int)pGVar3 & 0xffe00000;
                param1[0x1e] = (void*)pGVar5_int;
                unsigned int uVar1 = *(unsigned int*)((int)&DAT_00457fe8 + uVar4 * 8);
                param1[0x1f] = (void*)pGVar3_int;
                param1[0x1e] = (void*)(uVar1 | (unsigned int)pGVar5_int);
                param1[0x1f] = (void*)(*(unsigned int*)((int)&DAT_00457fe8 + 4 + uVar4 * 8) | (unsigned int)pGVar3_int);
                FUN_00411160(param1);
            }
        }
    }
}
}
