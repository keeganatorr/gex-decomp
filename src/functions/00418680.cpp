// Adapted from pc_decomp_backup/src/functions/FUN_00418680.cpp
// Historical source SHA256: b1138eb61f9707db405be98dd3ef0e5044b2257e46bbb76e17b042c03d7fcb3b
extern "C" {
extern "C" { extern int DAT_0049FB90; }
extern void** DAT_004A27FC;

extern "C" int __cdecl GEX_Target(int param_1, void** param_2)
{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar3 = (int)DAT_004A27FC[0x1f] - (int)param_2[0x1f];
    iVar2 = (int)DAT_004A27FC[0x1e] + (-iVar3 - (int)param_2[0x1e]);
    iVar1 = (int)DAT_004A27FC[0x1e] + (iVar3 - (int)param_2[0x1e]);
    if (iVar3 < 1) {
        DAT_0049FB90 = 0;
        return param_1;
    }
    if (iVar2 > -0x100000 && iVar2 < 0x100000) {
        DAT_0049FB90 = 1;
        return param_1;
    }
    if (iVar1 > -0x100000 && iVar1 < 0x100000) {
        DAT_0049FB90 = -1;
        return param_1;
    }
    DAT_0049FB90 = 0;
    return param_1;
}
}
