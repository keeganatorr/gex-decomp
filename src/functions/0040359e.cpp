// Adapted from pc_decomp_backup/src/functions/FUN_0040359E.cpp
// Historical source SHA256: 59334e716261ef0cc33532f23cef8b4a32c388a196fd00601d669b6bf04f66cf
extern "C" {
extern "C" int __cdecl GEX_Target(int a, unsigned int msg, int b)
{
    int l[0x100 / 4];
    int x = l[0];
    int y = l[1];
    int z = l[2];

    if (msg == 2) { x = l[0]; }
    if (msg == 0x110) { x = l[1]; }
    if (msg == 0x111) { x = l[2]; }
    return x;
}
}
