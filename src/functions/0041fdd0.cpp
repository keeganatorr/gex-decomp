// Field names from Ghidra's GXObject layout (evidence, not proof).
typedef struct GXObject {
    unsigned char _pad0[0x98];
    int gob_work0;   /* 0x98: parallax index */
    int gob_work1;   /* 0x9c: display priority */
    void *gob_work2; /* 0xa0: loaded parallax */
    void *gob_work3; /* 0xa4: its file */
} GXObject;
typedef struct ParaInfo { void *file; void *para; int index; } ParaInfo;
extern "C" {
extern ParaInfo ParaInfo_fake_ARRAY_00463a40[8];
extern char s_ERROR_To_many_parallaxs_in_one_l_0045a1ac[];
void __cdecl GOB_SetObjectDisplayPriority_00419b80(GXObject *gob, unsigned int priority);
void __cdecl assertfail_00405350(const char *format, ...);
void *__cdecl PAR_LoadParallaxs_00420210(int index, void **file);
void __cdecl GEX_Target(GXObject *gob, int loaded)
{
    int i;
    int freeSlot;
    if (!loaded) {
        GOB_SetObjectDisplayPriority_00419b80(gob, gob->gob_work1);
        for (i = 0; i < 8; i++) {
            if (ParaInfo_fake_ARRAY_00463a40[i].file && ParaInfo_fake_ARRAY_00463a40[i].index == gob->gob_work0) {
                gob->gob_work2 = ParaInfo_fake_ARRAY_00463a40[i].para;
                break;
            }
            if (!ParaInfo_fake_ARRAY_00463a40[i].file)
                freeSlot = i;
        }
        if (i >= 8) {
            if (freeSlot >= 8) {
                assertfail_00405350(s_ERROR_To_many_parallaxs_in_one_l_0045a1ac);
                return;
            }
            gob->gob_work2 = PAR_LoadParallaxs_00420210(gob->gob_work0, &gob->gob_work3);
            ParaInfo_fake_ARRAY_00463a40[freeSlot].file = gob->gob_work3;
            ParaInfo_fake_ARRAY_00463a40[freeSlot].para = gob->gob_work2;
            ParaInfo_fake_ARRAY_00463a40[freeSlot].index = gob->gob_work0;
        }
    }
}
}
