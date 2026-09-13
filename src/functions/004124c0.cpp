// Adapted from pc_decomp_backup/src/functions/FUN_004124C0.cpp
// Historical source SHA256: 1618dd7761bdbc6622d0524ba6b0bdd97ed74e6d2636ef2b3e57adcfb73a0e10
extern "C" {
extern "C" int __cdecl FUN_00421f20_pStateUnk_Side(void**);
extern "C" void __cdecl FUN_00411230(void**, void***, void***, void***);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl FUN_00424090(void**);
extern "C" { extern int FUN_004A2990; }
extern "C" { extern void** FUN_004A2864; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int result = FUN_00421f20_pStateUnk_Side(param_1);
    if (result != 0) {
        int* p26 = (int*)&param_1[0x26];
        (*p26)++;
        if (*p26 > 1) {
            int* p15 = (int*)&param_1[0x15];
            (*p15)++;
            param_1[0x26] = 0;
            int offset = *((int*)0x004586a8 + *p15);
            if (((unsigned int)param_1[0x1b] & 0x80000000) == 0) offset = -offset;
            param_1[0x1e] = (void*)((int)param_1[0x1e] + offset - 0x1c);
            param_1[0x1f] = (void*)((int)param_1[0x1f] + *((int*)0x004586c0 + *p15) - 0x1c);
            if (*p15 > 3) {
                if (FUN_004A2864 != 0) {
                    param_1[0x45] = 0;
                    param_1[0x3b] = (void*)1;
                    param_1[0x44] = (void*)FUN_004A2864;
                    FUN_004A2864 = 0;
                }
                FUN_00421560_DrawCharacter(FUN_004A2990, param_1);
                FUN_00424090(param_1);
            }
        }
    }
}
}
