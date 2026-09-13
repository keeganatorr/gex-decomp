// Adapted from pc_decomp_backup/src/functions/FUN_00430E20.cpp
// Historical source SHA256: 1c0a8ed9304c83ecdd9a5b9eab4a7835c7889285f3400e977cb75f8afefa1e00
extern "C" {
extern "C" void __cdecl GEX_Target(void** param_1)
{
    if ((int)param_1[0x26] == 1) {
        param_1[0x14] = 0;
    } else {
        int* p15 = (int*)&param_1[0x15];
        (*p15)++;
        if (*p15 >= 3) param_1[0x15] = 0;
    }
    int* p2c = (int*)&param_1[0x2c];
    (*p2c)++;
    if (*p2c < 1) {
        param_1[0x2c] = (void*)3;
        int* p2b = (int*)&param_1[0x2b];
        (*p2b)++;
        if (*p2b == 10) param_1[0x2b] = 0;
        param_1[0x1f] = (void*)((int)param_1[0x1f] + *(int*)((int*)0x0045b0b0 + (int)param_1[0x2b]) * 0x80);
    }
}
}
