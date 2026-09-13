// Adapted from pc_decomp_backup/src/functions/FUN_00417CA0.cpp
// Historical source SHA256: 4fa6a0e58256e885ad87bd4bbd641f5064c8f88c1926922ff66725320ad0de7e
extern "C" {
extern "C" void __cdecl FUN_00422390_Reset_Powerups(void**);
extern "C" void __cdecl FUN_0041A660();
extern "C" int __cdecl FUN_004206b0(int);

extern "C" { extern int DAT_004A27FC; }
extern "C" { extern int DAT_004A281C; }
extern "C" { extern int DAT_004A2878; }
extern "C" { extern int DAT_004A2840; }
extern "C" { extern int DAT_00455C4C; }
extern "C" { extern int DAT_004A2850; }
extern "C" { extern int DAT_00455B8C; }
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0281; }
extern "C" { extern int DAT_004A2AC0; }
extern "C" { extern int DAT_004A0218; }
extern "C" { extern int DAT_004594A0; }
extern "C" { extern int DAT_004594A4; }
extern "C" { extern int DAT_004594A8; }
extern "C" { extern int DAT_0045A6E0; }
extern "C" { extern int DAT_00459498; }
extern "C" { extern int DAT_00455C1C; }
extern "C" { extern int DAT_00455C24; }
extern "C" { extern int DAT_00456B00; }
extern "C" { extern int DAT_00462E38; }

extern "C" void __cdecl GEX_Target()
{
    void** gPlayerObject = (void**)DAT_004A27FC;
    if ((gPlayerObject != 0) && (DAT_004A281C != 0))
    {
        DAT_004A2878 = 0x14;
        if (DAT_004A2840 == 0)
        {
            DAT_00455C4C++;
            DAT_004A2840 = 1;
        }
        gPlayerObject[0x2e] = (void*)0x5a;
        DAT_004A2850 = 0;
        if (DAT_00455B8C != 0)
        {
            DAT_004A0280 = 0;
            DAT_004A0281 = 0;
        }
        if (DAT_004A2AC0 == 0)
        {
            int iVar1 = FUN_004206b0(0x55);
            if (iVar1 == 0)
                DAT_004A0218 = 0x76;
            DAT_004A281C = 0;
            FUN_00422390_Reset_Powerups(gPlayerObject);
            DAT_004594A0 = -1;
            DAT_004594A4 = -1;
            DAT_004594A8 = -1;
            DAT_0045A6E0 = -1;
            DAT_00459498 = -1;
            FUN_0041A660();
            if ((DAT_00455C1C == 0) && (DAT_00455C24 == 0))
            {
                DAT_00456B00--;
                return;
            }
        }
        else
        {
            DAT_00462E38 = 1;
        }
    }
}
}
