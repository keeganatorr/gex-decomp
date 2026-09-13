// Adapted from pc_decomp_backup/src/functions/FUN_004051D0.cpp
// Historical source SHA256: 6806ff2503be552f301c2b41bf95b974da6d00bd3632b8517187ae7bfa1146ed
extern "C" {
extern "C" { extern int DAT_0045103C; }
extern "C" { extern int DAT_00451794; }
extern "C" { extern int DAT_00487F74; }
extern "C" { extern int DAT_00487F88; }
extern "C" int __cdecl FUN_00404890();
extern "C" int __cdecl FUN_004013E0(int);
extern "C" int __cdecl FUN_0040B320();
extern "C" void __cdecl FUN_00402E30();

extern "C" void __cdecl GEX_Target()
{
    if (DAT_00487F88 != 0 && DAT_00487F74 == 0) {
        if (DAT_00451794 != 0) {
            FUN_00404890();
            if (DAT_0045103C == 2) {
                FUN_004013E0(1);
            }
            DAT_00487F88 = 0;
            return;
        }
        if (FUN_0040B320() != 0) {
            FUN_00402E30();
            if (DAT_0045103C == 2) {
                FUN_004013E0(1);
            }
            DAT_00487F88 = 0;
        }
    }
}
}
