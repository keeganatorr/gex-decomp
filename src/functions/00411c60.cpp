// Adapted from pc_decomp_backup/src/functions/FUN_00411C60.cpp
// Historical source SHA256: 0ba56db8a25fbb2988e897ae916ffca97781cb82acebd05ce37f4fbdd52c0901
extern "C" {
extern "C" int __cdecl FUN_00421f20_pStateUnk_Side(void**);
extern "C" void __cdecl FUN_00411160(void**);
extern "C" { extern int DAT_00458208; }
extern "C" { extern int DAT_004582a8; }
extern "C" { extern int DAT_00458328; }
extern "C" { extern int DAT_00457fe8; }
extern "C" void __cdecl GEX_Target(void** param1) {
    int iVar2 = FUN_00421f20_pStateUnk_Side(param1);
    if (iVar2 != 0) {
        void* pGVar3 = param1[0x26];
        void* pGVar5 = (void*)((int)pGVar3 + 0x40);
        param1[0x26] = pGVar5;
        if ((int)pGVar5 > 0x10000) {
            unsigned int uVar6 = ((unsigned int)param1[0x1b] & 0x80000000) >> 0x1c | (int)param1[0x31] >> 0x15;
            void* pGVar4 = (void*)((int)param1[0x15] + 1);
            param1[0x26] = (void*)((int)pGVar3 + -0x40);
            param1[0x15] = pGVar4;
            pGVar5 = (void*)((int)param1[0x1e] + *(int*)((int)&DAT_00458208 + ((int)pGVar4 + *(int*)((int)&DAT_004582a8 + uVar6 * 8) * 5 + -0x1c) * 4) + -0x1c);
            param1[0x1e] = pGVar5;
            pGVar3 = (void*)((int)param1[0x1f] + *(int*)((int)&DAT_00458208 + ((int)pGVar4 + *(int*)((int)&DAT_004582a8 + 4 + uVar6 * 8) * 5 + -0x1c) * 4) + -0x1c);
            param1[0x1f] = pGVar3;
            if ((int)pGVar4 > 3) {
                uVar6 = *(unsigned int*)((int)&DAT_00458328 + uVar6 * 4);
                pGVar4 = (void*)((unsigned int)param1[0x1b] & 0x7fffffff);
                param1[0x1b] = pGVar4;
                param1[0x31] = (void*)((uVar6 & 7) << 0x15);
                if ((uVar6 & 8) != 0) param1[0x1b] = (void*)((unsigned int)pGVar4 | 0x80000000);
                int p5 = (int)pGVar5 & 0xffe00000;
                int p3 = (int)pGVar3 & 0xffe00000;
                param1[0x1e] = (void*)p5;
                unsigned int uVar1 = *(unsigned int*)((int)&DAT_00457fe8 + uVar6 * 8);
                param1[0x1f] = (void*)p3;
                param1[0x1e] = (void*)(uVar1 | (unsigned int)p5);
                param1[0x1f] = (void*)(*(unsigned int*)((int)&DAT_00457fe8 + 4 + uVar6 * 8) | (unsigned int)p3);
                FUN_00411160(param1);
            }
        }
    }
}
}
