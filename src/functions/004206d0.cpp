typedef struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;     /* 0x6c */
    int gob_state;              /* 0x70 */
    unsigned char _pad74[0xc4 - 0x74];
    int gob_angle;              /* 0xc4 */
} GXObject;
extern "C" {
extern GXObject *gPlayerObject_004a27fc;
extern unsigned int DAT_00457210[];
extern int DAT_0045a6e8[];
int __cdecl GEX_Target(void)
{
    int dir;
    dir = 6;
    if (gPlayerObject_004a27fc) {
        switch (DAT_00457210[gPlayerObject_004a27fc->gob_state] >> 28) {
        case 0:
        case 1:
        case 4:
            return gPlayerObject_004a27fc->gob_flags & 0x80000000 ? 10 : 6;
        case 2:
            return (gPlayerObject_004a27fc->gob_flags & 0x80000000 ? 8 : 0) | gPlayerObject_004a27fc->gob_angle >> 21;
        case 3:
        case 5:
            dir = DAT_0045a6e8[gPlayerObject_004a27fc->gob_angle >> 22];
            break;
        }
    }
    return dir;
}
}
