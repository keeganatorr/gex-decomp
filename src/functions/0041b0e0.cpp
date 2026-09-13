// Adapted from pc_decomp_backup/src/functions/FUN_0041B0E0.cpp
// Historical source SHA256: 4da07ac9957f6f25a25f5960f5745416e2b32e3e1c7c22d53e81eade9180563b
extern "C" {
extern "C" { extern int FUN_004A2990; }
extern "C" int __cdecl FUN_004404b0(int, unsigned int, unsigned int);
extern "C" int __cdecl FUN_00419FE0(int, unsigned int, unsigned int);

extern "C" void __cdecl GEX_Target(unsigned int param_1, unsigned int param_2) {
    if ((((-1 < (int)param_1) && (-1 < (int)param_2)))) {
        int lv = *(int*)(FUN_004A2990 + 4);
        if ((int)param_1 < *(int*)(lv + 4) && (int)param_2 < *(int*)(lv + 8)) {
            unsigned short* puVar2 = (unsigned short*)FUN_004404b0(lv, param_1, param_2);
            if (puVar2 != (unsigned short*)0x0) {
                int iVar3 = FUN_00419FE0(FUN_004A2990, param_1, param_2);
                if (iVar3 != 0) {
                    *puVar2 = *(unsigned short*)(iVar3 + 10);
                }
            }
        }
    }
}
}
