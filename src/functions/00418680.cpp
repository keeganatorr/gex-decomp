extern "C" {
extern int DAT_0049FB90;
extern void** DAT_004A27FC;

int __cdecl SCRIPT_TrackGXDiag_00418680(int param_1, void** param_2)
{
    int dx = (int)DAT_004A27FC[0x1e] - (int)param_2[0x1e];
    int dy = (int)DAT_004A27FC[0x1f] - (int)param_2[0x1f];
    int minus = dx - dy;
    int plus = dx + dy;

    if (dy > 0) {
        if (minus > -0x100000 && minus < 0x100000) {
            DAT_0049FB90 = 1;
            return param_1;
        }
        if (plus > -0x100000 && plus < 0x100000) {
            DAT_0049FB90 = -1;
            return param_1;
        }
        DAT_0049FB90 = 0;
        return param_1;
    }
    DAT_0049FB90 = 0;
    return param_1;
}
}
