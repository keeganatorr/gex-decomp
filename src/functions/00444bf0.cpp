extern "C" char * __cdecl FUN_00444bf0_sprintfInner(unsigned long value,
                                                     char *output, int base)
{
    if (value == 0) {
        *(unsigned short *)output = *(unsigned short *)0x004610c4;
        return output;
    }

    if (base < 2 || base > 36)
        base = 10;
    char digits[32];
    char *write = output;
    if (base == 10 && (long)value < 0) {
        *write++ = '-';
        value = 0 - value;
    }
    int count = 0;
    do {
        digits[count++] = (char)(value % base);
        value /= base;
    } while (value != 0);
    while (count != 0) {
        int digit = digits[--count];
        *write++ = (char)(digit < 10 ? digit + '0' : digit + 'W');
    }
    *write = 0;
    return output;
}
