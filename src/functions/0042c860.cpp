// Adapted from pc_decomp_backup/src/functions/FUN_0042C860.cpp
// Historical source SHA256: 6a0f9e8816de7891cf4854d79739a12e6f3a3d1b0fe8948857e0fec604c30903
extern "C" {
extern int GXObject_00463b70_gob_xScale;
extern int DAT_00463b5c;

extern "C" void __cdecl GEX_Target(int *param_1, int param_2, int param_3)
{
    int iVar2, iVar3, iVar4;

    iVar2 = param_2;
    if (param_2 < 0) iVar2 = -param_2;

    iVar3 = param_3;
    if (param_3 < 0) iVar3 = -param_3;

    iVar4 = iVar3;
    if (iVar3 <= iVar2) iVar4 = iVar2;

    if (iVar2 < (iVar4 >> 1)) {
        if (param_3 < 1) {
            param_1[0x14] = 0x1a;
            param_1[0x28] = 0xa;
            param_1[0x2c] = 0;
            param_1[0x32] = GXObject_00463b70_gob_xScale;
        } else {
            param_1[0x14] = 0x1b;
            param_1[0x28] = 0xa;
            param_1[0x2c] = 4;
            param_1[0x32] = GXObject_00463b70_gob_xScale;
        }
        DAT_00463b5c = 4;
        return;
    }

    if (iVar3 < (iVar4 >> 1)) {
        param_1[0x14] = 0x1c;
        param_1[0x28] = 0xa;
        if (param_2 < 1) {
            param_1[0x2c] = 6;
            param_1[0x32] = GXObject_00463b70_gob_xScale;
        } else {
            param_1[0x2c] = 2;
            param_1[0x32] = -(int)GXObject_00463b70_gob_xScale;
        }
        DAT_00463b5c = 4;
        return;
    }

    if (param_2 > 0 && param_3 < 0) {
        param_1[0x14] = 0x17;
        param_1[0x28] = 0xa;
        param_1[0x32] = -(int)GXObject_00463b70_gob_xScale;
        param_1[0x2c] = 1;
        DAT_00463b5c = 2;
        return;
    }

    if (param_2 < 0 && param_3 > 0) {
        param_1[0x14] = 0x16;
        param_1[0x28] = 0xa;
        param_1[0x2c] = 5;
        param_1[0x32] = GXObject_00463b70_gob_xScale;
        DAT_00463b5c = 2;
        return;
    }

    if (param_2 > 0 && param_3 > 0) {
        param_1[0x14] = 0x16;
        param_1[0x28] = 0xa;
        param_1[0x32] = -(int)GXObject_00463b70_gob_xScale;
        param_1[0x2c] = 3;
        DAT_00463b5c = 2;
        return;
    }

    param_1[0x14] = 0x17;
    param_1[0x28] = 0xa;
    param_1[0x2c] = 7;
    param_1[0x32] = GXObject_00463b70_gob_xScale;
    DAT_00463b5c = 2;
}
}
