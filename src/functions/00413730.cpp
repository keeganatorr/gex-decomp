struct GXObject {
    unsigned char unknown00[0x54];
    int count54;
    unsigned char unknown58[0x24];
    int ypos;
    int save80;
    unsigned char unknown84[0x8];
    int save8c;
    unsigned char unknown90[0x8];
    int frac98;
    int speed9c;
    int timerA0;
    int orderA4;
    int newA8;
    int newAC;
    unsigned char unknownB0[0x14];
    int angleC4;
    unsigned char unknownC8[0x14];
    int yvelDC;
};

extern "C" {
extern int M1_CurrentLevel_004a2990;
extern int DAT_004a025c;
void __cdecl InitPlayerFalling_004252b0(GXObject *gob);
void __cdecl InitPlayerStopFall_00425c10(GXObject *gob);
void __cdecl GOB_KeepOutOfTiles_00420960(GXObject *gob);
void __cdecl FUN_004214d0_y_pos_movement(GXObject *gob);
int __cdecl FUN_004219c0_Velocity(GXObject *gob);
void __cdecl TILES_CheckYTileClid_0042d2c0(int level, GXObject *gob, int (__cdecl *velocity)(GXObject *));
void __cdecl FUN_004213f0_GexMovementLeftandRight(GXObject *gob);
void __cdecl FUN_004213c0(int level, GXObject *gob);
int __cdecl FUN_004212d0_pStateUnk_yVel(GXObject *gob);
int __cdecl FUN_004215d0_pStateUnk_Jump(GXObject *gob, int speed);

void __cdecl GEX_Target(GXObject *gob)
{
    gob->save80 = gob->newA8;
    gob->save8c = gob->newAC;
    gob->angleC4 += gob->speed9c;
    gob->angleC4 &= 0xff0000;
    gob->frac98 += 0xc000;
    if (gob->frac98 >= 0x10000) {
        gob->frac98 -= 0x10000;
        gob->count54++;
        if (gob->count54 > 2) {
            gob->ypos += 0x100000;
            DAT_004a025c = 0xfffe0000;
            gob->yvelDC = 0xfffe0000;
            InitPlayerFalling_004252b0(gob);
            return;
        }
        GOB_KeepOutOfTiles_00420960(gob);
    }
    if (gob->timerA0) {
        if (gob->orderA4) {
            FUN_004214d0_y_pos_movement(gob);
            TILES_CheckYTileClid_0042d2c0(M1_CurrentLevel_004a2990, gob, FUN_004219c0_Velocity);
            FUN_004213f0_GexMovementLeftandRight(gob);
            FUN_004213c0(M1_CurrentLevel_004a2990, gob);
        } else {
            FUN_004213f0_GexMovementLeftandRight(gob);
            FUN_004213c0(M1_CurrentLevel_004a2990, gob);
            FUN_004214d0_y_pos_movement(gob);
            TILES_CheckYTileClid_0042d2c0(M1_CurrentLevel_004a2990, gob, FUN_004219c0_Velocity);
        }
        if (FUN_004212d0_pStateUnk_yVel(gob)) {
            gob->ypos += 0x100000;
            return;
        }
        if (FUN_004215d0_pStateUnk_Jump(gob, 0x200000)) {
            gob->ypos += 0x100000;
            DAT_004a025c = 0xfffe0000;
            gob->yvelDC = 0xfffe0000;
            InitPlayerStopFall_00425c10(gob);
            return;
        }
    }
    gob->timerA0++;
}
}
