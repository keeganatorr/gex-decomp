// Adapted from pc_decomp_backup/src/functions/FUN_00418CD0.cpp
// Historical source SHA256: cb5ec38ae9358990497762bd19f114a12ea57ea4f2bd5edc49d231f5418a5549
extern "C" {
extern "C" void __cdecl FUN_00405350(const char *msg);
extern "C" { extern const char DAT_00458E84[]; }

extern "C" unsigned int __cdecl EVENT_Unimplemented_00418cd0(unsigned int param_1)
{
    FUN_00405350(DAT_00458E84);
    return param_1;
}
}
