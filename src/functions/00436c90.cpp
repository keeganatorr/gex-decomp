extern "C" {
extern char s_SCRIPT_ERROR_s_0045b98c[];
void __cdecl assertfail_00405350(const char *format, ...);
void __cdecl exit_00449780(int);

void __cdecl SCRIPT_ExitScriptError_00436c90(char *message)
{
    assertfail_00405350(s_SCRIPT_ERROR_s_0045b98c, message);
    exit_00449780(-1);
}
}
