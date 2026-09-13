// Adapted from pc_decomp_backup/src/functions/FUN_00409630.cpp
// Historical source SHA256: 1d785f0a6d368a1275f9eedf11dda0fdec9524dba6969679fb77dfc5a1865e43
extern "C" {
extern "C" void __cdecl FUN_00409430(void*, void*, int);
extern "C" void* __cdecl FUN_004096C0(int);
extern "C" void __cdecl FUN_004094F0(void*, void*, int);
extern "C" void __cdecl FUN_004094C0(void*);

struct FileHandle {
    int FileSize;
    void* Directory;
    void* Handle;
    int Offset;
};

extern "C" void* __cdecl GEX_Target(void* idl_file_handle, int LEV)
{
    FileHandle fh;
    void* outputBuffer;

    FUN_00409430(idl_file_handle, &fh, LEV);
    outputBuffer = FUN_004096C0(fh.FileSize);
    FUN_004094F0(&fh, outputBuffer, fh.FileSize);
    FUN_004094C0(&fh);
    return outputBuffer;
}
}
