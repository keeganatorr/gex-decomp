extern "C" {
void __cdecl FUN_00413EE0(void**);
int __cdecl FUN_00423b00_AirToFace_or_JumpTongueLash(void**);
void __cdecl FUN_004244e0_left_right_move_xpos(void**, int);
void __cdecl FUN_004213f0_GexMovementLeftandRight(void*);
void __cdecl FUN_004213c0(int, void**);
int __cdecl FUN_00421a00_AirToSideCrawl(void**);
void __cdecl FUN_004214d0_y_pos_movement(void**);
unsigned int __cdecl FUN_00421900(void**);
void __cdecl FUN_0042D2C0(int, void**, void*);
void __cdecl FUN_00413C80(void**);
void __cdecl FUN_00421740_pStateUnk_Jump(void**);
int __cdecl FUN_004212d0_pStateUnk_yVel(void**);
int __cdecl FUN_004215d0_pStateUnk_Jump(void**, int);
void __cdecl FUN_00425C10(void**);
extern int FUN_004A284C;
extern unsigned char DAT_004A0283;
extern int DAT_004a01e0;
int __cdecl FUN_004219C0(void**);
extern int FUN_004A2990;
void __cdecl PlayerBounceFall_00413d60(void** GexObject) {
    FUN_004A284C = 1;
    if (DAT_004A0283 == 0) FUN_00413EE0(GexObject);
    if ((int)GexObject[0x23] > 0x20000) GexObject[0x15] = (void*)1;
    if ((int)GexObject[0x23] > 0x50000) GexObject[0x15] = (void*)2;
    int iVar1 = FUN_00423b00_AirToFace_or_JumpTongueLash(GexObject);
    if (iVar1 == 0) {
        FUN_004244e0_left_right_move_xpos(GexObject, 0x10000);
        FUN_004213f0_GexMovementLeftandRight(GexObject);
        DAT_004a01e0 = 0;
        FUN_004213c0(FUN_004A2990, GexObject);
        iVar1 = FUN_00421a00_AirToSideCrawl(GexObject);
        if (iVar1 == 0) {
            FUN_004214d0_y_pos_movement(GexObject);
            unsigned int uVar2 = FUN_00421900(GexObject);
            FUN_0042D2C0(FUN_004A2990, GexObject, (void*)&FUN_004219C0);
            if (uVar2 != 0) { FUN_00413C80(GexObject); return; }
            FUN_00421740_pStateUnk_Jump(GexObject);
            iVar1 = FUN_004212d0_pStateUnk_yVel(GexObject);
            if (iVar1 == 0) {
                iVar1 = FUN_004215d0_pStateUnk_Jump(GexObject, 0);
                if (iVar1 != 0) FUN_00425C10(GexObject);
            }
        }
    }
}
}
