extern "C" int *GOB_AddObject_004195d0(int, int, int, int);
extern "C" void FUN_0042f7e0();

struct Blob8 { int a[8]; };
extern "C" struct Blob8 DAT_0049ffa0;

extern "C" void FUN_0042f800(int param_1, int param_2, int param_3)
{
    int *psVar;

    psVar = GOB_AddObject_004195d0(0xe5, param_2, param_3, *(int *)(param_1 + 0xc));
    if (psVar != 0) {
        psVar[0x14] = 0xd;
        psVar[0x15] = 0;
        psVar[0x17] = (int)&FUN_0042f7e0;
        *(struct Blob8 *)(psVar + 4) = DAT_0049ffa0;
        psVar[0x34] = 0x30000000;
    }
}
