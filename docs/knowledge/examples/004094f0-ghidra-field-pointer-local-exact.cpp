typedef struct GexLevFileStruct {
    int unk0;
    int unk4;
    int handle;    /* 0x8: 2 means the IDL memory image */
    int offset;    /* 0xc */
} GexLevFileStruct;
extern "C" {
void *__cdecl memcpy(void *dst, const void *src, unsigned int count);
extern unsigned char *gIDL_0047f000;
int __cdecl CDIO_FileSeek_004092d0(int handle, int offset, int origin);
int __cdecl CDIO_FileRead_00409250(int handle, void *buffer, unsigned int bytes);
int __cdecl GEX_Target(GexLevFileStruct *file, void *buffer, unsigned int bytes)
{
    if (file->handle == 2) {
        memcpy(buffer, gIDL_0047f000 + file->offset, bytes);
    } else {
        CDIO_FileSeek_004092d0(file->handle, file->offset, 0);
        CDIO_FileRead_00409250(file->handle, buffer, bytes);
    }
    file->offset += bytes;
    return 1;
}
}
