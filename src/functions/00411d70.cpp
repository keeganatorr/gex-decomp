extern "C" {
extern int DAT_00457F68;
extern int DAT_00457F6C;
extern int DAT_00458208;
extern int DAT_004582A8;
extern int DAT_004582AC;
extern void __cdecl FUN_00420BC0(void*);
extern void __cdecl FUN_00411C60(void*);

void __cdecl GEX_Target(int* param_1)
{
    unsigned int uVar3;
    int pGVar1;
    int pGVar2;

    uVar3 = (((unsigned int)param_1[0x1b] & 0x80000000) ? 8 : 0)
          | (int)param_1[0x31] >> 0x15;
    FUN_00420BC0(param_1);
    param_1[0x26] = 0;
    param_1[0x15] = 0;
    param_1[0x1c] = 0x40;
    param_1[0x14] = 0x50;

    pGVar1 = param_1[0x1e];
    param_1[0x1e] = pGVar1 & 0xffe00000;
    pGVar2 = *(int*)((char*)&DAT_00457F68 + uVar3 * 8) | (pGVar1 & 0xffe00000);
    pGVar1 = param_1[0x1f];
    param_1[0x1e] = pGVar2;
    param_1[0x1f] = pGVar1 & 0xffe00000;
    pGVar1 = *(int*)((char*)&DAT_00457F6C + uVar3 * 8) | (pGVar1 & 0xffe00000);
    param_1[0x1f] = pGVar1;

    param_1[0x1e] = pGVar2 + *(int*)((char*)&DAT_00458208 + *(int*)((char*)&DAT_004582A8 + uVar3 * 8) * 0x14);
    param_1[0x1f] = pGVar1 + *(int*)((char*)&DAT_00458208 + *(int*)((char*)&DAT_004582AC + uVar3 * 8) * 0x14);

    FUN_00411C60(param_1);
}
}