// Adapted from pc_decomp_backup/src/functions/FUN_00441130.cpp
// Historical source SHA256: 1884f04c3de447db59306969d85c54fdf3aa3c482ceb97a4febd4f90a9a72a47
extern "C" {
extern "C" { extern void* DAT_004A2ADC; }
extern "C" { extern void* DAT_004A2AE0; }
extern "C" { extern void* DAT_004A2AE4; }
extern "C" { extern int DAT_0047EDB0; }
extern "C" { extern int DAT_0046DC40; }

extern "C" void __cdecl GEX_Target()
{
    int* e = &DAT_0046DC40;
    DAT_004A2ADC = &DAT_0047EDB0;
    DAT_004A2AE0 = e;
    DAT_004A2AE4 = e;
}
}
