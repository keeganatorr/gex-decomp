typedef int GXObject;

extern "C" {
void __cdecl FUN_0042E850(void*);
void __cdecl FUN_00441150(void*);

extern int DAT_00463F10;
extern int DAT_00463F98;
extern int DAT_00463F14;
extern int DAT_00463E0C;

void __cdecl ob231Draw_00430ea0(GXObject** param_1)
{
    GXObject* pGVar1 = param_1[0x1e];
    GXObject* pGVar2 = param_1[0x1f];
    GXObject* pGVar3 = param_1[0x32];
    GXObject* pGVar4 = param_1[0x33];

    FUN_0042E850(param_1);
    if (DAT_00463F10 <= (int)param_1[0x1e] &&
        (int)param_1[0x1e] < DAT_00463F98 &&
        DAT_00463F14 <= (int)param_1[0x1f] &&
        (int)param_1[0x1f] < DAT_00463E0C) {
        FUN_00441150(param_1);
    }

    param_1[0x1e] = pGVar1;
    param_1[0x1f] = pGVar2;
    param_1[0x32] = pGVar3;
    param_1[0x33] = pGVar4;
}
}
