// Adapted from pc_decomp_backup/src/functions/FUN_00421A00.cpp
// Historical source SHA256: f18451e19067d6cbf4c06517b469ec20049143875668dbf9b3a8cb97306bfb97
extern "C" {
extern "C" { extern int DAT_004A01E0; }
extern "C" { extern int DAT_004A01EC; }
extern "C" { extern int DAT_004A2890; }
extern "C" { extern int DAT_00463AB8; }
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0282; }

extern "C" int __cdecl FUN_0041CB80(void**, int**);

extern "C" int __cdecl FUN_00421a00_AirToSideCrawl(void** param_1)
{
    int local_28[10];
    int v1, v2, v3, v4, v5, v6, v7, v8;
    int iVar1;

    v1 = 0; v2 = 0; v3 = 0; v4 = 0; v5 = 0; v6 = 0; v7 = 0; v8 = 0;
    if ((DAT_004A01E0 != DAT_004A01EC) || (DAT_004A2890 != 0)) return 0;
    if ((DAT_00463AB8 <= 0) || (DAT_004A0282 == 0)) {
        if ((DAT_00463AB8 >= 0) || (DAT_004A0280 == 0)) return 0;
    }
    iVar1 = FUN_0041CB80(param_1, (int**)local_28);
    if (iVar1 == 0) return 0;
    v1 = local_28[0]; v2 = local_28[1]; v3 = local_28[2]; v4 = local_28[3];
    v5 = local_28[4]; v6 = local_28[5]; v7 = local_28[6]; v8 = local_28[7];
    return v1 + v2 + v3 + v4 + v5 + v6 + v7 + v8;
}
}
