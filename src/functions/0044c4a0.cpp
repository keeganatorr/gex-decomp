extern "C" {
unsigned __int64 __cdecl _get_int64_arg(unsigned __int64 **cursor)
{
    *cursor += 1;
    return (*cursor)[-1];
}
}
