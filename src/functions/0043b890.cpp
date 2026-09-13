// Adapted from pc_decomp_backup/src/functions/FUN_0043B890.cpp
// Historical source SHA256: 1383a2539a2b2209b16c02980efe5dba709a9a3c24b8cfaecfd38eb808047793
extern "C" {
extern "C" void __cdecl FUN_00441150(void*);

extern "C" { extern int CAMERA_XPos_004a2a38; }

extern "C" void __cdecl GEX_Target(int* param_1)
{
    int val;

    param_1[0x1e] = param_1[0x2b] + CAMERA_XPos_004a2a38;
    param_1[0x2e] = param_1[0x2e] - 1;
    if (param_1[0x2e] < 0) {
        FUN_00441150((void*)param_1);
        return;
    }
    if (param_1[0x2e] & 1) {
        FUN_00441150((void*)param_1);
        return;
    }
    val = param_1[0x2f];
    param_1[0x2f] = 0x1d001d00;
    FUN_00441150((void*)param_1);
    param_1[0x2f] = val;
}
}
