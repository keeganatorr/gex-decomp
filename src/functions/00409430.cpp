typedef struct IDLEntry { int unk0; int size; int offset; int unkC; } IDLEntry;
typedef struct GexLevFileStruct {
    int size;          /* 0x0 */
    void *data;        /* 0x4: directory entries, or the parent directory */
    int handle;        /* 0x8: 1 means files are separate LEV files on disk */
    int offset;        /* 0xc */
} GexLevFileStruct;
extern "C" {
void *__cdecl memset(void *dst, int value, unsigned int count);
__declspec(dllimport) int __cdecl wsprintfA(char *buffer, const char *format, ...);
extern char s_LEV_GEX_3d_LEV_004559e4[];
int __cdecl CDIO_FileOpen_00409170(const char *name);
int __cdecl CDIO_FileSize_004092a0(int handle);
int __cdecl GEX_Target(GexLevFileStruct *directory, GexLevFileStruct *file, int index)
{
    char name[256];
    memset(file, 0, sizeof(*file));
    file->data = directory;
    if (directory->handle != 1) {
        file->size = ((IDLEntry *)directory->data)[index].size;
        file->offset = ((IDLEntry *)directory->data)[index].offset;
        file->handle = directory->handle;
    } else {
        wsprintfA(name, s_LEV_GEX_3d_LEV_004559e4, index);
        file->handle = CDIO_FileOpen_00409170(name);
        file->size = CDIO_FileSize_004092a0(file->handle);
    }
    return 1;
}
}
