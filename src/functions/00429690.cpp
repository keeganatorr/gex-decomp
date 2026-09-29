extern "C" {
extern char s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[];
void __cdecl FUN_00429690_PasswordString(unsigned char *password)
{
    unsigned int sum = 0;
    unsigned char *p;
    for (p = password + 2; *p; p++)
        sum += *p;
    password[0] = s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[sum & 0xf];
    password[1] = s_BCDFGHKLPRSTVXYZGot_password_s_0045abd8[(sum & 0xf0) >> 4];
}
}
