// Adapted from pc_decomp_backup/src/functions/FUN_0042DBD0.cpp
// Historical source SHA256: 7b6bc74d33136262bb831f0fbbebcb1c208c65d7cf24fb5d7e3018dfb2de4d8a
extern "C" {
extern "C" { extern unsigned int FUN_0045B9A0[]; }
extern "C" void __cdecl FUN_0042cc70(int, int*);
extern "C" int __cdecl FUN_0042d680(int*);

extern "C" int __cdecl GEX_Target(int* param_1, int param_2)
{
    unsigned int uVar6 = (unsigned int)param_1[0x61] & 0x1fffff;
    unsigned int uVar5 = (unsigned int)param_1[0x62] & 0x1fffff;
    unsigned int uVar2 = FUN_0045B9A0[(*(unsigned short*)(param_2 + 6)) * 8] & 0xf000000;

    if (uVar2 < 0x2000001) {
        if (uVar2 == 0x2000000) {
            int iVar4 = 0x1f0000 - uVar6;
            if ((int)uVar5 <= iVar4) {
                param_1[0x1f] = param_1[0x1f] + (iVar4 - uVar5);
                param_1[0x3c] = (int)(((unsigned int)param_1[0x62] & 0xffe00000) + iVar4);
                if (param_1[0x3b] != 0) {
                    FUN_0042cc70(0, param_1);
                }
                return 1;
            }
        } else if (uVar2 == 0x1000000 && uVar5 <= uVar6) {
            param_1[0x1f] = param_1[0x1f] + (uVar6 - uVar5);
            param_1[0x3c] = (int)(((unsigned int)param_1[0x62] & 0xffe00000) + uVar6);
            if (param_1[0x3b] != 0) {
                FUN_0042cc70(0, param_1);
            }
            return 1;
        }
        return 0;
    }
    if (uVar2 == 0x4000000) return FUN_0042d680(param_1);
    if (uVar2 == 0x8000000) return FUN_0042d680(param_1);
    return 0;
}
}
