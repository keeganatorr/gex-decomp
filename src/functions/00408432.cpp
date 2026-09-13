// Adapted from pc_decomp_backup/src/functions/FUN_00408432.cpp
// Historical source SHA256: 0e2120b66210517b351890d1f975e1f86c889d9ea119a371e6b0548558125432
extern "C" {
extern int DAT_00455018;
extern int DAT_0047F050;
extern int DAT_00488004;

extern "C" int __cdecl GEX_Target()
{
    unsigned int uVar2;
    unsigned int uVar3;
    int* pcVar4;
    int* pcVar5;
    int* pcVar6;
    int* pcVar7;
    int local_80[32];

    pcVar4 = (int*)0x4554a0;
    do {
        uVar2 = 0xffffffff;
        pcVar6 = pcVar4 + (-0x10 / 4);
        do {
            pcVar7 = pcVar6;
            if (uVar2 == 0) break;
            uVar2 = uVar2 - 1;
            pcVar7 = pcVar6 + 1;
            pcVar6 = pcVar7;
        } while (1);

        uVar2 = ~uVar2;
        pcVar6 = pcVar7 + (-(int)uVar2 / 4);
        pcVar7 = pcVar4;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            pcVar6 = pcVar6 + 1;
            pcVar7 = pcVar7 + 1;
        }
        pcVar5 = (int*)((char*)pcVar4 + 0x3c);
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        }

        if (pcVar5 == (int*)0x4556a0) {
            DAT_0047F050 = DAT_00455018;
            DAT_00488004 = 0;
            return 0;
        }
        pcVar4 = pcVar5;
    } while (1);
}
}
