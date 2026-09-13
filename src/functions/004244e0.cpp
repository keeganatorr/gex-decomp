// Adapted from pc_decomp_backup/src/functions/FUN_004244E0.cpp
// Historical source SHA256: 8165408ecf0bd16ff810be143dabdeb1ce19aa724a6890380b9fbe464dbfee02
extern "C" {
extern "C" { extern unsigned char DAT_004A0280; }
extern "C" { extern unsigned char DAT_004A0288; }
extern "C" { extern int DAT_004A23C8; }

extern "C" void __cdecl GEX_Target(void** param_1, int param_2)
{
    if (DAT_004A0280 != 0) {
        if (0 < (int)param_1[0x20] && DAT_004A23C8 == 0) {
            param_1[0x20] = (void*)0;
            param_1[0x22] = (void*)0;
            return;
        }
        param_1[0x22] = (void*)(-param_2);
        param_1[0x1b] = (void*)((int)param_1[0x1b] & 0x7fffffff);
        return;
    }
    if (DAT_004A0288 != 0) {
        if ((int)param_1[0x20] < 0 && DAT_004A23C8 == 0) {
            param_1[0x20] = (void*)0;
            param_1[0x22] = (void*)0;
            return;
        }
        param_1[0x22] = (void*)param_2;
        param_1[0x1b] = (void*)((int)param_1[0x1b] | 0x80000000);
        return;
    }
    if (0x10000 < (int)param_1[0x20]) {
        param_1[0x22] = (void*)0xffffc000;
        return;
    }
    if ((int)param_1[0x20] < -0x10000) {
        param_1[0x22] = (void*)0x4000;
        return;
    }
    param_1[0x22] = (void*)0;
}
}
