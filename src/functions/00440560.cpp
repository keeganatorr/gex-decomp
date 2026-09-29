// Adapted from pc_decomp_backup/src/functions/FUN_00440560.cpp
// Historical source SHA256: 08199f000675f566a9485775aa78b0bbb743ba1cea63a755d4241c45b6f4e770
extern "C" {
extern "C" { extern int DAT_0046BC58; }
extern "C" { extern int DAT_0046BC5C; }
extern "C" { extern int DAT_0046BC6C; }
extern "C" { extern int DAT_0046BC68; }
extern "C" { extern int* DAT_004A2B18; }
extern "C" { extern int* DAT_004A2B14; }
extern "C" { extern int DAT_004A2B20; }

extern "C" void __cdecl RM_LinkHiPriCels_00440560()
{
    if (DAT_0046BC58 != 0xFFFFFF)
    {
        *DAT_004A2B18 = DAT_0046BC58;
        DAT_004A2B18 = (int *)DAT_0046BC6C;
    }
    if (DAT_0046BC5C != 0xFFFFFF)
    {
        *DAT_004A2B14 = DAT_0046BC5C;
        DAT_004A2B14 = (int *)DAT_0046BC68;
    }
    *(short *)&DAT_004A2B20 = 0xFFFF;
}
}
