extern "C" {
extern unsigned char PasswordDecipherKey_0045aba8[4];
extern char s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[];
void __cdecl GEX_Target(char *text, unsigned char *data, int bits)
{
    int i;
    int n;
    unsigned char key;
    i = 0;
    for (n = 0; n < bits; n += 8) {
        key = PasswordDecipherKey_0045aba8[i & 3] ^ *data++;
        *text++ = s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[key & 0xf];
        *text++ = s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[(key & 0xf0) >> 4];
        i++;
    }
    *text = 0;
}
}
