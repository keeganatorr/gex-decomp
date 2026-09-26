typedef int (__stdcall *PFN2C)(void *, int, int, void **, unsigned long *, void **, unsigned long *, int);
typedef int (__stdcall *PFN50)(void *);
typedef int (__stdcall *PFN4C)(void *, void *, unsigned long, void *, unsigned long);

// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern "C" int decl_pad_0;
extern "C" int decl_pad_1;
extern "C" __declspec(dllimport) int __stdcall ReadFile(void *, void *, unsigned long, unsigned long *, void *);

extern "C" int GEX_Target(void *obj, void *hFile, int param3)
{
    int result;
    int b;
    unsigned long bytesRead;
    void *buf1;
    unsigned long size1;
    void *buf2;
    unsigned long size2;

    result = (*(PFN2C *)(*(void ***)obj + 0x2c / 4))(obj, 0, param3, &buf1, &size1, &buf2, &size2, 0);
    if (result == 0x88780096) {
        (*(PFN50 *)(*(void ***)obj + 0x50 / 4))(obj);
        result = (*(PFN2C *)(*(void ***)obj + 0x2c / 4))(obj, 0, param3, &buf1, &size1, &buf2, &size2, 0);
    }
    if (result == 0) {
        b = ReadFile(hFile, buf1, size1, &bytesRead, 0);
        if (b != 0) {
            if (buf2 == 0 || size2 == 0) {
                result = 1;
            } else {
                result = ReadFile(hFile, buf2, size2, &bytesRead, 0);
            }
            if (result != 0) {
                result = (*(PFN4C *)(*(void ***)obj + 0x4c / 4))(obj, buf1, size1, buf2, size2);
                if (result == 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
