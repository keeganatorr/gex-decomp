// Adapted from pc_decomp_backup/src/functions/FUN_00434190.cpp
// Historical source SHA256: 4aab8288722070b90ff129348792a6f8ff97425e7b4538d8af7efc6dbc9d211a
extern "C" {
extern "C" void __cdecl GEX_Target(void** param1, int param2) {
    void* pGVar4 = param1[0x2a];
    if (param2 != 0) {
        unsigned int uVar6 = (unsigned int)param1[0x2d] & 8;
        do {
            signed char cVar1 = *(signed char*)&((int*)pGVar4)[1];
            signed char cVar2;
            int base;
            if (uVar6 == 0) {
                cVar2 = *(signed char*)((int*)pGVar4 + 2);
                base = (int)pGVar4;
            } else {
                cVar2 = *(signed char*)((int*)pGVar4 + 2);
                base = (int)pGVar4 - 0x30;
            }
            if (cVar1 == -0x7f) {
                param1[0x38] = (void*)((unsigned int)param1[0x38] | 0x20);
                pGVar4 = param1[0x29];
                void* pGVar7;
                if (uVar6 == 0) {
                    cVar1 = *(signed char*)&((int*)pGVar4)[0];
                    cVar2 = *(signed char*)((int*)pGVar4 + 1);
                    pGVar7 = (void*)((int*)pGVar4 + 0);
                } else {
                    pGVar7 = (void*)((int)pGVar4 - 0x48);
                    cVar1 = *(signed char*)&((int*)pGVar7)[1];
                    cVar2 = *(signed char*)((int*)pGVar7 + 2);
                }
                if (((unsigned int)param1[0x2d] & 1) != 0) {
                    param1[0x2a] = pGVar7;
                    param1[0x1d] = (void*)((int)param1[0x1c] + 1);
                    return;
                }
            }
            pGVar4 = (void*)(base + 0x1c);
            int iVar5 = cVar1 * 0x2000000;
            int iVar8 = cVar2 * 0x2000000;
            if (uVar6 != 0) {
                iVar5 = cVar1 * -0x2000000;
                iVar8 = cVar2 * -0x2000000;
            }
            param1[0x1e] = (void*)((int)param1[0x1e] + (iVar5 >> 9) - 0x1c);
            param2--;
            param1[0x1f] = (void*)((int)param1[0x1f] + (iVar8 >> 9) - 0x1c);
        } while (param2 != 0);
    }
    param1[0x2a] = pGVar4;
}
}
