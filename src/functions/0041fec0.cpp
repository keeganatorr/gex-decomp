// Adapted from pc_decomp_backup/src/functions/FUN_0041FEC0.cpp
// Historical source SHA256: de4c615ce500587ef8b26f8fd37279f57cb7d5f7c2f52e325e83596d9afb2e1b
extern "C" {
extern "C" { extern int DAT_004A2ACC; }
extern "C" void __cdecl FUN_0041FEF0(int*, int, int);
extern "C" { extern int DAT_004A293C; }
extern "C" { extern int DAT_004A2978; }
extern "C" void __cdecl GEX_Target(int p)
{
    if (DAT_004A2ACC) {
        int *holder = *(int**)(p + 0xa0);
        if (holder != 0 && *holder != 0) {
            FUN_0041FEF0((int*)*holder, DAT_004A293C, DAT_004A2978);
        }
    }
}
}
