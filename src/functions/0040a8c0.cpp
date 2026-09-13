// Adapted from pc_decomp_backup/src/functions/FUN_0040A8C0.cpp
// Historical source SHA256: 57d833382c41024d43a5ae700adcc12f86ec06b6da9aea4ece3adffc82baea94
extern "C" {
extern "C" { extern int DAT_004a2a28_FileLoaded2; }
extern "C" { extern int DAT_004a298c_FileLoaded; }
extern "C" { extern int FUN_004A2964; }
extern "C" { extern void* PTR_gIDLDirectory_00455998; }
extern "C" { extern void* FUN_00455B7C; }
extern "C" { extern void* FUN_00455B78; }
extern "C" int __cdecl FUN_00409350(void*, void*, int);

extern "C" void __cdecl GEX_Target()
{
    if (DAT_004a2a28_FileLoaded2 == 0) {
        int idx = ((unsigned char*)0x004577b2)[FUN_004A2964 * 8];
        FUN_00409350(PTR_gIDLDirectory_00455998, FUN_00455B7C, idx);
        DAT_004a2a28_FileLoaded2 = 1;
    }
    if (DAT_004a298c_FileLoaded == 0) {
        int idx2 = ((unsigned char*)0x004577b3)[FUN_004A2964 * 8];
        if (idx2 != 0) {
            FUN_00409350(PTR_gIDLDirectory_00455998, FUN_00455B78, idx2);
            DAT_004a298c_FileLoaded = 1;
        }
    }
}
}
