typedef struct Event {
    int eventNumber;
    void *eventToCall;
} Event;
typedef struct GXObject {
    char pad0[0x30];
    void *script;               /* 0x30 */
    char pad34[0x1c];
    int anim;                   /* 0x50 */
    int frame;                  /* 0x54 */
    char pad58[0x14];
    unsigned int flags;         /* 0x6c */
    char pad70[8];
    int xpos;                   /* 0x78 */
    int ypos;                   /* 0x7c */
    char pad80[0x1c];
    int message;                /* 0x9c */
    int zoom;                   /* 0xa0 */
    char pada4[4];
    int messageData;            /* 0xa8 */
    char padac[0xc];
    int fb8;                    /* 0xb8 */
    char padbc[0x18];
    int oldX;                   /* 0xd4 */
    int oldY;                   /* 0xd8 */
    char paddc[4];
    unsigned int flags2;        /* 0xe0 */
    int fe4;
    int fe8;
    int fec;
    int ff0;
    int oldAnim;                /* 0xf4 */
    int oldFrame;               /* 0xf8 */
    unsigned int oldFlags;      /* 0xfc */
    char pad100[0x10];
    int f110;                   /* 0x110 */
    int f114;                   /* 0x114 */
    char pad118[0x7c];
    Event events[12];           /* 0x194 */
} GXObject;
typedef struct BUTTON_RECORD {
    unsigned char buttonLeft, buttonRight, buttonUp, buttonDown;
    unsigned char buttonA, buttonB, buttonC, buttonX, buttonL, buttonR, buttonStart;
    unsigned char unkB[4];
} BUTTON_RECORD;
typedef struct GXInputRecord {
    BUTTON_RECORD gxir_padButtons;
    BUTTON_RECORD gxir_padJustOnButtons;
    unsigned char _pad1e[2];
    int gxir_dValue;
} GXInputRecord;
typedef int (__cdecl *EventHandler)(GXObject *);
extern "C" {
extern int DAT_0045b138;
extern int DAT_0045b134;
extern int DAT_0045b12c;
extern GXInputRecord gInputControllers_004a0280[];
extern int gInputBits_004a02c8;
extern unsigned char *PTR_0049fb98;
extern int DAT_00463e08;
extern int DAT_0045b118;
extern int DAT_0045b11c;
extern int DAT_0045b114_zoomstate;
extern int DAT_004a2b00;
extern int DAT_00458c84;
extern char DAT_0045b0a0;
extern char DAT_0045b0a4;
extern int gGameState_00455c3c;
extern int gMainState_004a2970;
extern int M1_IsInMap_004a2a7c;
extern GXObject *gPlayerObject_004a27fc;
extern unsigned char *DAT_00463e10;
extern unsigned char *DAT_00463d78;
extern int DAT_0045b120;
extern int DAT_0045b124;
extern int DAT_00458c7c;
extern int DAT_00458c80;
extern void *PTR_00463d7c;
extern int DAT_0045b128;
extern char DAT_00463e98[];
extern EventHandler DAT_0045f00c[];
void __cdecl VSIT_PlayVoiceSituation_0041f8c0(int);
void __cdecl VFX_Play_0041fa80(int);
void __cdecl GOB_ProcessXPositionChange_00439090(GXObject *);
void __cdecl GOB_ProcessYPositionChange_004390d0(GXObject *);
void __cdecl GFX_Fade_0043f490(int, int, int, int, int, int, int);
void __cdecl VSIT_ForceVoiceSituation_0041fb80(int);
void __cdecl VSIT_UnforceVoiceSituation_0041fbc0(void);
int __cdecl FUN_00430060_MovePos(unsigned char **cursor);
void __cdecl RezOutObject_00437310(GXObject *);
int __cdecl FUN_0042e8b0_Call_Event_call(GXObject *, int);
void *__cdecl SCRIPT_DoEvent_00433590(GXObject *obj, void *script, void *eventToCall, int eventNumber);
void __cdecl FUN_0042f720(GXObject *);
void __cdecl FUN_0042f800(GXObject *, int, int);
void __cdecl FUN_0042f860(GXObject *);
void __cdecl GOB_SetObjectDisplayPriority_00419b80(GXObject *, int);
void __cdecl GEX_Target(GXObject *gob)
{
    int op;
    int n;
    int dy;
    Event *event;
    int i;

    DAT_0045b138++;
    if (DAT_0045b138 % 60 == 0)
        VSIT_PlayVoiceSituation_0041f8c0(0x44);
    if (DAT_0045b138 % 240 == 0)
        VFX_Play_0041fa80(0x44);
    if (DAT_0045b134 > 0) {
        DAT_0045b134--;
        return;
    }
    gob->oldX = gob->xpos;
    gob->oldY = gob->ypos;
    gob->oldFlags = gob->flags;
    gob->oldAnim = gob->anim;
    gob->oldFrame = gob->frame;
    gob->fe4 = 0;
    gob->fe8 = 0;
    gob->fec = 0;
    gob->ff0 = 0;
    gob->flags2 = (gob->flags2 * 2 ^ gob->flags2) & 0x200 ^ gob->flags2;
    gob->flags2 &= ~0x100;
    if (DAT_0045b12c) {
        gInputControllers_004a0280[0].gxir_padButtons.buttonLeft = 0;
        gInputControllers_004a0280[0].gxir_padButtons.buttonRight = 0;
        gInputControllers_004a0280[0].gxir_padButtons.buttonUp = 0;
        gInputControllers_004a0280[0].gxir_padButtons.buttonDown = 0;
        gInputControllers_004a0280[0].gxir_padButtons.buttonA = 0;
        gInputControllers_004a0280[0].gxir_padButtons.buttonB = 0;
        gInputControllers_004a0280[0].gxir_padButtons.buttonC = 0;
        gInputControllers_004a0280[0].gxir_padButtons.buttonX = 0;
        gInputControllers_004a0280[0].gxir_padButtons.buttonL = 0;
        gInputControllers_004a0280[0].gxir_padButtons.buttonR = 0;
        gInputControllers_004a0280[0].gxir_padButtons.buttonStart = 0;
        gInputControllers_004a0280[0].gxir_padButtons.unkB[0] = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonLeft = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonRight = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonUp = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonDown = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonA = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonB = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonC = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonX = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonL = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonR = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.buttonStart = 0;
        gInputControllers_004a0280[0].gxir_padJustOnButtons.unkB[0] = 0;
        gInputBits_004a02c8 = 0;
    }
    op = *PTR_0049fb98++;
    DAT_00463e08 = gob->zoom;
    gob->flags &= 0xe0ffffff;
    GOB_ProcessXPositionChange_00439090(gob);
    GOB_ProcessYPositionChange_004390d0(gob);
    while (op > 100) {
        switch (op) {
        case 0x65:
            DAT_0045b118 = 0x10000;
            DAT_0045b11c = 0x10000;
            DAT_0045b114_zoomstate = 0x65;
            break;
        case 0x66:
            DAT_0045b118 = 0x10000;
            DAT_0045b11c = 0x10000;
            DAT_0045b114_zoomstate = 0x66;
            break;
        case 0x67:
            DAT_0045b118 = 0x10000;
            DAT_0045b11c = 0x10000;
            DAT_0045b114_zoomstate = 0x67;
            break;
        case 0x68:
            DAT_0045b118 = 0x10000;
            DAT_0045b11c = 0x20000;
            DAT_0045b114_zoomstate = 0x68;
            break;
        case 0x69:
            DAT_0045b118 = 0x20000;
            DAT_0045b11c = 0x20000;
            DAT_0045b114_zoomstate = 0x69;
            break;
        case 0x6a:
            DAT_0045b118 = 0x20000;
            DAT_0045b11c = 0x20000;
            DAT_0045b114_zoomstate = 0x6a;
            break;
        case 0x97:
            if (!DAT_004a2b00)
                GFX_Fade_0043f490(1, 0, 0, 0, 0, 0, 0);
            break;
        case 0x98:
            if (!DAT_004a2b00)
                GFX_Fade_0043f490(0x3c, 0, 0xff, 0, 0xff, 0, 0xff);
            break;
        case 0x99:
            VSIT_ForceVoiceSituation_0041fb80(0x5a);
            DAT_00458c84 = 1;
            break;
        case 0x9a:
            DAT_0045b0a0 = 1;
            break;
        case 0x9b:
            PTR_0049fb98 += FUN_00430060_MovePos(&PTR_0049fb98) - 2;
            break;
        case 0x9c:
            gGameState_00455c3c = -1;
            gMainState_004a2970 = 5;
            M1_IsInMap_004a2a7c = 1;
            break;
        case 0x9d:
            DAT_0045b12c = 1;
            break;
        case 0x9e:
            VFX_Play_0041fa80(0x5a);
            VSIT_UnforceVoiceSituation_0041fbc0();
            DAT_0045b12c = 0;
            break;
        case 0x9f:
            n = FUN_00430060_MovePos(&PTR_0049fb98) << 16;
            dy = FUN_00430060_MovePos(&PTR_0049fb98) << 16;
            gPlayerObject_004a27fc->xpos += n;
            gPlayerObject_004a27fc->ypos += dy;
            break;
        case 0xa0:
            DAT_0045b0a4 = 1;
            break;
        case 0xa1:
            RezOutObject_00437310(gPlayerObject_004a27fc);
            break;
        case 0xa2:
            DAT_0045b134 = *PTR_0049fb98++;
            if (gob->f114 == -1)
                gob->f110 = 0;
            gob->f114 = -1;
            return;
        case 0xa3:
            gob->fb8 = 100000;
            break;
        case 0xc9:
            n = FUN_00430060_MovePos(&PTR_0049fb98);
            if ((gPlayerObject_004a27fc->ypos > 0x1a00000 || gPlayerObject_004a27fc->xpos < 0x1600000) && gPlayerObject_004a27fc->xpos < 0x3840000)
                PTR_0049fb98 += n - 2;
            break;
        case 0xca:
            n = FUN_00430060_MovePos(&PTR_0049fb98);
            if (gPlayerObject_004a27fc->xpos > 0x4b00000)
                PTR_0049fb98 += n - 2;
            break;
        case 0xcb:
            DAT_00463e10 = PTR_0049fb98;
            DAT_00463e10 += FUN_00430060_MovePos(&PTR_0049fb98);
            break;
        case 0xcc:
            DAT_00463d78 = PTR_0049fb98;
            DAT_00463d78 += FUN_00430060_MovePos(&PTR_0049fb98);
            break;
        case 0xff:
            gob->fb8 = 0;
            PTR_0049fb98 = DAT_00463e10;
            break;
        }
        op = *PTR_0049fb98++;
    }
    if (!FUN_0042e8b0_Call_Event_call(gob, op))
        PTR_0049fb98--;
    if (gob->script)
        gob->script = SCRIPT_DoEvent_00433590(gob, &gob->script, gob->script, -1);
    if (DAT_0045b120) {
        if (++DAT_00458c7c > 500) {
            DAT_00458c7c = 0;
            DAT_0045b120 = 0;
        }
    } else if (DAT_0045b124) {
        if (++DAT_00458c80 > 500) {
            DAT_00458c80 = 0;
            DAT_0045b124 = 0;
        }
    }
    switch (gob->message) {
    case 1:
        FUN_0042f720(gob);
        break;
    case 2:
        FUN_0042f800(gob, gob->messageData, 0xc80000);
        break;
    case 3:
        FUN_0042f860(gob);
        break;
    case 4:
        PTR_00463d7c = 0;
        break;
    case 5:
        DAT_00458c7c = 0;
        DAT_0045b120 = 1;
        break;
    case 6:
        DAT_00458c80 = 0;
        DAT_0045b124 = 1;
        break;
    case 7:
        DAT_0045b114_zoomstate = gob->messageData;
        break;
    case 8:
        DAT_0045b118 = gob->messageData;
        break;
    case 9:
        DAT_0045b11c = gob->messageData;
        break;
    case 10:
        DAT_0045b128 = 1;
        break;
    case 11:
        DAT_0045b128 = 0;
        break;
    }
    if (gob->message)
        gob->message = 0;
    event = gob->events;
    for (i = 0; i < 12; i++) {
        n = event->eventNumber;
        if (n && DAT_0045f00c[n](gob))
            SCRIPT_DoEvent_00433590(gob, DAT_00463e98, event->eventToCall, n);
        event++;
    }
    if (DAT_00463e08 <= 0x8000 && gob->zoom > 0x8000 || DAT_00463e08 > 0x10000 && gob->zoom <= 0x10000)
        GOB_SetObjectDisplayPriority_00419b80(gob, 2);
    else if (DAT_00463e08 > 0 && gob->zoom == 0)
        GOB_SetObjectDisplayPriority_00419b80(gob, 3);
    if (gob->f114 == -1)
        gob->f110 = 0;
    gob->f114 = -1;
}
}
