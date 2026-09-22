extern "C" {
extern int DAT_00458c78_ButtonUnk10;
extern int DAT_004a0218_pState;
extern int DAT_004A022C;
extern int DAT_004A284C;
extern unsigned char DAT_004A0286;
extern unsigned char DAT_004A0293;
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0295;
void __cdecl FUN_00423800_pStateUnk(int *);
int __cdecl FUN_00412a00_CheckInput(int *);
void __cdecl FUN_00413BA0(int *);
void __cdecl FUN_004144E0(int *);
void __cdecl FUN_00421900(int *);
void __cdecl InitPlayerFaceUnspin_00412ee0(int *);

void __cdecl GEX_Target(int *p)
{
    FUN_00423800_pStateUnk(p);
    if (DAT_00458c78_ButtonUnk10 != 0 || DAT_004A0294 != 0)
        goto crawl;

    if (DAT_004A0293 != 0 && DAT_004A0295 == 0) {
        p[0x1e] = p[0x2a];
        p[0x1f] = p[0x2b];
        p[0x31] = (p[0x31] + 0x200000) & 0xc00000;
        p[0x31] = FUN_00412a00_CheckInput(p);
        FUN_00413BA0(p);
        return;
    }

    DAT_004A284C = 1;
    if (DAT_004A0286 == 0)
        p[0x29] = 1;

    p[0x31] += (p[0x1b] & 0x80000000u) ? 0x3c0000 : -0x3c0000;
    p[0x31] &= 0xff0000;
    if (++p[0x26] > 8) {
        p[0x26] = 0;
        if (DAT_004A0286 == 0 || p[0x29] == 0)
            goto unspin;
        p[0x29] = 0;
        if (++p[0x27] == 3) {
            p[0x15] = 4;
            DAT_004a0218_pState = 0x6a;
        } else {
            DAT_004a0218_pState = 0x67;
        }
        FUN_00421900(p);
    }
    DAT_004A022C = 1;
    return;

unspin:
    p[0x1e] = p[0x2a];
    p[0x1f] = p[0x2b];
    InitPlayerFaceUnspin_00412ee0(p);
    return;

crawl:
    p[0x1e] = p[0x2a];
    p[0x1f] = p[0x2b];
    p[0x31] = (p[0x31] + 0x200000) & 0xc00000;
    p[0x31] = FUN_00412a00_CheckInput(p);
    FUN_004144E0(p);
}
}
