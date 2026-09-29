extern "C" {
void __cdecl FUN_0040F260(int *);
void __cdecl FUN_0040F2A0(int *);
int __cdecl FUN_0041A480(int);
void __cdecl FUN_00419A80(int *);
void __cdecl FUN_0042e850(int *);
void __cdecl FUN_00441150(int *);
void __cdecl FUN_00444590(int *);

void __cdecl ob92Draw_0042e2b0(int *param_1)
{
    int pGVar1;
    int saved_1e, saved_1f, saved_32, saved_33;
    if ((param_1[0x1b] & 0x4000) != 0)
        FUN_0040F260(param_1);
    if ((param_1[0x1b] & 0x8000) != 0)
        FUN_0040F2A0(param_1);
    pGVar1 = param_1[0x1c];
    if ((pGVar1 & 0xf) != 0) {
        if ((pGVar1 & 1) != 0) {
            param_1[0x28] = param_1[0x29] + param_1[0x28];
            param_1[0x31] = param_1[0x28] + param_1[0x31];
            param_1[0x31] = param_1[0x31] & 0xff0000;
        }
        if ((pGVar1 & 2) != 0) {
            param_1[0x2a] = param_1[0x2b] + param_1[0x2a];
            param_1[0x32] = param_1[0x32] + param_1[0x2a];
        }
        if ((pGVar1 & 4) != 0) {
            param_1[0x2c] = param_1[0x2d] + param_1[0x2c];
            param_1[0x33] = param_1[0x33] + param_1[0x2c];
        }
    }
    if ((pGVar1 & 0x10) != 0) {
        param_1[0x27] = param_1[0x27] + 1;
        if (param_1[0x26] <= param_1[0x27]) {
            param_1[0x27] = 0;
            param_1[0x15] = param_1[0x15] + 1;
            if ((pGVar1 & 0x20) != 0) {
                if (FUN_0041A480((int)param_1) == 0) {
                    FUN_00419A80(param_1);
                    return;
                }
            }
        }
    }
    if (param_1[0x2e] != 0) {
        param_1[0x2e] = param_1[0x2e] - 1;
        if (param_1[0x2e] <= 0) {
            FUN_00419A80(param_1);
            return;
        }
    }
    if ((param_1[0x38] & 0x40) != 0) {
        saved_1e = param_1[0x1e];
        saved_1f = param_1[0x1f];
        saved_32 = param_1[0x32];
        saved_33 = param_1[0x33];
        FUN_0042e850(param_1);
        FUN_00441150(param_1);
        param_1[0x1e] = saved_1e;
        param_1[0x1f] = saved_1f;
        param_1[0x32] = saved_32;
        param_1[0x33] = saved_33;
        return;
    }
    if (param_1[0x31] == 0 && (pGVar1 & 6) == 0) {
        FUN_00444590(param_1);
        return;
    }
    FUN_00441150(param_1);
}
}
