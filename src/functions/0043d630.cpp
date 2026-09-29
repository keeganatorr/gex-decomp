// Adapted from pc_decomp_backup/src/functions/FUN_0043D630.cpp
// Historical source SHA256: 26ccb04a5ac9f40f653ad33861587a555cfe4da47b757b0fa6aa9a4250fa1dcc
extern "C" {
extern "C" { extern int DAT_0045A3C8[]; }
extern "C" { extern int DAT_0045A5C8[]; }
extern "C" { extern int DAT_0045A7C8[]; }
extern "C" { extern int DAT_0045A9C8[]; }
extern "C" { extern int DAT_004A2AC8; }
extern "C" int __cdecl FUN_0040FCE0(void**);

extern "C" void __cdecl ob218DoIt_0043d630(void** param_1)
{
    int iVar1;
    unsigned int uVar2;
    void* pGVar3;
    
    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = 0;
    pGVar3 = param_1[0x38];
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    pGVar3 = (void*)((((int)pGVar3 * 2 ^ (unsigned int)pGVar3) & 0x200) ^ (unsigned int)pGVar3);
    param_1[0x38] = pGVar3;
    param_1[0x38] = (void*)((unsigned int)pGVar3 & 0xfffffeff);
    
    iVar1 = FUN_0040FCE0(param_1);
    if (iVar1 != 0) goto LAB_EXIT;
    
    if (param_1[0x20] != 0) {
        pGVar3 = (void*)((int)param_1[0x23] + (int)param_1[0x20] - 0x10);
        param_1[0x23] = pGVar3;
        if ((int)pGVar3 > 0xffff) {
            param_1[0x23] = (void*)((int)pGVar3 - 0x80);
            param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        }
    }
    
    pGVar3 = param_1[0x2c];
    if (pGVar3 != 0) {
        if (((unsigned int)param_1[0x2d] & 1) == 0) {
            uVar2 = ((((int)param_1[0x26] >> 0x10) + DAT_004A2AC8 & 0xffffU) * (int)param_1[0x2a] & 0x1ff0000) >> 0x10;
            if (uVar2 > 0xff) uVar2 = 0x200 - uVar2;
            iVar1 = (int)pGVar3 * (int)uVar2 * 0x100 + (int)pGVar3 * -0x8000;
        } else {
            uVar2 = ((((int)param_1[0x26] >> 0x10) + DAT_004A2AC8 & 0xffffU) * (int)param_1[0x2a] & 0xff0000) >> 0x10;
            if (uVar2 < 0x101) {
                if (uVar2 > 0x80) {
                    if ((int)(uVar2 - 0x80) > 0x40) goto LAB_TRIG1_ALT;
                    iVar1 = DAT_0045A3C8[uVar2 + 1];
                    goto LAB_TRIG1_END;
                }
                if (uVar2 < 0x41) iVar1 = DAT_0045A5C8[uVar2];
                else iVar1 = DAT_0045A7C8[(int)-uVar2];
            } else if (uVar2 < 0x81) {
                if (uVar2 < 0x41) iVar1 = DAT_0045A5C8[uVar2];
                else iVar1 = DAT_0045A7C8[(int)-uVar2];
            } else {
                if ((int)(uVar2 - 0x80) < 0x41) iVar1 = DAT_0045A3C8[uVar2 + 1];
                else {
LAB_TRIG1_ALT:
                    iVar1 = DAT_0045A9C8[(int)-uVar2];
                }
LAB_TRIG1_END:
                iVar1 = -iVar1;
            }
            iVar1 = ((int)pGVar3 >> 1) * iVar1;
        }
        param_1[0x1e] = (void*)((int)param_1[0x28] + iVar1 - 0x1c);
    }
    
    pGVar3 = param_1[0x2b];
    if (pGVar3 == 0) goto LAB_EXIT;
    
    if (((unsigned int)param_1[0x2d] & 2) == 0) {
        uVar2 = ((((int)param_1[0x26] + DAT_004A2AC8 - 0x1c & 0xffffU) * (int)param_1[0x29] & 0x1ff0000) >> 0x10);
        if (uVar2 > 0xff) uVar2 = 0x200 - uVar2;
        iVar1 = (int)uVar2 * (int)pGVar3 * 0x100 + (int)pGVar3 * -0x8000;
    } else {
        uVar2 = ((((int)param_1[0x26] + DAT_004A2AC8 - 0x1c & 0xffffU) * (int)param_1[0x29] & 0xff0000) >> 0x10);
        if (uVar2 < 0x101) {
            if (uVar2 > 0x80) {
                if ((int)(uVar2 - 0x80) > 0x40) goto LAB_TRIG2_ALT;
                iVar1 = DAT_0045A3C8[uVar2 + 1];
                goto LAB_TRIG2_END;
            }
            if (uVar2 < 0x41) iVar1 = DAT_0045A5C8[uVar2];
            else iVar1 = DAT_0045A7C8[(int)-uVar2];
        } else if (uVar2 < 0x81) {
            if (uVar2 < 0x41) iVar1 = DAT_0045A5C8[uVar2];
            else iVar1 = DAT_0045A7C8[(int)-uVar2];
        } else {
            if ((int)(uVar2 - 0x80) < 0x41) iVar1 = DAT_0045A3C8[uVar2 + 1];
            else {
LAB_TRIG2_ALT:
                iVar1 = DAT_0045A9C8[(int)-uVar2];
            }
LAB_TRIG2_END:
            iVar1 = -iVar1;
        }
        iVar1 = ((int)pGVar3 >> 1) * iVar1;
    }
    param_1[0x1f] = (void*)((int)param_1[0x27] + iVar1 - 0x1c);
    
LAB_EXIT:
    if (param_1[0x45] == (void*)-1) param_1[0x44] = 0;
    param_1[0x45] = (void*)-1;
}
}
