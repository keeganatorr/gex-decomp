typedef struct GexLevFileStruct {
    int size;     /* 0x0 */
    void *data;   /* 0x4 */
    int handle;   /* 0x8: 2 means the IDL memory image */
} GexLevFileStruct;
typedef struct IDL_File { int count; int entries[1]; } IDL_File;
extern "C" {
void *__cdecl memset(void *dst, int value, unsigned int count);
__declspec(dllimport) int __cdecl wsprintfA(char *buffer, const char *format, ...);
extern IDL_File *gIDL_0047f000;
extern char s_LEV_GEX_3d_LEV_004559e4[];
int __cdecl CDIO_FileOpen_00409170(const char *name);
int __cdecl CDIO_ReadFileTables_004093e0(GexLevFileStruct *file);
int __cdecl CDIO_OpenDirectory_00409350(void *idl, GexLevFileStruct *file, int number)
{
    char name[256];
    if (number != 13) {
        memset(file, 0, sizeof(*file));
        wsprintfA(name, s_LEV_GEX_3d_LEV_004559e4, number);
        file->handle = CDIO_FileOpen_00409170(name);
        CDIO_ReadFileTables_004093e0(file);
    } else {
        file->size = gIDL_0047f000->count;
        file->data = gIDL_0047f000->entries;
        file->handle = 2;
    }
    return 1;
}
}
