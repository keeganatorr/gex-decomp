// Adapted from pc_decomp_backup/src/functions/FUN_00417E70.cpp
// Historical source SHA256: b20f50354d9a955e368c6a0e835234abb68e0c4816285d503dcd1202461e4077
extern "C" {
extern "C" { extern int DAT_00456AFC; }
extern "C" { extern int DAT_00459498; }
extern "C" { extern int DAT_004594A0; }
extern "C" { extern int DAT_004594A4; }
extern "C" { extern int DAT_004594A8; }
extern "C" { extern int DAT_0045A6E0; }
extern "C" { extern int DAT_004A281C; }
extern "C" { extern int DAT_004A29A0; }
extern "C" { extern int DAT_004A29A4; }
extern "C" { extern int DAT_004A29A8; }
extern "C" { extern int DAT_004A29AC; }
extern "C" { extern int DAT_004A29B0; }
extern "C" { extern int DAT_004A29B4; }
extern "C" { extern int DAT_004A29B8; }
extern "C" void __cdecl FUN_0041A660();
extern "C" void __cdecl FUN_00422390(void**);

extern "C" void __cdecl ResetPlayerHP_00417e70()
{
    int three = 3;
    int zero = 0;
    int minus1 = -1;

    DAT_004A281C = three;
    DAT_00456AFC = three;
    DAT_004A29A0 = zero;
    DAT_004A29A4 = zero;
    DAT_004A29A8 = zero;
    DAT_004A29AC = zero;
    DAT_004A29B0 = zero;
    DAT_004A29B4 = zero;
    DAT_004A29B8 = zero;
    FUN_0041A660();
    DAT_004594A0 = minus1;
    DAT_004594A4 = minus1;
    DAT_004594A8 = minus1;
    DAT_00459498 = minus1;
    DAT_0045A6E0 = minus1;
    FUN_00422390((void**)zero);
}
}
