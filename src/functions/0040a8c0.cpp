typedef struct LevelInfo {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char fileIndex;   /* 0x2 */
    unsigned char extraIndex;  /* 0x3 */
    int unk4;
} LevelInfo;
extern "C" {
extern int DAT_004a2a28_FileLoaded2;
extern void *PTR_gIDLDirectory_00455998;
extern int level_004a2964;
extern LevelInfo DAT_004577B0[];
extern int DAT_004a298c_FileLoaded;
extern char *gLevelDir_00455b7c;
extern char *gIDLDir_00455b78;
int __cdecl CDIO_OpenDirectory_00409350(void *idl, char *name, int index);
void __cdecl M1_OpenLevelDirs_0040a8c0(void)
{
    int index;
    if (!DAT_004a2a28_FileLoaded2) {
        CDIO_OpenDirectory_00409350(PTR_gIDLDirectory_00455998, gLevelDir_00455b7c, DAT_004577B0[level_004a2964].fileIndex);
        DAT_004a2a28_FileLoaded2 = 1;
    }
    if (!DAT_004a298c_FileLoaded) {
        index = DAT_004577B0[level_004a2964].extraIndex;
        if (index) {
            CDIO_OpenDirectory_00409350(PTR_gIDLDirectory_00455998, gIDLDir_00455b78, index);
            DAT_004a298c_FileLoaded = 1;
        }
    }
}
}
