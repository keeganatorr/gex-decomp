extern "C" {
extern int DAT_00456168;
}

struct GXObject;

extern "C" void __cdecl GEX_Target(GXObject **param_1)
{
    GXObject *pGVar1;
    GXObject *pGVar2;

    pGVar1 = param_1[0x2c];
    pGVar2 = param_1[0x2a];
    if (pGVar2 == (GXObject *)0x10) {
        param_1[0x2c] = (GXObject *)0x1;
    } else if (pGVar2 == (GXObject *)0xe) {
        param_1[0x2c] = (GXObject *)0x2;
    } else if (pGVar2 == (GXObject *)0xc) {
        param_1[0x2c] = (GXObject *)0x3;
    } else if (pGVar2 == (GXObject *)0x70) {
        param_1[0x2c] = (GXObject *)0x4;
    } else {
        param_1[0x2c] = (GXObject *)0x5;
        if (pGVar2 != (GXObject *)0x12) {
            param_1[0x2c] = (GXObject *)0x0;
        }
    }
    if (pGVar1 != param_1[0x2c]) {
        *(int *)((int)&DAT_00456168 + (int)param_1[0x2c] * 0x10) = 0;
    }
}
