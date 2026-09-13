// Adapted from pc_decomp_backup/src/functions/FUN_004395B0.cpp
// Historical source SHA256: c33e051410eb4ffc959d452300075df0cf74e7f9f6cd806066e237075b7c3ea6
extern "C" {
extern "C" { extern int DAT_00464528; }
extern "C" { extern int DAT_0046452C; }
extern "C" { extern int DAT_00464530; }
extern "C" { extern int DAT_00464534; }
extern "C" { extern int DAT_004645B0; }
extern "C" { extern int DAT_00464610; }
extern "C" { extern int DAT_00464660; }
extern "C" { extern int DAT_00464664; }
extern "C" { extern int DAT_00464668; }

extern "C" void __cdecl GEX_Target(int param_1, int param_2)
{
    int* piVar3;
    int iVar4;
    int* puVar2;

    puVar2 = (int*)&DAT_004645B0;
    piVar3 = (int*)&DAT_00464610;
    iVar4 = 0;
    do {
        int iVar1 = *piVar3;
        puVar2[0] = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2 = puVar2 + 3;
        *(int*)(iVar1 + 0xa0) = 0;
        *(int*)(iVar1 + 0x54) = 0;
        iVar1 = *piVar3;
        *(int*)((int)&DAT_00464530 + iVar4) = param_1;
        *(int*)((int)&DAT_00464660 + iVar4) = 0;
        *(int*)((int)&DAT_00464534 + iVar4) = param_2;
        *(int*)((int)&DAT_00464664 + iVar4) = 0;
        *(int*)((int)&DAT_00464528 + iVar4) = param_1;
        *(int*)((int)&DAT_00464668 + iVar4) = 0;
        *(int*)((int)&DAT_0046452C + iVar4) = param_2;
        *(int*)(iVar1 + 0xd4) = param_1;
        *(int*)(*piVar3 + 0xd8) = param_2;
        *(int*)(*piVar3 + 0x78) = param_1;
        *(int*)(*piVar3 + 0x7c) = param_2;
        piVar3 = piVar3 + 1;
        iVar4 = iVar4 + 0x10;
    } while ((int)puVar2 < (int)&DAT_00464610);
}
}
