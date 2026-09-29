// Adapted from pc_decomp_backup/src/functions/FUN_00419B80.cpp
// Historical source SHA256: 8d7b180e80e19554593315093104b07139f42f823952008260f1043ce9f9f5b2
extern "C" {
extern "C" void __cdecl FUN_0042CBF0(void**);
extern "C" void __cdecl FUN_0042CC00(void**, void**);
extern "C" { extern void* DAT_004A28A0[]; }

extern "C" void __cdecl GOB_SetObjectDisplayPriority_00419b80(void** param_1, unsigned int gObNumber)
{
    FUN_0042CBF0(param_1);
    FUN_0042CC00(&DAT_004A28A0[gObNumber * 3], param_1);
    param_1[0x1b] = (void*)(((unsigned int)param_1[0x1b] & 0xfffffff0) | gObNumber);
}
}
