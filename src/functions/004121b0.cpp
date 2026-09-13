// Adapted from pc_decomp_backup/src/functions/FUN_004121B0.cpp
// Historical source SHA256: d0033be73f15f4875e9becb9dabdac32bd58b0fa12a4eeae0ed0c57694adad30
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" int __cdecl FUN_0041CB80(void**, int*);
extern "C" void __cdecl FUN_00411ff0(void**, int, int);

extern void** FUN_004A2864;

extern "C" void __cdecl GEX_Target(void** param1, int param2, int param3)
{
    int local_28[6];
    int local_10, local_c, local_4;
    
    FUN_00420BC0(param1);
    if (FUN_004A2864 != 0)
    {
        int iVar1 = FUN_0041CB80(FUN_004A2864, local_28);
        if (iVar1 != 0)
        {
            if (param2 != 0)
            {
                void* pGVar2;
                if ((((unsigned int)param1[0x1b] & 0x80000000) >> 0x1c | (int)param1[0x31] >> 0x15) == 0xe)
                    pGVar2 = (void*)(local_c + 0x180000);
                else
                    pGVar2 = (void*)(local_10 + -0x180000);
                param1[0x1e] = pGVar2;
            }
            if (param3 != 0)
                param1[0x1f] = (void*)(local_4 + 0x180000);
            FUN_00411ff0(param1, (param2 == 0) - 1 & 2, (param3 == 0) - 1 & 2);
        }
    }
}
}
