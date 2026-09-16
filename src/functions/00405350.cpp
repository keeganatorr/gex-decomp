extern "C" {
typedef unsigned int UINT;
extern unsigned gDebugInfo_004879f4;
__declspec(dllimport) int __stdcall wvsprintfA(char *, const char *, void *);
__declspec(dllimport) int __stdcall OutputDebugStringA(const char *);
void __cdecl GEX_Target(const char *formatString, ...) { char debugMessageBuffer[256]; if(gDebugInfo_004879f4 != 0){wvsprintfA(debugMessageBuffer, formatString, (char*)(&formatString + 1));OutputDebugStringA(debugMessageBuffer);} }
}
