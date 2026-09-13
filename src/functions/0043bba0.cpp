// Adapted from pc_decomp_backup/src/functions/FUN_0043BBA0.cpp
// Historical source SHA256: f294a085b2442e5a8351e20e288da3d1bc56186c8a026ed75d019be2c78ba8a2
extern "C" {
extern "C" { extern int DAT_00464DE8[]; }
extern "C" { extern void* PTR_00464E08; }
extern "C" { extern void* PTR_00464E14; }
extern "C" void* FUN_004195D0(int, int, int, int);
extern "C" void FUN_00419BE0(void*, void*);
extern "C" void FUN_00419BC0(void*, void*);
extern "C" void FUN_00419B80(void*, int);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int i;
    void* obj;
    int pGVar3 = 0;
    void* pGVar4 = 0;

    if ((int)param_1[0x26] != 0x80) return;

    param_1[0x14] = (void*)0;
    param_1[0x15] = (void*)0;
    param_1[0x18] = (void*)0;
    param_1[0x19] = (void*)0;

    for (i = 0; i < 2; i++) {
        obj = FUN_004195D0(0x105, (int)param_1[0x1e], (int)param_1[0x1f], (int)param_1[3]);
        if (obj != 0) {
            ((void**)obj)[0x26] = (void*)pGVar4;
            DAT_00464DE8[i] = (int)obj;
            ((void**)obj)[0x27] = (void*)pGVar3;
            ((void**)obj)[0x28] = (void*)pGVar3;
            ((void**)obj)[0x14] = (void*)0;
            ((void**)obj)[0x15] = (void*)0;
            ((void**)obj)[0x17] = (void*)0;
            if (i < 1) {
                if (obj != 0 && PTR_00464E08 != 0) {
                    FUN_00419BE0(obj, PTR_00464E08);
                }
            } else {
                if (obj != 0 && PTR_00464E14 != 0) {
                    FUN_00419BC0(obj, PTR_00464E14);
                }
            }
        }
        pGVar3 += 3;
        pGVar4 = (void*)((int)pGVar4 + 1);
    }
    FUN_00419B80(param_1, 0);
}
}
