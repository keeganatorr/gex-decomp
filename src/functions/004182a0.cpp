// Adapted from pc_decomp_backup/src/functions/FUN_004182A0.cpp
// Historical source SHA256: 9a864c8d3f5976f31860a41e9aeaad4bc363b0bf342a891d8184db382a100dc0
extern "C" {
extern "C" { extern int DAT_004A27FC; }
extern "C" { extern int DAT_0049FB90; }

extern "C" int __cdecl SCRIPT_TrackGXPositionY_004182a0(int param_1, void* param_2)
{
    void* pGVar2;
    void* pGVar1;
    
    pGVar2 = *(void**)((char*)param_2 + 0x15c);
    if (pGVar2 == (void*)0) {
        pGVar2 = *(void**)((char*)param_2 + 0x7c);
    }
    else {
        pGVar1 = *(void**)((char*)pGVar2 + 0x15c);
        while (pGVar1 != (void*)0) {
            pGVar2 = *(void**)((char*)pGVar2 + 0x15c);
            pGVar1 = *(void**)((char*)pGVar2 + 0x15c);
        }
        pGVar2 = (void*)*(int*)((char*)pGVar2 + 0x7c);
    }
    DAT_0049FB90 = *(int*)((int)DAT_004A27FC + 0x7c) - (int)pGVar2;
    return param_1;
}
}
