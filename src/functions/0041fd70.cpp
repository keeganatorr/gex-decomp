// Adapted from pc_decomp_backup/src/functions/FUN_0041FD70.cpp
// Historical source SHA256: 6c3c9dda2da7278f256e3e3327e5a258fc203ec57b405e6820f3375ded05bbb8
extern "C" {
extern "C" void __cdecl FUN_0040eea0(void*);
extern "C" void __cdecl FUN_0040B860(int);
extern "C" { extern void* PTR_004a2a10; }
extern "C" { extern int DAT_00463a38; }
extern "C" { extern int DAT_00463a30; }
extern "C" { extern int FUN_00463A34; }

extern "C" void __cdecl IDL_Free_0041fd70()
{
    if (PTR_004a2a10 != 0) {
        FUN_0040eea0(PTR_004a2a10);
        FUN_0040B860(DAT_00463a38);
        PTR_004a2a10 = 0;
        DAT_00463a30 = 0;
        FUN_00463A34 = 0;
    }
}
}
