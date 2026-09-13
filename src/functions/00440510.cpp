// Adapted from pc_decomp_backup/src/functions/FUN_00440510.cpp
// Historical source SHA256: 2da895c54dd52fd310d65213899d36658ae45cdb7772a4b2922a2618431933d6
extern "C" {
extern "C" { extern int DAT_0046BC64; }
extern "C" { extern int* DAT_004A2B18; }
extern "C" { extern int DAT_0046BC74; }
extern "C" { extern int DAT_0046BC60; }
extern "C" { extern int* DAT_004A2B14; }
extern "C" { extern int DAT_0046BC70; }
extern "C" { extern int DAT_004A2B20; }

extern "C" void __cdecl GEX_Target()
{
    if (DAT_0046BC64 != 0xFFFFFF)
    {
        *DAT_004A2B18 = DAT_0046BC64;
        DAT_004A2B18 = (int *)DAT_0046BC74;
    }
    if (DAT_0046BC60 != 0xFFFFFF)
    {
        *DAT_004A2B14 = DAT_0046BC60;
        DAT_004A2B14 = (int *)DAT_0046BC70;
    }
    *(short *)&DAT_004A2B20 = 0xFFFF;
}
}
