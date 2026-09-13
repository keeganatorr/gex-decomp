// Adapted from pc_decomp_backup/src/functions/FUN_00429690.cpp
// Historical source SHA256: b5b9585bc560efdaae229dc651d5ea1edd90311b6cdbe53d5d9db168f97e0960
extern "C" {
extern "C" { extern const unsigned char DAT_0045abd8[]; }

extern "C" void __cdecl GEX_Target(unsigned char* password)
{
    unsigned int sum;
    unsigned char* pb;
    unsigned char b;

    sum = 0;
    pb = password + 2;
    b = *pb;
    if (b == 0) goto done;
    do {
        pb++;
        sum += b;
        b = *pb;
    } while (b != 0);
done:
    password[0] = DAT_0045abd8[sum & 0xf];
    password[1] = DAT_0045abd8[(sum >> 4) & 0xf];
}
}
