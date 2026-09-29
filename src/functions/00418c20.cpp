// Adapted from pc_decomp_backup/src/functions/FUN_00418C20.cpp
// Historical source SHA256: 18ac0cdaebbbd97311ed1c8e0c7e6b002dca2b1b6cf7b6560e8cddeb41296958
extern "C" {
extern "C" { extern int DAT_0049FB90; }

extern "C" unsigned char * __cdecl SCRIPT_ModWorkField_00418c20(unsigned char *p, void **pp)
{
    unsigned char idx = *p;
    int val = (int)pp[idx + 0x1a];
    DAT_0049FB90 = DAT_0049FB90 % val;
    return p + 1;
}
}
