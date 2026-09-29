typedef struct FileEntry { int a, b, c, d; } FileEntry;
typedef struct FileTables { int count; FileEntry *entries; void *file; } FileTables;
extern "C" {
extern int DAT_004626e4_FileSize;
extern void __cdecl CDIO_FileRead_00409250(void *, void *, int);
extern void * __cdecl MEM_AllocMem_004096c0(int);
int __cdecl CDIO_ReadFileTables_004093e0(FileTables *tables)
{
    int size;
    CDIO_FileRead_00409250(tables->file, &DAT_004626e4_FileSize, 4);
    size = (DAT_004626e4_FileSize + 1) * sizeof(FileEntry);
    tables->count = DAT_004626e4_FileSize;
    tables->entries = (FileEntry *)MEM_AllocMem_004096c0(size);
    CDIO_FileRead_00409250(tables->file, tables->entries, size);
    return 1;
}
}
