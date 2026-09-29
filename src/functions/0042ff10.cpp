typedef struct Block32 { int words[8]; } Block32;
typedef struct Slot32 { int value; int rest[7]; } Slot32;
typedef struct LoadData { unsigned char _pad0[4]; int **table; } LoadData;
typedef struct GXObject {
    unsigned char _pad0[0xc];
    LoadData *gob_objectLoadData;   /* 0x0c */
    Block32 gob_block;              /* 0x10 */
    unsigned char _pad30[0x6c - 0x30];
    unsigned int gob_flags;         /* 0x6c */
    unsigned char _pad70[0x98 - 0x70];
    int gob_work0;                  /* 0x98 */
    unsigned char _pad9c[0xe0 - 0x9c];
    unsigned int gob_flags2;        /* 0xe0 */
} GXObject;
extern "C" {
extern GXObject *gPlayerObject_004a27fc;
extern GXObject *PTR_00463d80;
extern int PTR_00463d7c;
extern Slot32 DAT_0049fc60[];
extern Block32 DAT_0049fba0;
extern int DAT_004a2a04;
extern int DAT_0045b124;
extern int DAT_0045b120;
extern int DAT_00458c84;
extern int DAT_00458c80;
extern int DAT_00458c7c;
extern int DAT_00463e10;
extern int DAT_00463d78;
extern char DAT_0045b0a0;
extern char DAT_0045b0ac;
extern char DAT_0045b0a4;
extern char DAT_0045b0a8;
extern int DAT_0045b12c;
extern int DAT_0045b114_zoomstate;
extern volatile int DAT_0045b098;
extern int DAT_0045b09c;
extern volatile int DAT_004a2948;
extern int DAT_0045b118;
extern int DAT_0045b11c;
extern int DAT_00463eb8;
extern int DAT_004a2b00;
void __cdecl GFX_Fade_0043f490(int mode, int from, int to, int a, int b, int c, int d);
void __cdecl ob229Init_0042ff10(GXObject *gob, int flag)
{
    LoadData *data;
    int i;
    int value;
    if (gob->gob_work0 == 0x40) {
        if (flag) {
            PTR_00463d7c = 0;
            return;
        }
        data = gob->gob_objectLoadData;
        if (data->table && *data->table) {
            for (i = 0; i < 40; i++) {
                value = (*data->table)[i];
                if (value)
                    DAT_0049fc60[i].value = value;
            }
        }
        gPlayerObject_004a27fc->gob_flags2 |= 0x40;
        gob->gob_flags2 |= 0x40;
        DAT_004a2a04 = 0;
        gob->gob_block = DAT_0049fba0;
        gob->gob_flags |= 0x80000000;
        PTR_00463d80 = gob;
        DAT_0045b124 = 0;
        DAT_0045b120 = 0;
        DAT_00458c84 = 0;
        DAT_00458c80 = 0;
        DAT_00458c7c = 0;
        DAT_00463e10 = 0;
        DAT_00463d78 = 0;
        PTR_00463d7c = 0;
        DAT_0045b0a0 = 1;
        DAT_0045b0ac = 1;
        DAT_0045b0a4 = 0;
        DAT_0045b0a8 = 0;
        DAT_0045b12c = 0;
        DAT_0045b114_zoomstate = 0;
        DAT_0045b098 = -1;
        DAT_0045b09c = 0;
        DAT_004a2948 = 1;
        DAT_0045b118 = 0x10000;
        DAT_0045b11c = 0x20000;
        DAT_00463eb8 = 6;
        if (!DAT_004a2b00)
            GFX_Fade_0043f490(1, 0, 0, 0, 0, 0, 0);
    }
}
}
