extern "C" int __cdecl FUN_00444930(char*, const char*, int*);
extern "C" void __cdecl FUN_0043FA70(int, int, char*, int);

extern "C" void __cdecl TXT_DrawPrintFP_0043faa0(int xPos, int yPos, const char* text, ...)
{
    char buffer[0x64];
    int* args = (int*)&text + 1;
    FUN_00444930(buffer, text, args);
    FUN_0043FA70(xPos, yPos, buffer, 0);
}
