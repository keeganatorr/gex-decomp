// Adapted from pc_decomp_backup/src/functions/FUN_00435760.cpp
// Historical source SHA256: a49318eb4ca8b9f3814469b8de901098107777efd27aeb51386fb9dd9bed0239
extern "C" {
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int FUN_004A2AD4;
extern int DAT_0045b7cc;
extern int DAT_0045b7d0;
extern int DAT_0045b7d8_framecount_;
extern int DAT_0045b7b0;
extern int DAT_0045b7b8;
extern int DAT_0045b798;
extern int DAT_0045b7a0;
extern int DAT_0045b7a4;
extern int FUN_004A2990;

extern "C" int __cdecl FUN_0040FCE0(int *);
extern "C" void __cdecl FUN_00420770_Movement_unk(int *, int);
extern "C" void __cdecl FUN_0040F260(int *);
extern "C" void __cdecl FUN_0040F2A0(int *);
extern "C" int __cdecl FUN_0041A0A0(int *, int);
extern "C" void __cdecl FUN_0041A160(int *, int *);
extern "C" void __cdecl FUN_00419A80(int *);

extern "C" void __cdecl GEX_Target(int *param_1)
{
    int pGVar1;
    int iVar2;

    param_1[0x35] = param_1[0x1e];
    param_1[0x36] = param_1[0x1f];
    param_1[0x3f] = param_1[0x1b];
    param_1[0x3d] = param_1[0x14];
    param_1[0x3e] = param_1[0x15];
    param_1[0x39] = 0;
    pGVar1 = param_1[0x38];
    param_1[0x3a] = 0;
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    pGVar1 = (pGVar1 * 2 ^ (unsigned int)pGVar1) & 0x200 ^ (unsigned int)pGVar1;
    param_1[0x38] = pGVar1;
    param_1[0x38] = (unsigned int)pGVar1 & 0xfffffeff;
    iVar2 = FUN_0040FCE0(param_1);
    if (iVar2 != 0) goto FUN_0043594F;
    if (param_1[0x1c] == 0) {
        if (DAT_0045b7cc != 0) {
            param_1[0x1c] = 1;
            iVar2 = *(int *)((int)&DAT_0045b7d8_framecount_ + param_1[0x26] * 4);
            param_1[0x15] = 0;
            param_1[0x27] = 0;
            param_1[0x14] = iVar2 + 0xb;
            return;
        }
        if (DAT_0045b7d0 != 0) {
            param_1[0x1e] = param_1[0x2b] + CAMERA_XPos_004a2a38;
            param_1[0x1f] = param_1[0x2c] + CAMERA_YPos_004a2a1c;
        }
        FUN_00420770_Movement_unk(param_1, 0x45);
        param_1[3] = FUN_004A2AD4;
        pGVar1 = param_1[0x27] + DAT_0045b7b0;
        param_1[0x27] = pGVar1;
        if (0x10000 < pGVar1) {
            param_1[0x27] = pGVar1 - 0x80;
            param_1[0x28] = param_1[0x28] + 1;
        }
        if (((unsigned int)param_1[0x2d] & 2) != 0) {
            FUN_0040F260(param_1);
            FUN_0040F2A0(param_1);
            iVar2 = FUN_0041A0A0(param_1, DAT_0045b798);
            if (iVar2 != 0) {
                pGVar1 = DAT_0045b7a0 - param_1[0x23];
                if (DAT_0045b7a4 <= DAT_0045b7a0 - param_1[0x23]) {
                    pGVar1 = DAT_0045b7a4;
                }
                param_1[0x23] = pGVar1;
                FUN_0041A160((int *)FUN_004A2990, param_1);
                param_1[0x1f] = param_1[0x1f] - DAT_0045b798;
            }
        }
        param_1[0x14] = 0;
        pGVar1 = param_1[0x26];
    }
    else {
        if (param_1[0x1c] != 1) goto FUN_0043594F;
        pGVar1 = param_1[0x27] + DAT_0045b7b8;
        param_1[0x27] = pGVar1;
        if (pGVar1 < 0x10001) goto FUN_0043594F;
        param_1[0x27] = pGVar1 - 0x80;
        if (param_1[0x15] == 4) {
            FUN_00419A80(param_1);
            goto FUN_0043594F;
        }
        pGVar1 = param_1[0x15] + 1;
    }
    param_1[0x15] = pGVar1;
FUN_0043594F:
    if (param_1[0x45] == -1) {
        param_1[0x44] = 0;
    }
    param_1[0x45] = -1;
}
}
