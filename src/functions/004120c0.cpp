extern "C" {
void __cdecl FUN_00420BC0(void**);
int __cdecl FUN_00421560_DrawCharacter(int, void**);
void __cdecl FUN_00411E40(void**);
extern int DAT_00457f68;
extern int DAT_004583e8;
extern int DAT_00458488;
extern int FUN_004A2990;

void __cdecl GEX_Target(void** param1) {
    FUN_00420BC0(param1);
    int flags = (int)param1[0x1b] & (-2147483647 - 1);
    unsigned int uVar3 = flags / -0x10000000;
    uVar3 |= (int)param1[0x31] >> 0x15;
    param1[0x26] = 0;
    param1[0x15] = 0;
    param1[0x1c] = (void*)0x42;
    *(void* volatile*)&param1[0x14] = (void*)0x51;
    void* pGVar1 = *(void* volatile*)&param1[0x1e];
    param1[0x1e] = (void*)((unsigned int)pGVar1 & 0xffe00000);
    void* pGVar4 = (void*)(*(unsigned int*)((int)&DAT_00457f68 + uVar3 * 8) | ((unsigned int)pGVar1 & 0xffe00000));
    param1[0x1f] = (void*)((int)param1[0x1f] + 0x200000);
    param1[0x1e] = pGVar4;
    param1[0x1e] = (void*)((int)pGVar4 + (uVar3 == 4 ? -0x10000 : 0x10000));
    FUN_00421560_DrawCharacter(FUN_004A2990, param1);
    pGVar1 = param1[0x1f];
    param1[0x1e] = pGVar4;
    param1[0x1f] = (void*)((int)pGVar1 - 0x180000);
    param1[0x1e] = (void*)((int)pGVar4 + *(int*)((int)&DAT_004583e8 + ((int)param1[0x15] + *(int*)((int)&DAT_00458488 + uVar3 * 8) * 5) * 4));
    int iVar2 = *(int*)((int)&DAT_004583e8 + ((int)param1[0x15] + *(int*)((int)&DAT_00458488 + 4 + uVar3 * 8) * 5) * 4);
    param1[0x2a] = 0;
    param1[0x1f] = (void*)((int)param1[0x1f] + iVar2);
    param1[0x2b] = 0;
    FUN_00411E40(param1);
}
}
