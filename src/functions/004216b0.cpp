extern "C" {
extern int gSplashGlob_004a2410;
extern unsigned int GetTileFlagsAtPosition_00420c10(unsigned int, unsigned int);
extern void* GOB_AddObject_004195d0(int, int, int, int);
extern void SND_PlaySound_0041a340(void*, int);
extern void GOB_PutObjectInfrontOfObject_00419be0(void*, void**);

void __cdecl GEX_Target(void** param_1)
{
    int iVar3;
    unsigned int uVar4;
    void** ppGVar2;

    if (gSplashGlob_004a2410 != 0) {
        uVar4 = (unsigned int)param_1[0x1f] & 0xffe00000;
        iVar3 = 0;
        do {
            if ((GetTileFlagsAtPosition_00420c10((unsigned int)param_1[0x1e], uVar4) & 1) == 0) break;
            uVar4 = uVar4 - 0x200000;
            iVar3 = iVar3 + 1;
        } while (iVar3 < 3);
        if (iVar3 < 3) {
            ppGVar2 = (void**)GOB_AddObject_004195d0(0x5c, (int)param_1[0x1e], uVar4 + 0x240000, gSplashGlob_004a2410);
            if (ppGVar2 != (void**)0x0) {
                ppGVar2[0x26] = (void*)0x3;
                ppGVar2[0x1c] = (void*)0x30;
                SND_PlaySound_0041a340(ppGVar2, 0xfe);
                GOB_PutObjectInfrontOfObject_00419be0(ppGVar2, param_1);
            }
        }
    }
}
}
