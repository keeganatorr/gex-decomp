// Adapted from pc_decomp_backup/src/functions/FUN_0043B920.cpp
// Historical source SHA256: 16fe063925e64cd1efc2c0ea9c2a5471dc0c26596b4da2ea2fdcb5ec95197397
extern "C" {
extern "C" void* FUN_004195D0(int, int, int, int);
extern "C" void __cdecl FUN_00419BE0(void*, void*);
extern "C" void __cdecl FUN_00419B80(void*, int);
extern "C" { extern void** DAT_00464E08; }
extern "C" { extern void** DAT_00464E14; }
extern "C" { extern int DAT_004A2ABC; }
extern "C" { extern int DAT_004A2A04; }
extern "C" { extern int DAT_00464E0C; }
extern "C" { extern int DAT_00455B8C; }

extern "C" void __cdecl ob259Init_0043b920(void** param_1, int param_2)
{
    if ((int)param_1[0x26] == 0x100) {
        if (param_2 != 0) {
            DAT_00464E08 = (void**)0;
            return;
        }
        DAT_00464E08 = (void**)FUN_004195D0(0x103, (int)param_1[0x1e], (int)param_1[0x1f], (int)param_1[3]);
        if (DAT_00464E08 != 0) {
            DAT_00464E08[0x14] = 0;
            DAT_00464E08[0x15] = 0;
            DAT_00464E08[0x17] = 0;
            if (DAT_00464E08 != 0 && DAT_00464E14 != 0) {
                FUN_00419BE0(DAT_00464E08, DAT_00464E14);
            }
        }
        DAT_004A2ABC = 0;
        param_1[0x14] = 0;
        param_1[0x18] = 0;
        DAT_004A2A04 = 0;
        DAT_00464E0C = 1;
        DAT_00455B8C = 1;
        FUN_00419B80(param_1, 0);
    }
}
}
