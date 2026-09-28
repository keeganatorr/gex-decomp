extern "C" {
extern int DAT_00455c54_DebugVar;
extern char s_Object_Type_0045f088[];
extern char s_event_hitContour_0045f180[];
void __cdecl TracePrintf_Debug_00405390(char *, ...);

typedef struct GXObject {
    char pad0[8];
    int type;
    char pad0c[0xd4];
    unsigned int flags2;
} GXObject;

int __cdecl GEX_Target(GXObject *gob)
{
    if ((unsigned char)(gob->flags2 >> 8) & 8) {
        if (DAT_00455c54_DebugVar > 1) {
            TracePrintf_Debug_00405390(s_Object_Type_0045f088, gob->type);
            TracePrintf_Debug_00405390(s_event_hitContour_0045f180);
        }
        gob->flags2 &= ~0x800;
        return 1;
    }
    return 0;
}
}
