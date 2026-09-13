// Adapted from pc_decomp_backup/src/functions/FUN_0043F000.cpp
// Historical source SHA256: f59613142fb15ad03831ba26bdcee17cb9299465913cf498df9d4040e0880531
extern "C" {
extern "C" void __cdecl FUN_00444D10(int*, int, int, int);
extern "C" void __cdecl FUN_00445170(int);
extern "C" void __cdecl FUN_00445340(int);
extern "C" void __cdecl FUN_00405390(const char*, ...);

extern "C" { extern int DAT_0046A560[1]; }
extern "C" { extern int DAT_0046A574[1]; }
extern "C" { extern const char DAT_00460DCC[]; }

extern "C" void __cdecl GEX_Target()
{
    FUN_00444D10(DAT_0046A560, 0, 0, 0);
    FUN_00444D10(DAT_0046A574, 0, 0, 0);
    FUN_00445170(0);
    FUN_00445340(1);
    FUN_00405390(DAT_00460DCC);
}
}
