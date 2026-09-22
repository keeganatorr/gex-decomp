extern "C" {
extern int DAT_0045A6D0;
extern int DAT_004A025C;
extern int DAT_004A0264;
extern unsigned char DAT_004A0280;
extern unsigned char DAT_004A0281;
extern unsigned char DAT_004A0282;
extern unsigned char DAT_004A0283;
extern unsigned char DAT_004A0294;
void __cdecl FUN_00420BC0(void**);
void __cdecl FUN_00420960(void**);
void __cdecl FUN_004143B0(void**);

void __cdecl GEX_Target(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x15] = 0;
    param_1[0x26] = 0;
    param_1[0x1c] = (void*)0x39;
    param_1[0x14] = (void*)0x5a;
    void* value = (void*)DAT_0045A6D0;
    param_1[0x25] = (void*)0x14000;
    param_1[0x24] = (void*)0xe0000;
    param_1[0x21] = value;
    param_1[0x37] = (void*)0xffe00000;
    DAT_004A025C = 0xffe00000;
    param_1[0x23] = (void*)0x20000;
    param_1[0x20] = 0;
    if (DAT_004A0280 != 0) {
        param_1[0x20] = (void*)0xfffc0000;
    } else if (DAT_004A0281 != 0) {
        param_1[0x20] = (void*)0x40000;
    }
    if (DAT_004A0282 != 0) {
        param_1[0x23] = (void*)0x80000;
    } else if (DAT_004A0283 != 0) {
        param_1[0x23] = (void*)0x40000;
    }
    if (DAT_004A0264 != 0) {
        param_1[0x20] = (void*)(((int)param_1[0x20] >> 8) * 0x180);
        param_1[0x23] = (void*)(((int)param_1[0x23] >> 8) * 0x180);
    }
    param_1[0x2a] = param_1[0x20];
    param_1[0x2b] = param_1[0x23];
    DAT_004A0294 = 0;
    FUN_00420960(param_1);
    FUN_004143B0(param_1);
}
}
