// Adapted from pc_decomp_backup/src/functions/FUN_0041A680.cpp
// Historical source SHA256: d1f0a8ae162ea0d52d78ef2db958f84ae8def64fd95f31e9a88081a2c6ca3a20
extern "C" {
extern "C" { extern unsigned int DAT_004A2660[]; }
extern "C" { extern unsigned int DAT_004A2678; }

extern "C" unsigned int __cdecl GEX_Target()
{
    int index = 0;
    unsigned int* ptr = DAT_004A2660;

    while (1) {
        unsigned int val = *ptr;
        unsigned int low_byte = val & 0xff;
        if (low_byte != 4 && low_byte != 3) {
            DAT_004A2660[index] = 4;
            return val;
        }
        ptr = ptr + 1;
        index = index + 1;
        if (ptr >= &DAT_004A2678) {
            index = 0;
            ptr = DAT_004A2660;
            do {
                val = *ptr;
                if ((unsigned char)val == 3) {
                    DAT_004A2660[index] = 4;
                    return val;
                }
                ptr = ptr + 1;
                index = index + 1;
            } while (ptr < &DAT_004A2678);
            return 4;
        }
    }
}
}
