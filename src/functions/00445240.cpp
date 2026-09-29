// Adapted from pc_decomp_backup/src/functions/FUN_00445240.cpp
// Historical source SHA256: ff075c10985ca01f32ea2d8d6553d2c39fa28e259096903e66cd4e40afd96293
extern "C" {
extern "C" void __cdecl FUN_00406C30();
extern "C" { extern int DAT_004A2F84; }
extern "C" { extern int DAT_004A2F74; }
extern "C" { extern int DAT_004A2F7C; }
extern "C" { extern int DAT_004A2F80; }
extern "C" { extern int DAT_004A2F70; }

extern "C" int __cdecl FUN_00445240_DrawWindowAlways(int param_1)
{
    DAT_004A2F84 = 0;
    DAT_004A2F74 = -1;
    DAT_004A2F7C = -1;
    DAT_004A2F80 = -1;
    DAT_004A2F70 = -1;
    FUN_00406C30();
    return param_1;
}
}
