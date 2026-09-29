typedef struct Directory { int count; void *entries; void *file; } Directory;
extern "C" {
void * __cdecl memset(void *, int, unsigned int);
extern void __cdecl CDIO_FileClose_00409200(void *);
extern void __cdecl FreeMemory_00409740(void *);
int __cdecl CDIO_CloseDirectory_00409320(Directory *dir)
{
    if (dir->file > (void *)2) {
        CDIO_FileClose_00409200(dir->file);
        FreeMemory_00409740(dir->entries);
    }
    memset(dir, 0, sizeof(Directory));
    return 0;
}
}
