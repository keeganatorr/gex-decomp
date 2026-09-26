typedef void *HANDLE;
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
extern int nFileHandles_0047f004;
extern HANDLE HANDLE_ARRAY_0047f010[8];
extern void *gIDL_0047f000;
extern char s_CDIO_have_d_open_Files_on_Clos_00455a04[];
void __cdecl assertfail_00405350(const char *fmt, ...);
void __cdecl FreeMemory_00409740(void *block);
__declspec(dllimport) int __stdcall CloseHandle(HANDLE h);
void __cdecl GEX_Target(void)
{
    HANDLE *handle;
    if (nFileHandles_0047f004) {
        assertfail_00405350(s_CDIO_have_d_open_Files_on_Clos_00455a04, nFileHandles_0047f004);
        for (handle = HANDLE_ARRAY_0047f010; handle < &HANDLE_ARRAY_0047f010[8]; handle++) {
            if (*handle) {
                CloseHandle(*handle);
                *handle = 0;
            }
        }
        nFileHandles_0047f004 = 0;
    }
    if (gIDL_0047f000)
        FreeMemory_00409740(gIDL_0047f000);
    gIDL_0047f000 = 0;
}
}
