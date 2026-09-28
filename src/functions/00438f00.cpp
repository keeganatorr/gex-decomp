extern "C" {
extern int DAT_00455c54_DebugVar;
extern char s_Object_Type_0045f088[];
extern char s_event_flamed_0045f1a8[];
void __cdecl TracePrintf_Debug_00405390(char *, ...);

typedef struct GXObject {
    char pad0[8];
    int type;
    char pad0c[0xd4];
    unsigned int flags2;
} GXObject;

int __cdecl GEX_Target(GXObject *gob)
{
    if ((unsigned char)(gob->flags2 >> 8) & 0x80) {
        if (DAT_00455c54_DebugVar > 1) {
            TracePrintf_Debug_00405390(s_Object_Type_0045f088, gob->type);
            TracePrintf_Debug_00405390(s_event_flamed_0045f1a8);
        }
        gob->flags2 &= ~0x8000;
        return 1;
    }
    return 0;
}
}
