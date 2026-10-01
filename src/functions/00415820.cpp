// Tube travel reconstructed from pinned 00415820..00415ae9 instructions.
// Corrects the archived candidate's coordinate-as-pointer accesses, table
// loads and junction probe distances. Behavioral candidate, not a byte proof.
extern "C" {
extern int DAT_00455BB4, DAT_00455BB8, DAT_00455BBC, DAT_00455BC0;
extern int DAT_00455BC4, DAT_00455BC8, DAT_00455BCC, DAT_00455BD0;
extern int DAT_00458910[20];
extern unsigned char DAT_004A0280, DAT_004A0281, DAT_004A0282, DAT_004A0283;
extern int DAT_004A2990, DAT_004A2AC8;
unsigned int __cdecl FUN_0040F170(int, unsigned int, unsigned int);
void __cdecl FUN_0041A250(int *, int, int, int);
void __cdecl FUN_0041A340(int *, int);
void __cdecl FUN_0041FA80(int);
}

extern "C" void __cdecl PlayerGoThruTube_00415820(int *object)
{
    DAT_00455BB4 = DAT_00455BCC = DAT_00455BC4 = 0x9f0000;
    DAT_00455BB8 = DAT_00455BD0 = DAT_00455BC8 = 0xa10000;
    DAT_00455BBC = 0x770000;
    DAT_00455BC0 = 0x790000;
    FUN_0041FA80(0x49);

    int direction, exiting = 0;
    if (!object[0x26]) {
        object[0x26] = 1;
        direction = object[0x27];
    } else {
        unsigned int tile = FUN_0040F170(DAT_004A2990, object[0x1e], object[0x1f]);
        switch (tile) {
        case 0x58: case 0x59: case 0x5a: case 0x5b:
            direction = tile - 0x58;
            break;
        case 0x5c: case 0x5d: case 0x5e: case 0x5f:
            direction = tile - 0x5c;
            if (DAT_004A0280 && object[0x27] != 1) {
                if (FUN_0040F170(DAT_004A2990, object[0x1e] - 0x200000, object[0x1f]) == 0x58)
                    direction = 0;
            } else if (DAT_004A0281 && object[0x27] != 0) {
                if (FUN_0040F170(DAT_004A2990, object[0x1e] + 0x200000, object[0x1f]) == 0x59)
                    direction = 1;
            } else if (DAT_004A0282 && object[0x27] != 3) {
                if (FUN_0040F170(DAT_004A2990, object[0x1e], object[0x1f] - 0x200000) == 0x5a)
                    direction = 2;
            } else if (DAT_004A0283 && object[0x27] != 2) {
                if (FUN_0040F170(DAT_004A2990, object[0x1e], object[0x1f] + 0x200000) == 0x5b)
                    direction = 3;
            }
            break;
        case 0x60:
            direction = object[0x27];
            break;
        case 0x74: case 0x75: case 0x76: case 0x77:
            direction = tile - 0x74;
            break;
        default:
            FUN_0041A250(object, 0xed, 0x80, 0x60);
            direction = object[0x27];
            exiting = 1;
            object[0x20] = DAT_00458910[direction * 5];
            object[0x23] = DAT_00458910[direction * 5 + 1];
            object[0x22] = 0;
            object[0x1d] = 0x10;
            break;
        }
    }
    if (!(DAT_004A2AC8 & 7)) FUN_0041A340(object, 0xee);

    int previous = object[0x27];
    if (direction != previous) {
        int x = object[0x1e] & 0x1f0000;
        int y = object[0x1f] & 0x1f0000;
        if (x < 0xc0000 || x > 0x140000 || y < 0xc0000 || y > 0x140000)
            direction = previous;
    }
    int *row = DAT_00458910 + direction * 5;
    object[0x1e] += row[0];
    object[0x1f] += row[1];
    object[0x32] = row[2];
    object[0x33] = row[3];
    object[0x31] = row[4];
    if (direction == previous) ++object[0x15];
    else object[0x15] = -1;
    object[0x27] = direction;
    if (exiting) object[0x31] = 0;
}
