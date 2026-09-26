// Field names from Ghidra's GXObject/GXHitArea layouts (evidence, not proof).
typedef struct GXHitArea { int gxha_left; int gxha_top; int gxha_right; int gxha_bottom; } GXHitArea;
typedef struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;  /* 0x6c */
    unsigned char _pad70[8];
    int gob_xpos;            /* 0x78 */
    int gob_ypos;            /* 0x7c */
    unsigned char _pad80[0x48];
    int gob_xScale;          /* 0xc8 */
    int gob_yScale;          /* 0xcc */
} GXObject;
typedef struct AnglePoint { int x; int y; } AnglePoint;
typedef struct AnglePoints { int unk0; AnglePoint points[4]; } AnglePoints;
extern "C" {
void __cdecl CLD_ApplyAngleToPoints_0041cc70(AnglePoints *points, int x, int y, int a, int b, unsigned int angle, int xScale, int yScale);
void __cdecl GEX_Target(GXObject *gob, GXHitArea *area, int a, int b, unsigned int angle, AnglePoints *points)
{
    if (gob->gob_flags & 0x80000000) {
        points->points[0].x = -area->gxha_right;
        points->points[1].x = -area->gxha_left;
        points->points[2].x = -area->gxha_left;
        points->points[3].x = -area->gxha_right;
    } else {
        points->points[0].x = area->gxha_left;
        points->points[1].x = area->gxha_right;
        points->points[2].x = area->gxha_right;
        points->points[3].x = area->gxha_left;
    }
    if (gob->gob_flags & 0x40000000) {
        points->points[0].y = -area->gxha_bottom;
        points->points[1].y = -area->gxha_bottom;
        points->points[2].y = -area->gxha_top;
        points->points[3].y = -area->gxha_top;
    } else {
        points->points[0].y = area->gxha_top;
        points->points[1].y = area->gxha_top;
        points->points[2].y = area->gxha_bottom;
        points->points[3].y = area->gxha_bottom;
    }
    CLD_ApplyAngleToPoints_0041cc70(points, gob->gob_xpos, gob->gob_ypos, a, b, angle, gob->gob_xScale, gob->gob_yScale);
}
}
