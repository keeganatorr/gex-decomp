// Adapted from pc_decomp_backup/src/functions/FUN_00413730.cpp
// Historical source SHA256: 1e2c247e5e16da170d90df0b182440dd4218d4ef6ca247819f45eae4c78950cb
extern "C" {
extern int FUN_004A2990;
extern int DAT_004a025c;

extern "C" void __cdecl FUN_00420960(void **);
extern "C" void __cdecl FUN_004213f0_GexMovementLeftandRight(void *);
extern "C" void __cdecl FUN_004213c0(int, void **);
extern "C" void __cdecl FUN_004214d0_y_pos_movement(void **);
extern "C" void __cdecl FUN_0042D2C0(int, void **, void *);
extern "C" void __cdecl FUN_004219c0_Velocity();
extern "C" int __cdecl FUN_004212d0_pStateUnk_yVel(void **);
extern "C" int __cdecl FUN_004215d0_pStateUnk_Jump(void **);
extern "C" void __cdecl FUN_00425C10(void **);
extern "C" void __cdecl FUN_004252B0(void **);

extern "C" void __cdecl GEX_Target(void **gOb)
{
    int pGVar1;
    int iVar3;

    gOb[0x20] = gOb[0x2a];
    gOb[0x23] = gOb[0x2b];
    pGVar1 = *(int *)gOb[0x31] + (int)gOb[0x27] + -0xc;
    gOb[0x31] = (void *)pGVar1;
    gOb[0x31] = (void *)((unsigned int)pGVar1 & 0xff0000);
    pGVar1 = (int)gOb[0x26];
    gOb[0x26] = (void *)(pGVar1 + 0x60);
    if (0xffff < pGVar1 + 0x60) {
        gOb[0x26] = (void *)(pGVar1 + -0x20);
        gOb[0x15] = (void *)((int)gOb[0x15] + 1);
        if (2 < (int)gOb[0x15]) {
            gOb[0x1f] = (void *)((int)gOb[0x1f] + 0x800);
            DAT_004a025c = 0xfffe0000;
            gOb[0x37] = (void *)0xfffe0000;
            FUN_004252B0(gOb);
            return;
        }
        FUN_00420960(gOb);
    }
    if (gOb[0x28] != (void *)0x0) {
        if (gOb[0x29] == (void *)0x0) {
            FUN_004213f0_GexMovementLeftandRight((void *)gOb);
            FUN_004213c0(FUN_004A2990, gOb);
            FUN_004214d0_y_pos_movement(gOb);
            FUN_0042D2C0(FUN_004A2990, gOb, (void *)FUN_004219c0_Velocity);
        }
        else {
            FUN_004214d0_y_pos_movement(gOb);
            FUN_0042D2C0(FUN_004A2990, gOb, (void *)FUN_004219c0_Velocity);
            FUN_004213f0_GexMovementLeftandRight((void *)gOb);
            FUN_004213c0(FUN_004A2990, gOb);
        }
        iVar3 = FUN_004212d0_pStateUnk_yVel(gOb);
        if (iVar3 != 0) {
            gOb[0x1f] = (void *)((int)gOb[0x1f] + 0x800);
            return;
        }
        iVar3 = FUN_004215d0_pStateUnk_Jump(gOb);
        if (iVar3 != 0) {
            gOb[0x1f] = (void *)((int)gOb[0x1f] + 0x800);
            DAT_004a025c = 0xfffe0000;
            gOb[0x37] = (void *)0xfffe0000;
            FUN_00425C10(gOb);
            return;
        }
    }
    gOb[0x28] = (void *)((int)gOb[0x28] + 1);
}
}
