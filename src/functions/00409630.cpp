extern "C" {
void __cdecl FUN_00409430(void*, void*, int);
void* __cdecl FUN_004096C0(int);
void __cdecl FUN_004094F0(void*, void*, int);
void __cdecl FUN_004094C0(void*);

struct FileHandle {
    int FileSize;
    void* Directory;
    void* Handle;
    int Offset;
};

void* __cdecl GEX_Target(void* idl_file_handle, int LEV)
{
    FileHandle fh;
    int fileSize;
    void* outputBuffer;

    FUN_00409430(idl_file_handle, &fh, LEV);
    fileSize = fh.FileSize;
    outputBuffer = FUN_004096C0(fileSize);
    FUN_004094F0(&fh, outputBuffer, fileSize);
    FUN_004094C0(&fh);
    return outputBuffer;
}
}