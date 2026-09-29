// Adapted from pc_decomp_backup/src/functions/FUN_0041FCB0.cpp
// Historical source SHA256: 928ec631c5ca42688538ef08d95f95116346cf7bcb66977e3010b134b1971a46
extern "C" {
extern "C" { extern int PTR_004a2a10; }
extern "C" { extern int DAT_00463a2c; }
extern "C" { extern int DAT_004a298c_FileLoaded; }
extern "C" void __cdecl FUN_0040B8C0(void*, int, int*, int*);
extern "C" { extern void* DAT_00455B78; }
extern "C" { extern int FUN_00463A34; }
extern "C" { extern int DAT_00463a38; }
extern "C" { extern int DAT_00463a30; }

extern "C" void __cdecl IDL_Open_0041fcb0(int param_1)
{
    if (PTR_004a2a10 == 0 && DAT_00463a2c == 0 && DAT_004a298c_FileLoaded != 0) {
        FUN_0040B8C0(DAT_00455B78, param_1, &DAT_00463a38, &DAT_00463a30);
        FUN_00463A34 = param_1;
        DAT_00463a2c = 1;
    }
}
}
