extern "C" {
void __cdecl FUN_00423800_pStateUnk(void**);
int __cdecl FUN_00412a00_CheckInput(int);
void __cdecl FUN_004144E0(void**);
void __cdecl FUN_00413BA0(void**);
void __cdecl FUN_00421900(void**);
void __cdecl FUN_00426CA0(void**);
extern int DAT_00458C78;
extern int DAT_00462E80;
extern int DAT_004A022C;
extern int FUN_004A284C;
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;

void __cdecl GEX_Target(void** param1) {
    FUN_00423800_pStateUnk(param1);
    if (DAT_00458C78 != 0 || DAT_004A0294 != 0)
        goto crawl;
    if (DAT_004A0293 != 0 && DAT_004A0295 == 0) {
        param1[0x31] = (void*)(((unsigned int)param1[0x31] + 0x200000) & 0xc00000);
        param1[0x31] = (void*)FUN_00412a00_CheckInput((int)param1);
        FUN_00413BA0(param1);
        return;
    }
    FUN_004A284C = 1;
    param1[0x31] = (void*)DAT_00462E80;
    param1[0x26] = (void*)((int)param1[0x26] + 0x8000);
    if ((int)param1[0x26] >= 0x10000) {
        param1[0x26] = (void*)((int)param1[0x26] - 0x10000);
        param1[0x15] = (void*)((int)param1[0x15] + 1);
        if ((int)param1[0x15] > 7)
            FUN_00426CA0(param1);
        else
            FUN_00421900(param1);
    }
    DAT_004A022C = 1;
    return;
crawl:
    param1[0x31] = (void*)(((unsigned int)param1[0x31] + 0x200000) & 0xc00000);
    param1[0x31] = (void*)FUN_00412a00_CheckInput((int)param1);
    FUN_004144E0(param1);
}
}
