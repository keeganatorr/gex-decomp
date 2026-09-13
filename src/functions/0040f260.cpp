// Adapted from pc_decomp_backup/src/functions/FUN_0040F260.cpp
// Historical source SHA256: a8641f4e9c9ad4c53accbde057d19ac8acd8198ea62296d8dbac2dd84daf509f
extern "C" {
extern "C" void __cdecl GEX_Target(int* p)
{
    int vel = p[0x20] + p[0x22];
    int maxVel = p[0x21];
    if (vel > maxVel) { vel = maxVel; }
    else if (vel < -maxVel) { vel = -maxVel; }
    p[0x20] = vel;
    p[0x1e] += vel;
}
}
