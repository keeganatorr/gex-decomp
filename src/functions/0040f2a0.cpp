// Adapted from pc_decomp_backup/src/functions/FUN_0040F2A0.cpp
// Historical source SHA256: d413197642ece38d94f37722d80851a4c28cd3a461243b5468751d6a3f163d19
extern "C" {
extern "C" void __cdecl GEX_Target(int* p)
{
    int vel = p[0x23] + p[0x25];
    int maxVel = p[0x24];
    if (vel > maxVel) { vel = maxVel; }
    else if (vel < -maxVel) { vel = -maxVel; }
    p[0x23] = vel;
    p[0x1f] += vel;
}
}
