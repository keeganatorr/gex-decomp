// Adapted from pc_decomp_backup/src/functions/FUN_0043AE20.cpp
// Historical source SHA256: 072dd165bf299331c72b1a6fc6da0f3f5e833da9e57c82f605f786b24af35a03
extern "C" {
extern "C" { extern int DAT_004647B0; }
extern "C" { extern int DAT_0046478C; }

extern "C" void __cdecl GEX_Target(void* param_1, int param_2)
{
    if (param_2 == 0) {
        if (DAT_004647B0 == 0) {
            *(int*)((char*)param_1 + 0xd0) = 0x30000000;
            DAT_004647B0 = (int)param_1;
        }
        *(int*)((char*)param_1 + 0x9c) = 0;
        return;
    }
    if (DAT_004647B0 == (int)param_1) {
        DAT_004647B0 = 0;
        DAT_0046478C = 0;
    }
}
}
