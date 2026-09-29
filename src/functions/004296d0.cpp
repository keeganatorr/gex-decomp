extern "C" {
extern char s_Put_value_d_d_d_2x_addr_0045ac88[];
extern char s_Error_numbits_d_too_small_for_v_0045ac5c[];
extern char s_stream_value_now_2x_0045ac44[];
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
void __cdecl FUN_004296d0_ParseLoadPasswords(unsigned char *stream, int value, int bitpos, int numbits)
{
    unsigned char *p;
    int count;
    int shift;
    p = stream + bitpos / 8;
    TracePrintf_Debug_00405390(s_Put_value_d_d_d_2x_addr_0045ac88, value, bitpos, numbits, *p, p);
    if ((1 << numbits) <= value)
        TracePrintf_Debug_00405390(s_Error_numbits_d_too_small_for_v_0045ac5c, numbits, value);
    while (numbits) {
        count = 8 - (bitpos & 7);
        shift = count - numbits;
        if (shift < 0)
            shift = 0;
        else
            count = numbits;
        bitpos += count;
        numbits -= count;
        *p++ |= (unsigned char)((unsigned char)((1 << count) - 1) & (unsigned char)value) << shift;
        value >>= count;
    }
    TracePrintf_Debug_00405390(s_stream_value_now_2x_0045ac44, p[-1]);
}
}
