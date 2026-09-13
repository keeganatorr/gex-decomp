// Adapted from pc_decomp_backup/src/functions/FUN_0043B570.cpp
// Historical source SHA256: b44e67fdde7802a3daa2777f840fb11db06327e31224a0602a46872508ea808b
extern "C" {
extern "C" void** __cdecl FUN_004195D0(int, int, int, int);
extern "C" void** __cdecl FUN_004196E0(int, int, int, unsigned int);
extern "C" void __cdecl FUN_00419BE0(void**, void**);
extern "C" void __cdecl FUN_0041A630(int);
extern "C" void __cdecl FUN_0043B510();

extern "C" { extern void** DAT_00464E14; }
extern "C" { extern void** DAT_004A27FC; }
extern "C" { extern void** DAT_00464E10; }

extern "C" void __cdecl GEX_Target(void** param1)
{
    void** ppGVar1 = FUN_004195D0(0x102, (int)DAT_00464E14[0x1e], (int)DAT_00464E14[0x1f], (int)DAT_00464E14[3]);
    if (ppGVar1 != 0)
    {
        ppGVar1[0x14] = (void*)8;
        ppGVar1[0x15] = 0;
        ppGVar1[0x17] = (void*)&FUN_0043B510;
        ppGVar1[0x19] = 0;
        ppGVar1[0x2b] = DAT_00464E14[0x2b];
        param1[0x2c] = (void*)3;
        FUN_00419BE0(param1, DAT_004A27FC);
    }
    ppGVar1 = FUN_004196E0(0x72, (int)DAT_00464E14[0x1e], (int)DAT_00464E14[0x1f], (unsigned int)param1[0x2d]);
    if (ppGVar1 != 0)
    {
        DAT_00464E10 = ppGVar1;
        ppGVar1[0x2b] = (void*)3;
        FUN_00419BE0(ppGVar1, DAT_00464E14);
    }
    FUN_0041A630(3);
}
}
