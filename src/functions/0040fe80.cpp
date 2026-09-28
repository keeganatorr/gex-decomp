typedef struct GXObject {
    char pad0[0x78];
    int xpos;
    int ypos;
    char pad80[0x18];
    int work0;
    char pad9c[0xc];
    int work4;
    int work5;
    int work6;
    int work7;
} GXObject;

extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
extern int DAT_004A29FC;
extern int DAT_004a297c_CamY1;
extern int DAT_004a2a30_CameraXResult;
extern int DAT_004a2a34_CameraYResult;

void __cdecl GEX_Target(GXObject *g, int unused, int snap)
{
    int x;
    int y;
    int dx;
    int dy;
    int dxo;
    int dyo;
    x = g->xpos;
    y = g->ypos;
    dx = x - CAMERA_XPos_004a2a38;
    dy = y - CAMERA_YPos_004a2a1c;
    dxo = x - DAT_004A29FC;
    dyo = y - DAT_004a297c_CamY1;
    switch (g->work0) {
    case 0:
        if (dy < 0 || dy >= 0xf00000)
            break;
        if (dy >= 0x140000 && dy <= 0xdc0000) {
            if (dx < 0)
                break;
            if (snap ? dx < 0x1400000 : (dxo <= 0 && DAT_004a2a30_CameraXResult < 0)) {
                dx = dxo;
                CAMERA_XPos_004a2a38 = x;
            }
        } else {
            if (dx < 0)
                break;
            if (snap ? dx < 0x1400000 : (dx < 0x140000 && DAT_004a2a30_CameraXResult < 0)) {
                dx = dxo;
                CAMERA_XPos_004a2a38 = x;
            }
        }
        break;
    case 1:
        if (dy < 0 || dy >= 0xf00000)
            break;
        if (dy >= 0x140000 && dy <= 0xdc0000) {
            if (dx > 0x1400000)
                break;
            if (snap ? dx >= 0 : (dxo >= 0x1400000 && DAT_004a2a30_CameraXResult > 0)) {
                CAMERA_XPos_004a2a38 = x - 0x1400000;
                dx = dxo;
            }
        } else {
            if (dx > 0x1400000)
                break;
            if (snap ? dx >= 0 : (dx > 0x12c0000 && DAT_004a2a30_CameraXResult > 0)) {
                CAMERA_XPos_004a2a38 = x - 0x1400000;
                dx = dxo;
            }
        }
        break;
    case 2:
        if (dx < 0 || dx >= 0x1400000)
            break;
        if (dx >= 0x140000 && dx <= 0x12c0000) {
            if (dy < 0)
                break;
            if (snap ? dy < 0xf00000 : (dyo <= 0 && DAT_004a2a34_CameraYResult < 0)) {
                CAMERA_YPos_004a2a1c = y;
                dy = dyo;
            }
        } else {
            if (dy < 0)
                break;
            if (snap ? dy < 0xf00000 : (dy < 0x140000 && DAT_004a2a34_CameraYResult < 0)) {
                CAMERA_YPos_004a2a1c = y;
                dy = dyo;
            }
        }
        break;
    case 3:
        if (dx < 0 || dx >= 0x1400000)
            break;
        if (dx >= 0x140000 && dx <= 0x12c0000) {
            if (dy > 0xf00000)
                break;
            if (snap ? dy >= 0 : (dyo >= 0xf00000 && DAT_004a2a34_CameraYResult > 0)) {
                CAMERA_YPos_004a2a1c = y - 0xf00000;
                dy = dyo;
            }
        } else {
            if (dy > 0xf00000)
                break;
            if (snap ? dy >= 0 : (dy > 0xdc0000 && DAT_004a2a34_CameraYResult > 0)) {
                CAMERA_YPos_004a2a1c = y - 0xf00000;
                dy = dyo;
            }
        }
        break;
    }
    g->work4 = dx;
    g->work5 = dy;
    g->work6 = CAMERA_XPos_004a2a38;
    g->work7 = CAMERA_YPos_004a2a1c;
}
}
