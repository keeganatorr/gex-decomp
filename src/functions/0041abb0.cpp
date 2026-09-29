struct astruct_4 {
    char pad_0000[0x78];
    int RemoteX;
    int RemoteY;
    char pad_0080[0x18];
    int RemoteLevelID;
    int RemoteID;
};

extern "C" {
    void __cdecl FUN_00405350(const char*, int, int, int);
    void __cdecl FUN_00419520(void**);
    int __cdecl FUN_0041A590(int);
    extern int DAT_004a2964;
    extern unsigned char DAT_004a2420[];
    extern unsigned char DAT_00459080[];
    extern const char DAT_004590b0[];
    extern const char DAT_004590e4[];

    void __cdecl RemoteInit_0041abb0(astruct_4* LevelStruct) {
        if (LevelStruct->RemoteLevelID < 0) {
            FUN_00405350(DAT_004590e4,
                         LevelStruct->RemoteX >> 0x10,
                         LevelStruct->RemoteY >> 0x10,
                         LevelStruct->RemoteLevelID);
            return;
        }
        int RemoteID = LevelStruct->RemoteID;
        if (RemoteID < 0 || 2 < RemoteID) {
            FUN_00405350(DAT_004590b0,
                         LevelStruct->RemoteX >> 0x10,
                         LevelStruct->RemoteY >> 0x10,
                         RemoteID);
        } else {
            DAT_004a2420[DAT_004a2964] |= DAT_00459080[RemoteID];
            RemoteID = FUN_0041A590(LevelStruct->RemoteLevelID);
            if (RemoteID != 0) {
                FUN_00419520((void**)LevelStruct);
                if (RemoteID != 2) {
                    DAT_004a2420[DAT_004a2964] |= DAT_00459080[LevelStruct->RemoteID] << 4;
                }
            }
        }
    }
}
