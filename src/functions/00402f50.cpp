// Adapted from pc_decomp_backup/src/functions/FUN_00402F50.cpp
// Historical source SHA256: ec87016131b3332e804b83708290e8da8a5881ef85533d668780ee167b438c33
extern "C" {
extern "C" { extern int DAT_00455C10; }
extern "C" void __cdecl FUN_00402EC0(int);
extern "C" void __cdecl MUS_StopMusic_00402f50()
{ if (DAT_00455C10 != 0) FUN_00402EC0(0); }
}
