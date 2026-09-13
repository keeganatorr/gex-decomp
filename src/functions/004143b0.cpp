// Adapted from pc_decomp_backup/src/functions/FUN_004143B0.cpp
// Historical source SHA256: bc95df7ec8fb8463140382feceeb7d46d76751583a58664ed437bef694a3490f
extern "C" {
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int DAT_004a025c; }
extern "C" { extern int FUN_004219c0_Velocity; }
extern "C" void __cdecl FUN_00423b80_pStateUnk(void**);
extern "C" void __cdecl FUN_004252B0(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_004244e0_left_right_move_xpos(void**, int);
extern "C" void __cdecl FUN_004213f0_GexMovementLeftandRight(void*);
extern "C" void __cdecl FUN_004213c0(int, void**);
extern "C" int __cdecl FUN_00421a00_AirToSideCrawl(void**);
extern "C" void __cdecl FUN_004214d0_y_pos_movement(void**);
extern "C" void __cdecl FUN_0042D2C0(int, void**, int);
extern "C" void __cdecl FUN_00421740_pStateUnk_Jump(void**);
extern "C" int __cdecl FUN_004212d0_pStateUnk_yVel(void**);
extern "C" int __cdecl FUN_004215d0_pStateUnk_Jump(void**);
extern "C" void __cdecl FUN_00425C10(void**);

extern "C" void __cdecl GEX_Target(void** param_1) {
    void* pGVar1;
    int iVar2;

    param_1[0x20] = param_1[0x2a];
    param_1[0x23] = param_1[0x2b];
    FUN_00423b80_pStateUnk(param_1);
    pGVar1 = (void*)((int)param_1[0x26] + 1);
    param_1[0x26] = pGVar1;
    if (0 < (int)pGVar1) {
        if (param_1[0x15] == (void*)2) {
            param_1[0x1f] = (void*)((int)param_1[0x1f] + 0x1000);
            DAT_004a025c = 0xffe00000;
            param_1[0x37] = (void*)0xffe00000;
            FUN_004252B0(param_1);
            return;
        }
        param_1[0x26] = (void*)0x0;
        param_1[0x15] = (void*)((int)param_1[0x15] + 1);
        FUN_00420960(param_1);
    }
    FUN_004244e0_left_right_move_xpos(param_1, 0x10000);
    FUN_004213f0_GexMovementLeftandRight((void*)param_1);
    FUN_004213c0(FUN_004A2990, param_1);
    iVar2 = FUN_00421a00_AirToSideCrawl(param_1);
    if (iVar2 == 0) {
        FUN_004214d0_y_pos_movement(param_1);
        FUN_0042D2C0(FUN_004A2990, param_1, FUN_004219c0_Velocity);
        FUN_00421740_pStateUnk_Jump(param_1);
        iVar2 = FUN_004212d0_pStateUnk_yVel(param_1);
        if (iVar2 != 0) {
            param_1[0x1f] = (void*)((int)param_1[0x1f] + 0x1000);
            return;
        }
        iVar2 = FUN_004215d0_pStateUnk_Jump(param_1);
        if (iVar2 != 0) {
            param_1[0x1f] = (void*)((int)param_1[0x1f] + 0x1000);
            DAT_004a025c = 0xffe00000;
            param_1[0x37] = (void*)0xffe00000;
            FUN_00425C10(param_1);
        }
    }
}
}
