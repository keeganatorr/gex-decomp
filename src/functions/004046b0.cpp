typedef unsigned long DWORD;
typedef int BOOL;
typedef unsigned int UINT;
typedef DWORD MCIERROR;
typedef char CHAR;

extern "C" __declspec(dllimport) DWORD __stdcall GetCurrentDirectoryA(DWORD nBufferLength, CHAR* lpBuffer);
extern "C" __declspec(dllimport) BOOL __stdcall mciGetErrorStringA(MCIERROR mciError, CHAR* lpszErrorText, UINT cchErrorText);
extern "C" void __cdecl WinShowError_004063d0(int, const CHAR*, const CHAR*, const CHAR*);
extern "C" const CHAR s_AVI_ERROR___s__s_004517a8[];

extern "C" void __cdecl FUN_004046b0_AVI(MCIERROR param_1)
{
  CHAR local_400[512];
  CHAR local_200[512];
  GetCurrentDirectoryA(0x200, local_400);
  mciGetErrorStringA(param_1, local_200, 0x200);
  WinShowError_004063d0(0, s_AVI_ERROR___s__s_004517a8, local_200, local_400);
}