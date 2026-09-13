// Adapted from pc_decomp_backup/src/functions/FUN_0041B500.cpp
// Historical source SHA256: 62d21cb5bc6cfde111b8c55bd21ab2d6a520dd6b4710e92d986883245b1c79be
extern "C" {
extern "C" int __cdecl FUN_0040F170(int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_0041b600_ObjCallUnkInner3(int, int, int, unsigned int, int);
extern "C" void __cdecl FUN_00419520(void**);
extern "C" { extern int DAT_004592b0; }
extern "C" { extern int DAT_0045B9A4; }
extern "C" { extern int DAT_004A23D0; }
extern int FUN_004A2990;
extern "C" void __cdecl GEX_Target(void** param1) {
    void* pGVar1 = param1[0x29];
    void* xPos = param1[0x1e];
    void* yPos = param1[0x1f];
    unsigned int uVar2 = (unsigned int)(param1[0x28] != 0);
    if (param1[0x27] == 0) {
        param1[0x27] = (void*)1;
        uVar2 = FUN_0040F170(FUN_004A2990, (unsigned int)xPos, (unsigned int)yPos);
        void* pGVar3 = *(void**)((int)&DAT_0045B9A4 + uVar2 * 0x20);
        param1[0x28] = pGVar3;
        uVar2 = (unsigned int)(pGVar3 != 0);
        FUN_0041b600_ObjCallUnkInner3((int)xPos, (int)yPos, (int)pGVar1, uVar2, 0);
    }
    void* pGVar3 = (void*)((int)param1[0x26] + 1);
    param1[0x26] = pGVar3;
    if ((int)pGVar3 > DAT_004592b0) {
        param1[0x26] = 0;
        pGVar3 = (void*)((int)param1[0x27] + 1);
        param1[0x27] = pGVar3;
        if (pGVar3 == (void*)6) {
            FUN_0041b600_ObjCallUnkInner3((int)xPos, (int)yPos, (int)pGVar1, uVar2, 2);
            *(int*)((int)&DAT_004A23D0 + (int)param1[0x29] * 4) = 0;
            FUN_00419520(param1);
            return;
        }
        FUN_0041b600_ObjCallUnkInner3((int)xPos, (int)yPos, (int)pGVar1, uVar2, 1);
    }
}
}
