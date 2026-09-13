// Adapted from pc_decomp_backup/src/functions/FUN_00437E90.cpp
// Historical source SHA256: 1fa0a1c783f2bd2bd486ec79d5a3dcf5124fd81f4ceb3875d12f9610226294ba
extern "C" {
extern "C" { extern int DAT_00437F00; }
extern "C" { extern int DAT_0045EFD0; }
extern "C" void __cdecl FUN_00405350(int, int, int);
extern "C" void __cdecl FUN_00409430(int, void*, int);
extern "C" void __cdecl FUN_00409680(void*, int, void*, int, void*);

extern "C" void __cdecl GEX_Target(int param_1, int LEV, void* fileHandle, void* fileOutputBytes, int BytesToRead)
{
    int numberOfBytesToRead;
    int puVar1;

    *(int*)((int)fileHandle + 0x58) = 0;
    FUN_00409430(param_1, (void*)((int)fileHandle + 0x48), LEV);
    puVar1 = *(int*)((int)fileHandle + 0x48) + 0x7ff;
    numberOfBytesToRead = ((puVar1 >> 0x1f & 0x7ff) + puVar1 >> 0xb) * 0x800;
    if (BytesToRead < numberOfBytesToRead) {
        FUN_00405350((int)&DAT_0045EFD0, numberOfBytesToRead, BytesToRead);
        numberOfBytesToRead = BytesToRead;
    }
    *(int*)((int)fileHandle + 0x44) = (int)fileHandle;
    FUN_00409680((void*)((int)fileHandle + 0x48), (int)fileHandle, fileOutputBytes, numberOfBytesToRead, (void*)&DAT_00437F00);
}
}
