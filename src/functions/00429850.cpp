extern "C" {
extern unsigned char PasswordDecipherKey_0045aba8[4];
extern char s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[];
void __cdecl FUN_00429850_PasswordRelated(char *text, unsigned char *data, int bits)
{
    int i;
    int n;
    int key;
    i = 0;
    for (n = 0; n < bits; n += 8) {
        key = (unsigned char)(PasswordDecipherKey_0045aba8[i & 3] ^ *data++);
        *text++ = s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[key & 0xf];
        *text++ = s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[(key & 0xf0) >> 4];
        i++;
    }
    *text = 0;
}
}
