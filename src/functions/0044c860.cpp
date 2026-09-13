// Fill the three-word mantissa, without assuming a larger floating-point layout.
extern void *__cdecl memset(void *, int, unsigned int);
void __cdecl GEX_Target(unsigned int *words)
{
    memset(words, 0, 12);
}
