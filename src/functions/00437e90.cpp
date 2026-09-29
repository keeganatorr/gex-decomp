extern "C" {
extern int DAT_00437F00;
extern int DAT_0045EFD0;
void __cdecl FUN_00405350(int, int, int);
void __cdecl FUN_00409430(int, void*, int);
void __cdecl FUN_00409680(void*, int, void*, int, void*);

void __cdecl ASYNC_LoadFileToMem_00437e90(int param_1, int LEV, void* fileHandle, void* fileOutputBytes, int BytesToRead)
{
    void* levFileStruct;
    int numberOfBytesToRead;

    *(int*)((int)fileHandle + 0x58) = 0;
    levFileStruct = (void*)((int)fileHandle + 0x48);
    FUN_00409430(param_1, levFileStruct, LEV);
    numberOfBytesToRead = (*(int*)levFileStruct + 0x7ff) / 0x800 * 0x800;
    if (BytesToRead < numberOfBytesToRead) {
        FUN_00405350((int)&DAT_0045EFD0, numberOfBytesToRead, BytesToRead);
        numberOfBytesToRead = BytesToRead;
    }
    *(int*)((int)fileHandle + 0x44) = (int)fileHandle;
    FUN_00409680(levFileStruct, (int)fileHandle, fileOutputBytes, numberOfBytesToRead, (void*)&DAT_00437F00);
}
}
