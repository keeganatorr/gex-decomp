extern "C" {
unsigned __int64 __cdecl GEX_Target(unsigned __int64 **cursor)
{
    *cursor += 1;
    return (*cursor)[-1];
}
}
