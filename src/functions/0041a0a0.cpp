extern "C" int __cdecl FUN_0040F1D0(int, void*);
extern "C" void __cdecl FUN_00405390(const char*, int, int);
extern "C" int FUN_004A2990;
extern "C" int DAT_00455c54;
extern "C" void* DAT_004a27fc;
extern "C" const char DAT_00458f48[];
extern "C" int DAT_00458edc;

struct GXObject {
    char pad0[0x7c];
    int ypos;
    char pad1[0xdc - 0x80];
    int oldContourDist;
    char pad2[0x110 - 0xe0];
    int platform;
    int platHitType;
};

extern "C" int __cdecl GEX_Target(GXObject* param1, int param2)
{
    param1->ypos += param2;
    int dist = FUN_0040F1D0(FUN_004A2990, param1);
    param1->ypos -= param2;
    if (DAT_00455c54 > 2 && param1 == DAT_004a27fc) {
        FUN_00405390(DAT_00458f48, dist >> 0x10, param1->oldContourDist >> 0x10);
    }
    if (dist <= 0x18000) {
        if (dist < DAT_00458edc) {
            param1->oldContourDist = dist;
            if (param1->platform != 0 && param1->platHitType == 0)
                return 1;
            return 0;
        }
        if (param1->oldContourDist >= -0x20000 || param1->oldContourDist < -0x7e000000) {
            param1->oldContourDist = 0;
            param1->ypos += dist;
            return 1;
        }
    }
    param1->oldContourDist = dist;
    if (param1->platform != 0 && param1->platHitType == 0)
        return 1;
    return 0;
}
