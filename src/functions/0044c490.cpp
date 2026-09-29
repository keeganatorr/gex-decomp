// Advance the four-byte argument slot before loading its previous value.
extern "C" unsigned int __cdecl _get_int_arg(unsigned int **cursor)
{
    ++*cursor;
    return (*cursor)[-1];
}
