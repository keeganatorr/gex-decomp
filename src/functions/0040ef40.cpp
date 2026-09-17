typedef struct GXObject GXObject;
typedef void (__cdecl *GXDoItFunc)(GXObject *);

struct GXObject {
    GXObject *next;                    /* 0x00 */
    unsigned char pad_04[0x5c - 0x04]; /* 0x04 */
    GXDoItFunc doit;                   /* 0x5c */
    unsigned char pad_60[0x6c - 0x60]; /* 0x60 */
    unsigned int flags;                /* 0x6c */
};

extern "C" {
void __cdecl FUN_0042CBF0(GXObject *obj);
void __cdecl FUN_0042CC00(void *list, GXObject *obj);
extern int DAT_004A27A4;
extern unsigned char DAT_004A27B0;
}

extern "C" void __cdecl GEX_Target(GXObject *p)
{
    while (p->next != 0) {
        if ((p->flags & 0x100000u) != 0) {
            GXObject *obj = p;
            p = p->next;
            FUN_0042CBF0(obj);
            FUN_0042CC00(&DAT_004A27B0, obj);
            --DAT_004A27A4;
        } else {
            if (p->doit != 0)
                (*p->doit)(p);
            p = p->next;
        }
    }
}
