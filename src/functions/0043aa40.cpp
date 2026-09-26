typedef struct CLDEdges {
    int points[6];
    int left;
    int right;
    int top;
    int bottom;
} CLDEdges;
typedef struct GXObject GXObject;
struct GXObject {
    unsigned char _pad0[0x78];
    int gob_xpos;               /* 0x78 */
    int gob_ypos;               /* 0x7c */
    unsigned char _pad80[0x98 - 0x80];
    GXObject *gob_work0;        /* 0x98 */
    GXObject *gob_work1;        /* 0x9c */
};
extern "C" {
extern int CAMERA_XPos_004a2a38;
extern int CAMERA_YPos_004a2a1c;
void *__cdecl memset(void *, int, unsigned int);
int __cdecl CLD_ComputeAngleEdges_0041cb80(GXObject *gob, CLDEdges *edges);
void __cdecl GOB_DisplayCelToQuad_00443ae0(GXObject *gob, int cel, int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);
void __cdecl GEX_Target(GXObject *gob)
{
    CLDEdges a;
    CLDEdges b;
    GXObject *objA;
    GXObject *objB;
    int dx;
    int dy;
    int ya;
    int yb;
    dx = gob->gob_xpos - CAMERA_XPos_004a2a38 - 0xa00000;
    dy = gob->gob_ypos - CAMERA_YPos_004a2a1c - 0x780000;
    objA = gob->gob_work0;
    objB = gob->gob_work1;
    if (objA)
        CLD_ComputeAngleEdges_0041cb80(objA, &a);
    else
        memset(&a, 0, sizeof a);
    if (objB)
        CLD_ComputeAngleEdges_0041cb80(objB, &b);
    else
        memset(&b, 0, sizeof b);
    if (dy > 0) {
        yb = b.top - CAMERA_YPos_004a2a1c;
        ya = a.top - CAMERA_YPos_004a2a1c;
    } else {
        yb = b.bottom - CAMERA_YPos_004a2a1c;
        ya = a.bottom - CAMERA_YPos_004a2a1c;
    }
    GOB_DisplayCelToQuad_00443ae0(gob, 0, a.left - CAMERA_XPos_004a2a38, ya, a.right - CAMERA_XPos_004a2a38, ya, b.right - CAMERA_XPos_004a2a38, yb, b.left - CAMERA_XPos_004a2a38, yb);
    if (dx > 0)
        GOB_DisplayCelToQuad_00443ae0(gob, 1, a.left - CAMERA_XPos_004a2a38, a.top - CAMERA_YPos_004a2a1c, b.left - CAMERA_XPos_004a2a38, b.top - CAMERA_YPos_004a2a1c, b.left - CAMERA_XPos_004a2a38, b.bottom - CAMERA_YPos_004a2a1c, a.left - CAMERA_XPos_004a2a38, a.bottom - CAMERA_YPos_004a2a1c);
    else
        GOB_DisplayCelToQuad_00443ae0(gob, 1, a.right - CAMERA_XPos_004a2a38, a.top - CAMERA_YPos_004a2a1c, b.right - CAMERA_XPos_004a2a38, b.top - CAMERA_YPos_004a2a1c, b.right - CAMERA_XPos_004a2a38, b.bottom - CAMERA_YPos_004a2a1c, a.right - CAMERA_XPos_004a2a38, a.bottom - CAMERA_YPos_004a2a1c);
}
}
