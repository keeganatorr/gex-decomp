// Adapted from pc_decomp_backup/src/functions/FUN_0043FAA0.cpp
// Historical source SHA256: 1277a404a578a1b5f9470df211e86d79bb01491e187d183f5aca303a366377e3
extern "C" {
extern "C" int __cdecl FUN_00444930(char*, const char*, int*);
extern "C" void __cdecl FUN_0043FA70(int, int, char*);

extern "C" void __cdecl GEX_Target(int xPos, int yPos, const char* text, ...)
{
    char buffer[0x64];
    int* args = (int*)&text + 1;
    FUN_00444930(buffer, text, args);
    FUN_0043FA70(xPos, yPos, buffer);
}
}
