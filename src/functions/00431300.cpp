typedef struct GXObject GXObject;
extern "C" {
extern int DAT_0045b114_zoomstate;
extern GXObject *DAT_0045b09c;
extern GXObject *PTR_00463d80;
extern GXObject *PTR_00463d7c;
extern GXObject *gPlayerObject_004a27fc;
void __cdecl FUN_0042eaf0_GRAPHICSDRAWING(GXObject *first, GXObject *second, GXObject *third);
void __cdecl GEX_Target(void)
{
    switch (DAT_0045b114_zoomstate) {
    case 0x65:
        FUN_0042eaf0_GRAPHICSDRAWING(gPlayerObject_004a27fc, 0, 0);
        return;
    case 0x66:
        FUN_0042eaf0_GRAPHICSDRAWING(PTR_00463d80, 0, 0);
        return;
    case 0x67:
        if (DAT_0045b09c) {
            FUN_0042eaf0_GRAPHICSDRAWING(DAT_0045b09c, 0, 0);
            return;
        }
        break;
    case 0x68:
        FUN_0042eaf0_GRAPHICSDRAWING(gPlayerObject_004a27fc, PTR_00463d80, PTR_00463d7c);
        return;
    case 0x69:
        FUN_0042eaf0_GRAPHICSDRAWING(gPlayerObject_004a27fc, 0, 0);
        return;
    case 0x6a:
        FUN_0042eaf0_GRAPHICSDRAWING(gPlayerObject_004a27fc, 0, 0);
        break;
    default:
        FUN_0042eaf0_GRAPHICSDRAWING(gPlayerObject_004a27fc, PTR_00463d80, PTR_00463d7c);
        return;
    }
}
}
