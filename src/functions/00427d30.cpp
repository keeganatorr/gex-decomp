typedef struct GXObject {
    unsigned char pad0[0x50];
    int gob_currentFrameGroup;  /* 0x50 */
    int gob_currentFrameIndex;  /* 0x54 */
    unsigned char pad58[0x6c - 0x58];
    unsigned int gob_flags;     /* 0x6c */
    unsigned char pad70[0x78 - 0x70];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char pad80[0x98 - 0x80];
    int gob_work0;              /* 0x98 */
    unsigned char pad9c[0xc4 - 0x9c];
    int gob_angle;              /* 0xc4 */
} GXObject;

typedef struct BUTTON_RECORD {
    unsigned char buttonLeft, buttonRight, buttonUp, buttonDown;
    unsigned char buttonA, buttonB, buttonC, buttonX, buttonL, buttonR, buttonStart;
    unsigned char unkB[4];
} BUTTON_RECORD;
typedef struct GXInputRecord {
    BUTTON_RECORD gxir_padButtons;        /* 0x0 */
    BUTTON_RECORD gxir_padJustOnButtons;  /* 0xf */
    unsigned char _pad1e[2];
    int gxir_dValue;                      /* 0x20 */
} GXInputRecord;

extern "C" {
extern GXInputRecord gInputControllers_004a0280[];
extern int DAT_00458c78_ButtonUnk10;
extern GXObject *gPlayerPlatform_004a2864;
extern GXObject *PTR_004a27f0;
extern int DAT_004a2860;
extern void *M1_CurrentLevel_004a2990;
extern int DAT_004a0218_pState;
int __cdecl FUN_00421f20_pStateUnk_Side(GXObject *);
int __cdecl FUN_00421f90(GXObject *);
void __cdecl InitPlayerSideJump_004138b0(GXObject *);
void __cdecl InitPlayerSideTongueLash_00412960(GXObject *);
void __cdecl InitPlayerSideSpin_00413170(GXObject *);
int __cdecl FUN_00420c40_CheckWallCollision(void *level, int x, int y);
void __cdecl FUN_004121b0_SideInside90Trans_Outer(GXObject *, int, int);
void __cdecl FUN_00411ff0_SideInside90Trans(GXObject *, int, int);
void __cdecl InitPlayerSideInside45Trans_00411b90(GXObject *);
void __cdecl InitPlayerSideOutside45Trans_00411d70(GXObject *);
void __cdecl InitPlayerSideGetup_004125b0(GXObject *);
void __cdecl InitPlayerSideOutside90Trans_004123c0(GXObject *);
unsigned short *__cdecl GOB_GetBlockAddress_00419fe0(void *level, int x, int y);
int __cdecl M1_GetContourDataFromID_0040f100(void *level, unsigned int id, unsigned int position);
void __cdecl FUN_004120c0_SideInside90Trans(GXObject *);
void __cdecl InitPlayerStand_00424090(GXObject *);
void __cdecl InitPlayerDuck_00427850(GXObject *);
void __cdecl InitPlayerSideUTurn_00412750(GXObject *);

void __cdecl PlayerSideCrawl_00427d30(GXObject *gob)
{
    int dir;
    int moved;
    int idle;
    int speed;
    int x;
    int y;
    int nx;
    int ny;
    int by;
    int tx;
    int d;
    int contour;
    unsigned short block;

    if (!FUN_00421f20_pStateUnk_Side(gob))
        return;
    dir = (gob->gob_flags & 0x80000000 ? 8 : 0) | gob->gob_angle >> 21;
    if (!gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonB && !DAT_00458c78_ButtonUnk10 && (dir == 6 || dir == 10 || FUN_00421f90(gob))) {
        if (!gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonA) {
            if (gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonC) {
                InitPlayerSideSpin_00413170(gob);
                return;
            }
            moved = 0;
            speed = gInputControllers_004a0280[0].gxir_padButtons.buttonL ? 0x70000 : 0x50000;
            idle = 0;
            x = gob->gob_xpos;
            y = gob->gob_ypos;
            switch (dir) {
            case 0:
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp) {
                    if (PTR_004a27f0 && DAT_004a2860 == 3) {
                        gPlayerPlatform_004a2864 = PTR_004a27f0;
                        FUN_004121b0_SideInside90Trans_Outer(gob, 0, 1);
                    } else {
                        y -= speed;
                        ny = y - 0x180000;
                        switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x, ny)) {
                        case 0xc0000000:
                            if (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x + 0x10000, ny) == 0xc0000000)
                                FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            else {
                                gob->gob_xpos = x;
                                gob->gob_ypos = y;
                                moved = 1;
                            }
                            break;
                        case 0xc0008000:
                            FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            break;
                        case 0xc2000000:
                            InitPlayerSideInside45Trans_00411b90(gob);
                            break;
                        case 0xc8000000:
                            InitPlayerSideOutside45Trans_00411d70(gob);
                            break;
                        case 0:
                            x += 0x10000;
                            if (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x, ny) == 0xc0000000)
                                FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            else
                                InitPlayerSideGetup_004125b0(gob);
                            break;
                        }
                    }
                } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonDown)
                    InitPlayerSideUTurn_00412750(gob);
                else
                    idle = 1;
                break;
            case 1:
                if (!gInputControllers_004a0280[0].gxir_padButtons.buttonUp && !gInputControllers_004a0280[0].gxir_padButtons.buttonRight) {
                    if (!gInputControllers_004a0280[0].gxir_padButtons.buttonDown && !gInputControllers_004a0280[0].gxir_padButtons.buttonLeft)
                        idle = 1;
                    else
                        InitPlayerSideUTurn_00412750(gob);
                } else {
                    x += speed;
                    y -= speed;
                    switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x + 0x180000, y - 0x180000)) {
                    case 0xc0000000:
                        InitPlayerSideInside45Trans_00411b90(gob);
                        break;
                    case 0xc2000000:
                        gob->gob_xpos = x;
                        gob->gob_ypos = y;
                        moved = 1;
                        break;
                    case 0:
                        InitPlayerSideOutside45Trans_00411d70(gob);
                        break;
                    }
                }
                break;
            case 2:
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonRight) {
                    if (PTR_004a27f0 && DAT_004a2860 == 1) {
                        gPlayerPlatform_004a2864 = PTR_004a27f0;
                        FUN_004121b0_SideInside90Trans_Outer(gob, 1, 0);
                    } else {
                        x += speed;
                        nx = x + 0x180000;
                        switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, nx, y)) {
                        case 0xc0000000:
                            if (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, nx, y + 0x10000) == 0xc0000000)
                                FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            else {
                                gob->gob_xpos = x;
                                gob->gob_ypos = y;
                                moved = 1;
                            }
                            break;
                        case 0xc0008000:
                            FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            break;
                        case 0xc1000000:
                            InitPlayerSideInside45Trans_00411b90(gob);
                            break;
                        case 0xc2000000:
                            InitPlayerSideOutside45Trans_00411d70(gob);
                            break;
                        case 0:
                            y += 0x10000;
                            if (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, nx, y) == 0xc0000000)
                                FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            else
                                InitPlayerSideOutside90Trans_004123c0(gob);
                            break;
                        }
                    }
                } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonLeft)
                    InitPlayerSideUTurn_00412750(gob);
                else
                    idle = 1;
                break;
            case 3:
                if (!gInputControllers_004a0280[0].gxir_padButtons.buttonDown && !gInputControllers_004a0280[0].gxir_padButtons.buttonRight) {
                    if (!gInputControllers_004a0280[0].gxir_padButtons.buttonUp && !gInputControllers_004a0280[0].gxir_padButtons.buttonLeft)
                        idle = 1;
                    else
                        InitPlayerSideUTurn_00412750(gob);
                } else {
                    x += speed;
                    y += speed;
                    switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x + 0x180000, y + 0x180000)) {
                    case 0xc0000000:
                        InitPlayerSideInside45Trans_00411b90(gob);
                        break;
                    case 0xc1000000:
                        gob->gob_xpos = x;
                        gob->gob_ypos = y;
                        moved = 1;
                        break;
                    case 0:
                        InitPlayerSideOutside45Trans_00411d70(gob);
                        break;
                    }
                }
                break;
            case 4:
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonDown) {
                    y += speed;
                    by = y + 0x180000;
                    switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x, by)) {
                    case 0xc0000000:
                        tx = x - 0x10000;
                        block = GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, tx, by)[1];
                        if (block && (contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, block, tx & 0x1f0000)) != 0 && (by & 0x1f0000) >= contour - 0x10000) {
                            FUN_004120c0_SideInside90Trans(gob);
                            return;
                        }
                        by = y - 0x80000;
                        block = GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, tx, by)[1];
                        if (block && (contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, block, tx & 0x1f0000)) != 0 && (d = y - (by & 0xffe00000) - contour + 0x190000) > 0 && d < 0x100000) {
                            FUN_004120c0_SideInside90Trans(gob);
                            return;
                        }
                        gob->gob_xpos = x;
                        gob->gob_ypos = y;
                        moved = 1;
                        break;
                    case 0xc0008000:
                        FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                        break;
                    case 0xc1000000:
                        InitPlayerSideOutside45Trans_00411d70(gob);
                        break;
                    case 0xc4000000:
                        InitPlayerSideInside45Trans_00411b90(gob);
                        break;
                    case 0:
                        if ((d = FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x - 0x10000, by)) != 0xc0000000 && d != 0x80000000 && !GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, x, by)[1])
                            InitPlayerSideOutside90Trans_004123c0(gob);
                        break;
                    }
                } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp)
                    InitPlayerSideUTurn_00412750(gob);
                else
                    idle = 1;
                break;
            case 5:
                if (!gInputControllers_004a0280[0].gxir_padButtons.buttonDown && !gInputControllers_004a0280[0].gxir_padButtons.buttonLeft) {
                    if (!gInputControllers_004a0280[0].gxir_padButtons.buttonUp && !gInputControllers_004a0280[0].gxir_padButtons.buttonRight)
                        idle = 1;
                    else
                        InitPlayerSideUTurn_00412750(gob);
                } else {
                    x -= speed;
                    y += speed;
                    switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x - 0x180000, y + 0x180000)) {
                    case 0xc0000000:
                        InitPlayerSideInside45Trans_00411b90(gob);
                        break;
                    case 0xc4000000:
                        gob->gob_xpos = x;
                        gob->gob_ypos = y;
                        moved = 1;
                        break;
                    case 0:
                        InitPlayerSideOutside45Trans_00411d70(gob);
                        break;
                    }
                }
                break;
            case 6:
                InitPlayerStand_00424090(gob);
                break;
            case 7:
                if (!gInputControllers_004a0280[0].gxir_padButtons.buttonUp && !gInputControllers_004a0280[0].gxir_padButtons.buttonLeft) {
                    if (!gInputControllers_004a0280[0].gxir_padButtons.buttonDown && !gInputControllers_004a0280[0].gxir_padButtons.buttonRight)
                        idle = 1;
                    else
                        InitPlayerSideUTurn_00412750(gob);
                } else {
                    x -= speed;
                    y -= speed;
                    switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x - 0x180000, y - 0x180000)) {
                    case 0xc0000000:
                        InitPlayerSideInside45Trans_00411b90(gob);
                        break;
                    case 0xc8000000:
                        gob->gob_xpos = x;
                        gob->gob_ypos = y;
                        moved = 1;
                        break;
                    case 0:
                        InitPlayerSideOutside45Trans_00411d70(gob);
                        break;
                    }
                }
                break;
            case 8:
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp) {
                    if (PTR_004a27f0 && DAT_004a2860 == 3) {
                        gPlayerPlatform_004a2864 = PTR_004a27f0;
                        FUN_004121b0_SideInside90Trans_Outer(gob, 0, 1);
                    } else {
                        y -= speed;
                        ny = y - 0x180000;
                        switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x, ny)) {
                        case 0xc0000000:
                            if (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x - 0x10000, ny) == 0xc0000000)
                                FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            else {
                                gob->gob_xpos = x;
                                gob->gob_ypos = y;
                                moved = 1;
                            }
                            break;
                        case 0xc0008000:
                            FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            break;
                        case 0xc1000000:
                            InitPlayerSideInside45Trans_00411b90(gob);
                            break;
                        case 0xc4000000:
                            InitPlayerSideOutside45Trans_00411d70(gob);
                            break;
                        case 0:
                            x -= 0x10000;
                            if (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x, ny) == 0xc0000000)
                                FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            else
                                InitPlayerSideGetup_004125b0(gob);
                            break;
                        }
                    }
                } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonDown)
                    InitPlayerSideUTurn_00412750(gob);
                else
                    idle = 1;
                break;
            case 9:
                if (!gInputControllers_004a0280[0].gxir_padButtons.buttonUp && !gInputControllers_004a0280[0].gxir_padButtons.buttonRight) {
                    if (!gInputControllers_004a0280[0].gxir_padButtons.buttonDown && !gInputControllers_004a0280[0].gxir_padButtons.buttonLeft)
                        idle = 1;
                    else
                        InitPlayerSideUTurn_00412750(gob);
                } else {
                    x += speed;
                    y -= speed;
                    switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x + 0x180000, y - 0x180000)) {
                    case 0xc0000000:
                        InitPlayerSideInside45Trans_00411b90(gob);
                        break;
                    case 0xc4000000:
                        gob->gob_xpos = x;
                        gob->gob_ypos = y;
                        moved = 1;
                        break;
                    case 0:
                        InitPlayerSideOutside45Trans_00411d70(gob);
                        break;
                    }
                }
                break;
            case 10:
                InitPlayerDuck_00427850(gob);
                break;
            case 11:
                if (!gInputControllers_004a0280[0].gxir_padButtons.buttonDown && !gInputControllers_004a0280[0].gxir_padButtons.buttonRight) {
                    if (!gInputControllers_004a0280[0].gxir_padButtons.buttonUp && !gInputControllers_004a0280[0].gxir_padButtons.buttonLeft)
                        idle = 1;
                    else
                        InitPlayerSideUTurn_00412750(gob);
                } else {
                    x += speed;
                    y += speed;
                    switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x + 0x180000, y + 0x180000)) {
                    case 0xc0000000:
                        InitPlayerSideInside45Trans_00411b90(gob);
                        break;
                    case 0xc8000000:
                        gob->gob_xpos = x;
                        gob->gob_ypos = y;
                        moved = 1;
                        break;
                    case 0:
                        InitPlayerSideOutside45Trans_00411d70(gob);
                        break;
                    }
                }
                break;
            case 12:
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonDown) {
                    y += speed;
                    by = y + 0x180000;
                    switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x, by)) {
                    case 0xc0000000:
                        tx = x + 0x10000;
                        block = GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, tx, by)[1];
                        if (block && (contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, block, tx & 0x1f0000)) != 0 && (by & 0x1f0000) >= contour - 0x10000) {
                            FUN_004120c0_SideInside90Trans(gob);
                            return;
                        }
                        by = y - 0x80000;
                        block = GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, tx, by)[1];
                        if (block && (contour = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, block, tx & 0x1f0000)) != 0 && (d = y - (by & 0xffe00000) - contour + 0x190000) > 0 && d < 0x100000) {
                            FUN_004120c0_SideInside90Trans(gob);
                            return;
                        }
                        gob->gob_xpos = x;
                        gob->gob_ypos = y;
                        moved = 1;
                        break;
                    case 0xc0008000:
                        FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                        break;
                    case 0xc2000000:
                        InitPlayerSideOutside45Trans_00411d70(gob);
                        break;
                    case 0xc8000000:
                        InitPlayerSideInside45Trans_00411b90(gob);
                        break;
                    case 0:
                        if ((d = FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x + 0x10000, by)) != 0xc0000000 && d != 0x80000000 && !GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, x, by)[1])
                            InitPlayerSideOutside90Trans_004123c0(gob);
                        break;
                    }
                } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonUp)
                    InitPlayerSideUTurn_00412750(gob);
                else
                    idle = 1;
                break;
            case 13:
                if (!gInputControllers_004a0280[0].gxir_padButtons.buttonDown && !gInputControllers_004a0280[0].gxir_padButtons.buttonLeft) {
                    if (!gInputControllers_004a0280[0].gxir_padButtons.buttonUp && !gInputControllers_004a0280[0].gxir_padButtons.buttonRight)
                        idle = 1;
                    else
                        InitPlayerSideUTurn_00412750(gob);
                } else {
                    x -= speed;
                    y += speed;
                    nx = x - 0x180000;
                    ny = y + 0x180000;
                    switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, nx, ny)) {
                    case 0xc0000000:
                        InitPlayerSideInside45Trans_00411b90(gob);
                        break;
                    case 0xc2000000:
                        gob->gob_xpos = x;
                        gob->gob_ypos = y;
                        moved = 1;
                        break;
                    case 0:
                        InitPlayerSideOutside45Trans_00411d70(gob);
                        break;
                    }
                }
                break;
            case 14:
                if (gInputControllers_004a0280[0].gxir_padButtons.buttonLeft) {
                    if (PTR_004a27f0 && DAT_004a2860 == 2) {
                        gPlayerPlatform_004a2864 = PTR_004a27f0;
                        FUN_004121b0_SideInside90Trans_Outer(gob, 1, 0);
                    } else {
                        x -= speed;
                        nx = x - 0x180000;
                        switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, nx, y)) {
                        case 0xc0000000:
                            if (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, nx, y + 0x10000) == 0xc0000000)
                                FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            else {
                                gob->gob_xpos = x;
                                gob->gob_ypos = y;
                                moved = 1;
                            }
                            break;
                        case 0xc0008000:
                            FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            break;
                        case 0xc2000000:
                            InitPlayerSideInside45Trans_00411b90(gob);
                            break;
                        case 0xc1000000:
                            InitPlayerSideOutside45Trans_00411d70(gob);
                            break;
                        case 0:
                            y += 0x10000;
                            if (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, nx, y) == 0xc0000000)
                                FUN_00411ff0_SideInside90Trans(gob, 1, 1);
                            else
                                InitPlayerSideOutside90Trans_004123c0(gob);
                            break;
                        }
                    }
                } else if (gInputControllers_004a0280[0].gxir_padButtons.buttonRight)
                    InitPlayerSideUTurn_00412750(gob);
                else
                    idle = 1;
                break;
            case 15:
                if (!gInputControllers_004a0280[0].gxir_padButtons.buttonUp && !gInputControllers_004a0280[0].gxir_padButtons.buttonLeft) {
                    if (!gInputControllers_004a0280[0].gxir_padButtons.buttonDown && !gInputControllers_004a0280[0].gxir_padButtons.buttonRight)
                        idle = 1;
                    else
                        InitPlayerSideUTurn_00412750(gob);
                } else {
                    x -= speed;
                    y -= speed;
                    switch (FUN_00420c40_CheckWallCollision(M1_CurrentLevel_004a2990, x - 0x180000, y - 0x180000)) {
                    case 0xc0000000:
                        InitPlayerSideInside45Trans_00411b90(gob);
                        break;
                    case 0xc1000000:
                        gob->gob_xpos = x;
                        gob->gob_ypos = y;
                        moved = 1;
                        break;
                    case 0:
                        InitPlayerSideOutside45Trans_00411d70(gob);
                        break;
                    }
                }
                break;
            }
            if (idle) {
                if (gob->gob_currentFrameGroup != 0x58) {
                    gob->gob_currentFrameGroup = 0x58;
                    gob->gob_currentFrameIndex = 0;
                    gob->gob_work0 = 0;
                }
                gob->gob_work0 += 0x4000;
                if (gob->gob_work0 > 0x10000) {
                    gob->gob_work0 -= 0x10000;
                    gob->gob_currentFrameIndex++;
                }
            } else if (moved) {
                if (gob->gob_currentFrameGroup != 0x49) {
                    gob->gob_currentFrameGroup = 0x49;
                    gob->gob_currentFrameIndex = 0;
                    gob->gob_work0 = 0;
                }
                gob->gob_work0 += 0x10000;
                if (gob->gob_work0 > 0x10000) {
                    gob->gob_work0 -= 0x10000;
                    gob->gob_currentFrameIndex += moved;
                    if (gob->gob_currentFrameIndex < 0) {
                        DAT_004a0218_pState = 0x6b;
                        gob->gob_currentFrameIndex = 7;
                    }
                    if (gob->gob_currentFrameIndex > 7)
                        DAT_004a0218_pState = 0x6b;
                }
            }
        } else
            InitPlayerSideTongueLash_00412960(gob);
    } else
        InitPlayerSideJump_004138b0(gob);
}
}
