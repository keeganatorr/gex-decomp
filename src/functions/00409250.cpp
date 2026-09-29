extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int decl_pad_10;
extern int decl_pad_11;
extern int decl_pad_12;
extern int decl_pad_13;
extern int decl_pad_14;
extern int decl_pad_15;
extern char DAT_00487a10_FileAccessErrorString[];
extern void __cdecl WinShowError_004063d0(int, char *);
__declspec(dllimport) int __stdcall ReadFile(void *, void *, unsigned long, unsigned long *, void *);
void __cdecl CDIO_FileRead_00409250(void *file, void *buffer, unsigned long size)
{
    unsigned long read;
    while (!ReadFile(file, buffer, size, &read, 0))
        WinShowError_004063d0(1, DAT_00487a10_FileAccessErrorString);
}
}
