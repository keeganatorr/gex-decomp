struct IDLDirectory {
    void *handle_0x0_LevelData;
    int pad_0x4;
    void *f_0x8_gOb_Tiles_gexTileStruct;
};

extern "C" IDLDirectory *PTR_gIDLDirectory_00455998;
extern "C" void *gIDL_0047f000;
extern "C" char s_IDL_GEX000_IDL_004559f4[];
extern "C" int CDIO_FileOpen_00409170(const char *filename);
extern "C" int CDIO_FileSize_004092a0(int handle);
extern "C" void *MEM_AllocMem_004096c0(int size);
extern "C" void CDIO_FileRead_00409250(int handle, void *buffer, int size);

extern "C" int GEX_Target(void)
{
    PTR_gIDLDirectory_00455998->handle_0x0_LevelData = (void *)0;
    PTR_gIDLDirectory_00455998->f_0x8_gOb_Tiles_gexTileStruct = (void *)1;
    int handle = CDIO_FileOpen_00409170(s_IDL_GEX000_IDL_004559f4);
    int fileSize = CDIO_FileSize_004092a0(handle);
    gIDL_0047f000 = MEM_AllocMem_004096c0(fileSize);
    CDIO_FileRead_00409250(handle, gIDL_0047f000, fileSize);
    return 1;
}
