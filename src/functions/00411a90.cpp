extern "C" {
int __cdecl FUN_00421f20_pStateUnk_Side(int*);
void __cdecl FUN_00411160(int*);
extern int DAT_004580a8[];
extern int DAT_00458148[];
extern int DAT_004581c8[];
extern int DAT_00457fe8[];

void __cdecl GEX_Target(int* p) {
    if (FUN_00421f20_pStateUnk_Side(p) != 0) {
        p[0x26] += 0x8000;
        if (p[0x26] > 0x10000) {
            unsigned int direction = (unsigned int)(((unsigned __int64)(unsigned int)p[0x1b] & 0x80000000U) >> 28) | (p[0x31] >> 21);
            p[0x26] -= 0x10000;
            int step = ++p[0x15];
            p[0x1e] += DAT_004580a8[step + DAT_00458148[direction * 2] * 5];
            p[0x1f] += DAT_004580a8[step + DAT_00458148[direction * 2 + 1] * 5];
            if (step > 3) {
                direction = DAT_004581c8[direction];
                p[0x1b] &= 0x7fffffff;
                p[0x31] = (direction & 7) << 21;
                if ((unsigned char)direction & 8) p[0x1b] |= 0x80000000U;
                p[0x1e] &= 0xffe00000;
                int offset = DAT_00457fe8[direction * 2];
                p[0x1f] &= 0xffe00000;
                offset |= p[0x1e];
                p[0x1e] = offset;
                p[0x1f] |= DAT_00457fe8[direction * 2 + 1];
                FUN_00411160(p);
            }
        }
    }
}
}
