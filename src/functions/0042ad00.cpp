// Adapted from pc_decomp_backup/src/functions/FUN_0042AD00.cpp
// Historical source SHA256: dbfb1b95295d7d05cd49d0cdfb91be2f8f12d402c475982141b223e98083ff1b
extern "C" {
extern "C" void __cdecl GEX_Target(void** param_1)
{
    param_1[0x15] = (void*)0xffffffff;
    param_1[0x14] = (void*)1;
    if ((int)param_1[0x26] != 1) {
        param_1[0x14] = 0;
    }
    param_1[0x2b] = (void*)(((unsigned int)param_1[0x2b] & 0xffffff20) | 0x20);
}
}
