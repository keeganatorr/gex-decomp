extern "C" {
unsigned int __cdecl strlen(const char *text);
extern char s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[];
int __cdecl PasswordIsValid_004295c0(char *password)
{
    int i;
    unsigned int j;
    unsigned int k;
    unsigned int sum;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 16; j++)
            if (s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[j] == password[i])
                break;
        if (j == 16)
            return 0;
    }
    if (strlen(password) < 8)
        return 0;
    sum = 0;
    for (k = 2; k < strlen(password); k++)
        sum += (unsigned char)password[k];
    if (s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[sum & 0xf] == password[0]
        && s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[(sum & 0xf0) >> 4] == password[1])
        return 1;
    return 0;
}
}
