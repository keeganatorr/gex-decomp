extern "C" void __cdecl FUN_00420BC0(int *param1);
extern "C" void __cdecl FUN_00411E40(int *param1);
extern "C" int DAT_00457f68;
extern "C" int DAT_00457F6C;
extern "C" int DAT_004583e8;
extern "C" int DAT_00458488;
extern "C" int DAT_0045848c;

extern "C" void __cdecl FUN_00411ff0_SideInside90Trans(int *param1, int param2, int param3)
{
    FUN_00420BC0(param1);

    param1[0x1c] = 0x42;
    param1[0x14] = 0x51;

    unsigned int uVar3 = (((unsigned int)param1[0x1b] & 0x80000000) ? 8 : 0)
                       | ((unsigned int)(param1[0x31] >> 0x15));

    param1[0x26] = 0;
    param1[0x15] = 0;

    if (param2 == 1) {
        int v = param1[0x1e];
        param1[0x1e] = v & 0xffe00000;
        param1[0x1e] = *(int *)((int)&DAT_00457f68 + uVar3 * 8) | (v & 0xffe00000);
    }

    if (param3 == 1) {
        int v = param1[0x1f];
        param1[0x1f] = v & 0xffe00000;
        param1[0x1f] = *(int *)((int)&DAT_00457F6C + uVar3 * 8) | (v & 0xffe00000);
    }

    param1[0x1e] = param1[0x1e] + *(int *)((int)&DAT_004583e8 + *(int *)((int)&DAT_00458488 + uVar3 * 8) * 0x14);
    param1[0x1f] = param1[0x1f] + *(int *)((int)&DAT_004583e8 + *(int *)((int)&DAT_0045848c + uVar3 * 8) * 0x14);

    param1[0x2a] = param2;
    param1[0x2b] = param3;

    FUN_00411E40(param1);
}
