// Adapted from pc_decomp_backup/src/functions/FUN_004451E0.cpp
// Historical source SHA256: 33d41afe6c36ea21d707066c50ae3f9ccfd77ce18e8039e82b6afdb22123d30d
extern "C" {
extern "C" { extern short* FUN_004A33AC; }

extern "C" int __cdecl GEX_Target(void* drawCache, short* fileMemoryPointer)
{
    short* pd = (short*)drawCache;
    int eax = pd[0];
    int esi = pd[1] << 10;
    int ecx = pd[2];
    esi += eax;
    eax = (int)FUN_004A33AC;
    int ebx = pd[3];
    short* pixels = (short*)((char*)eax + esi * 2);
    int strideBytes = (0x400 - ecx) * (int)sizeof(short);
    
    if (ebx != 0) {
        do {
            ecx = pd[2];
            if (ecx != 0) {
                do {
                    *pixels++ = *fileMemoryPointer++;
                    ecx--;
                } while (ecx != 0);
            }
            pixels = (short*)((char*)pixels + strideBytes);
            ebx--;
        } while (ebx != 0);
    }
    return 1;
}
}
