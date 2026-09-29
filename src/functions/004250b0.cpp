// Adapted from pc_decomp_backup/src/functions/FUN_004250B0.cpp
// Historical source SHA256: d4dff4908dfd3039e00b3b811a6db035e9ae326a2c23cfdee546c548971aa58a
extern "C" {
extern "C" void __cdecl FUN_00425030(void**);
extern "C" void __cdecl InitPlayerFall_004250b0(void** param_1)
{
    param_1[0x14] = (void*)0x27;
    param_1[0x15] = (void*)4;
    FUN_00425030(param_1);
}
}
