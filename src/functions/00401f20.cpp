typedef void *HANDLE;
typedef void *HGLOBAL;
extern "C" {
__declspec(dllimport) HGLOBAL __stdcall GlobalAlloc(unsigned int flags, unsigned long bytes);
HANDLE __cdecl CDIO_FileOpen_00409170(const char *name);
unsigned long __cdecl CDIO_FileSize_004092a0(HANDLE file);
int __cdecl CDIO_FileRead_00409250(HANDLE file, void *buffer, unsigned long bytes);
void __cdecl CDIO_FileClose_00409200(HANDLE file);
extern char s_SFX_GEX_SFX_004514f8[];
extern unsigned char *gSFXTable_0049fb54;
extern int gSndSizes_00451048[];
extern unsigned char *gSNDPointerArray_0049f6b0[];
extern unsigned char *DAT_0049fb14_DS_pDSCaps;
void __cdecl GEX_Target(void)
{
    HANDLE file;
    unsigned char *data;
    unsigned long bytes;
    unsigned char **sound;
    int *size;
    file = CDIO_FileOpen_00409170(s_SFX_GEX_SFX_004514f8);
    bytes = CDIO_FileSize_004092a0(file);
    gSFXTable_0049fb54 = (unsigned char *)GlobalAlloc(0, bytes);
    CDIO_FileRead_00409250(file, gSFXTable_0049fb54, bytes);
    CDIO_FileClose_00409200(file);
    data = gSFXTable_0049fb54;
    size = gSndSizes_00451048;
    for (sound = gSNDPointerArray_0049f6b0; sound < &gSNDPointerArray_0049f6b0[281]; sound++) {
        *sound = data;
        data += *size;
        size++;
    }
}
}
