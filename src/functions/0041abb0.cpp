// Adapted from pc_decomp_backup/src/functions/FUN_0041ABB0.cpp
// Historical source SHA256: 1d198714b97f6670dad4433a968db879d984714f004f0713723134a4afc38ecc
extern "C" {
extern "C" void __cdecl FUN_00405350(const char*, int, int, int);
extern "C" void __cdecl FUN_00419520(void**);
extern "C" int __cdecl FUN_0041A590(int);
extern "C" { extern int DAT_004a2964; }
extern "C" { extern unsigned int DAT_004a2420[]; }
extern "C" { extern unsigned int DAT_00459080[]; }
extern "C" { extern const char DAT_004590b0[]; }
extern "C" { extern const char DAT_004590e4[]; }
extern "C" void __cdecl GEX_Target(void* LevelStruct) {
    int* ls = (int*)LevelStruct;
    if (ls[7] < 0) {
        FUN_00405350(DAT_004590e4, ls[2] >> 0x10, ls[3] >> 0x10, ls[7]);
        return;
    }
    int RemoteID = ls[8];
    if (RemoteID < 0 || RemoteID > 2) {
        FUN_00405350(DAT_004590b0, ls[2] >> 0x10, ls[3] >> 0x10, RemoteID);
    } else {
        DAT_004a2420[DAT_004a2964] |= DAT_00459080[RemoteID];
        RemoteID = FUN_0041A590(ls[7]);
        if (RemoteID != 0) {
            FUN_00419520((void**)LevelStruct);
            if (RemoteID != 2) {
                DAT_004a2420[DAT_004a2964] |= DAT_00459080[ls[8]] << 4;
            }
        }
    }
}
}
