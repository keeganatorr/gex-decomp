// Adapted from pc_decomp_backup/src/functions/FUN_0041FD00.cpp
// Historical source SHA256: 96962375f8a46caeaa77b2afcacf2d2718db29b56c4ba23870ad6d13e80fe023
extern "C" {
extern "C" { extern int DAT_004A2A10; }
extern "C" { extern int DAT_00463A2C; }
extern "C" { extern int* DAT_00463A30; }
extern "C" { extern int DAT_00455C54; }
extern "C" { extern int DAT_00463A34; }
extern "C" { extern int DAT_00463A38; }
extern "C" { extern const char DAT_0045A198[]; }
extern "C" void __cdecl FUN_00405390(const char*, ...);
extern "C" int __cdecl FUN_0040EB70(int, int);

extern "C" int __cdecl GEX_Target()
{
    if (DAT_004A2A10 == 0 && DAT_00463A2C != 0) {
        if (DAT_00463A30 == 0) {
            
            DAT_00463A2C = 0;
            return 1;
        }
        if (DAT_00455C54 > 2) {
            FUN_00405390(DAT_0045A198, DAT_00463A34);
        }
        DAT_00463A2C = 0;
        DAT_004A2A10 = FUN_0040EB70(DAT_00463A38, *DAT_00463A30);
    }
    return 1;
}
}
