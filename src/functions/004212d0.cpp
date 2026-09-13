// Adapted from pc_decomp_backup/src/functions/FUN_004212D0.cpp
// Historical source SHA256: 5a58c964657f64d0b2b7ffb339e5f992f097647688a4206d7084765152e2e9f6
extern "C" {
extern "C" { extern int DAT_004A2890; }
extern "C" void __cdecl FUN_00425250(void*);
extern "C" void __cdecl FUN_00424D80(void*);

extern "C" int __cdecl GEX_Target(void* param_1)
{
    int vel = DAT_004A2890;
    if (vel < 0) {
        DAT_004A2890 = 0;
        FUN_00425250(param_1);
        return 1;
    }
    if (vel > 0) {
        int save = *(int*)((char*)param_1 + 0x8c);
        DAT_004A2890 = 0;
        FUN_00424D80(param_1);
        *(int*)((char*)param_1 + 0x8c) = save;
        *(int*)((char*)param_1 + 0xa0) = vel;
        return 1;
    }
    return 0;
}
}
