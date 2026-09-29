// Adapted from pc_decomp_backup/src/functions/FUN_0040F440.cpp
// Historical source SHA256: 1cef04cddd354fd98d969db51b5ce3b6df1e8ce301158be177aec970bb70fb22
extern "C" {
typedef void (*voidfunc)();

extern "C" int __cdecl FUN_00402FA0();

extern "C" { extern int DAT_00462C98; }
extern "C" { extern int DAT_00462C88; }
extern "C" { extern voidfunc DAT_00462CA0; }
extern "C" { extern unsigned int DAT_00462C94; }
extern "C" { extern voidfunc DAT_00462C90; }
extern "C" { extern int DAT_00462C8C; }

extern "C" void __cdecl CheckIdle_0040f440(int param_1)
{
    int iVar1;

    if (param_1 != 0) {
        DAT_00462C98 = FUN_00402FA0();
        if (DAT_00462C88 != 0 && DAT_00462CA0 != (voidfunc)0) {
            DAT_00462CA0();
        }
        DAT_00462C88 = 0;
        return;
    }
    if (DAT_00462C88 != 0) {
        iVar1 = FUN_00402FA0();
        if (DAT_00462C94 < (unsigned int)(iVar1 - DAT_00462C98)) {
            if (DAT_00462C90 != (voidfunc)0 && (DAT_00462C8C == 0 || DAT_00462C88 == 0)) {
                DAT_00462C90();
            }
            DAT_00462C88 = 1;
        }
    }
}
}
