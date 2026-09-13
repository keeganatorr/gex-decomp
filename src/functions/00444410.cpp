// Adapted from pc_decomp_backup/src/functions/FUN_00444410.cpp
// Historical source SHA256: 1fd31d9ead0a0f134417aa4d2b56fd9e9fa5dfeea305ba639bf241247e2c7538
extern "C" {
extern "C" { extern short int DAT_004610A0[]; }
extern "C" { extern short int DAT_004610A8[]; }
extern "C" { extern short int DAT_004610B0[]; }
extern "C" { extern short int DAT_004610B8[]; }
extern "C" { extern int FUN_004A2AC8; }
extern "C" { extern int DAT_0047EDB0; }

extern "C" void __cdecl GEX_Target(int param_1)
{
    short int v4 = DAT_004610B8[0];
    short int v3 = DAT_004610B0[0];
    short int v2 = DAT_004610A8[0];
    short int v1 = DAT_004610A0[0];

    if (FUN_004A2AC8 != DAT_0047EDB0) {
        DAT_0047EDB0 = FUN_004A2AC8;
        DAT_004610A0[0] = DAT_004610A0[1];
        DAT_004610A0[1] = DAT_004610A0[2];
        DAT_004610A0[2] = DAT_004610A0[3];
        DAT_004610A0[3] = v1;
        DAT_004610A8[0] = DAT_004610A8[1];
        DAT_004610A8[1] = DAT_004610A8[2];
        DAT_004610A8[2] = DAT_004610A8[3];
        DAT_004610A8[3] = v2;
        DAT_004610B0[0] = DAT_004610B0[1];
        DAT_004610B0[1] = DAT_004610B0[2];
        DAT_004610B0[2] = DAT_004610B0[3];
        DAT_004610B0[3] = v3;
        DAT_004610B8[0] = DAT_004610B8[1];
        DAT_004610B8[1] = DAT_004610B8[2];
        DAT_004610B8[2] = DAT_004610B8[3];
        DAT_004610B8[3] = v4;
    }
    {
        int i;
        int* src = (int*)&DAT_004610A0;
        int* dst = (int*)(param_1 + 2);
        for (i = 0; i < 7; i++) {
            dst[i] = src[i];
        }
    }
    *(short int*)(param_1 - 2) = -1;
}
}
