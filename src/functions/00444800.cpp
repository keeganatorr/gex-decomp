// Adapted from pc_decomp_backup/src/functions/FUN_00444800.cpp
// Historical source SHA256: a9b44279896c00189fcd84e3d4d576cd2b24d6c220ad2cc44484f1e84d0fb882
extern "C" {
extern "C" { extern int DAT_004A2ADC; }
extern "C" { extern int DAT_004A2AE0; }
extern "C" { extern int DAT_004A2AE4; }
extern "C" { extern int DAT_004A2B14; }
extern "C" { extern int DAT_004A2B18; }
extern "C" { extern int DAT_004A2B20; }
extern "C" void __cdecl FUN_00445350(int);

extern "C" void __cdecl GEX_Target()
{
    int* pMVar1 = (int*)DAT_004A2AE4;
    int* pMVar2;
    int* piVar3;
    
    pMVar1 = (int*)(DAT_004A2AE4 + 1);
    pMVar2 = (int*)DAT_004A2AE4;
    DAT_004A2AE4 = (int)pMVar1;
    if (DAT_004A2ADC < (int)pMVar1) {
        pMVar2 = (int*)DAT_004A2AE0;
        DAT_004A2AE4 = DAT_004A2AE0 + 1;
    }
    *(int*)DAT_004A2B14 = (int)pMVar2;
    DAT_004A2B14 = (int)pMVar2;
    *(int*)(DAT_004A2B14 + 4) = 0;
    *(int*)(DAT_004A2B14 + 8) = 0;
    FUN_00445350(DAT_004A2B18);
    FUN_00445350(DAT_004A2B20);
}
}
