// Adapted from pc_decomp_backup/src/functions/FUN_00410250.cpp
// Historical source SHA256: e2d01063dfb44af0d030df1a4e467b20d3f577cc458a643ea01e2787cc428bcd
extern "C" {
extern "C" { extern int DAT_004A2A9C; }
extern "C" { extern int DAT_004A2A2C; }
extern "C" { extern int DAT_004A2A38; }
extern "C" { extern int DAT_004A2A1C; }
extern "C" { extern int DAT_004A2A90; }
extern "C" { extern int DAT_004A2940; }

extern "C" void __cdecl GEX_Target()
{
    int tmp1 = DAT_004A2A9C;
    int tmp2 = DAT_004A2A2C;
    DAT_004A2A38 = tmp1;
    DAT_004A2A1C = tmp2;
    DAT_004A2A90 = 0;
    DAT_004A2940 = 0;
}
}
