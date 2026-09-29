// Adapted from pc_decomp_backup/src/functions/FUN_00402F30.cpp
// Historical source SHA256: 670e3cdb4362efeb790e0ad4da830f37cab0237ab164ec74fbb94c25f6c84f5e
extern "C" {
extern "C" { extern int DAT_00455C10; }
extern "C" void __cdecl FUN_00402EC0(int);
extern "C" void __cdecl MUS_PlayMusic_00402f30()
{ if (DAT_00455C10 != 0) FUN_00402EC0(1); }
}
