// Adapted from pc_decomp_backup/src/functions/FUN_0043B630.cpp
// Historical source SHA256: 3378e32aef68fa82e5cb9b7e9c0a53df12165edd155daf0d9b7d54408315785b
extern "C" {
extern "C" void __cdecl FUN_0043B550(void**);
extern "C" { extern int DAT_0043B870; }
extern "C" { extern int DAT_00460028; }
extern "C" { extern int DAT_0046002C; }
extern "C" { extern int DAT_00460030; }
extern "C" { extern int DAT_00464DB8; }
extern "C" { extern int DAT_00464DC0; }
extern "C" { extern int DAT_00464DCC; }
extern "C" { extern int DAT_00464DD4; }
extern "C" { extern int DAT_00464DD8; }
extern "C" { extern int DAT_00464DDC; }
extern "C" { extern int DAT_00464DE0; }
extern "C" { extern int DAT_00464DE8; }
extern "C" { extern int DAT_00464DF8; }
extern "C" { extern int DAT_00464E00; }
extern "C" { extern int DAT_00464E04; }
extern "C" { extern void** DAT_00464E08; }
extern "C" { extern int DAT_00464E10; }
extern "C" { extern void** DAT_00464E14; }
extern "C" { extern int DAT_00464E18; }
extern "C" { extern int DAT_00464E1C; }
extern "C" { extern int DAT_004A2A38; }

extern "C" void __cdecl FUN_00419BC0(void**, void**);
extern "C" void __cdecl FUN_00419BE0(void**, void**);
extern "C" void __cdecl FUN_004339C0(void**);
extern "C" void __cdecl FUN_0043B570(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    if (DAT_00464E10 != 0) {
        *(int*)(DAT_00464E10 + 0x78) = DAT_004A2A38 + 0xa00000;
    }
    DAT_00464DB8--;
    if (DAT_00464DB8 == 0) {
        param_1[0x18] = 0;
        param_1[0x19] = 0;
        DAT_00464DB8 = 1;
        return;
    }
    if ((int)param_1[0x26] == 0x40) {
        FUN_004339C0(DAT_00464E14);
        if ((int)DAT_00464E14[0x18] != (int)&FUN_0043B550) {
            return;
        }
        if ((int)DAT_00464E14[0x27] == 1) {
            DAT_00464E18 = 1;
            DAT_00464E14[0x29] = (void*)0xc9;
        }
    } else {
        FUN_004339C0(param_1);
    }
}
}
