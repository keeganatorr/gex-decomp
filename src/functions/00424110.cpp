typedef unsigned int U32;

extern "C" {
extern unsigned char DAT_004A0294;
extern unsigned char DAT_004A0280;
extern unsigned char DAT_004A0281;
extern unsigned char DAT_004A0288;
extern unsigned char DAT_004A0295;
extern unsigned char DAT_004A0293;
extern void *DAT_004A2990;
extern U32 DAT_0045B9A0[];
void __cdecl InitPlayerSlide45Jump_00424320(U32 *);
void __cdecl FUN_00424AA0(U32 *);
void __cdecl FUN_00427760(U32 *);
void __cdecl FUN_00427B80(U32 *);
void __cdecl InitPlayerRunSkid_004270b0(U32 *);
void __cdecl FUN_004250B0(U32 *);
U32 __cdecl FUN_0040F170(void *, U32, U32);
void __cdecl FUN_004213f0_GexMovementLeftandRight(U32 *);
int __cdecl FUN_00421560_DrawCharacter(void *, U32 *);
}

extern "C" void __cdecl PlayerSlide45_00424110(U32 *p)
{
    U32 flags;
    U32 *support;
    if (DAT_004A0294) {
        InitPlayerSlide45Jump_00424320(p);
        return;
    }
    if ((DAT_004A0280 || DAT_004A0281) && DAT_004A0288) {
        FUN_00424AA0(p);
        return;
    }
    if (DAT_004A0295) {
        FUN_00427760(p);
        return;
    }
    if (!DAT_004A0293) {
        if (p[0x27])
            --p[0x27];
        support = (U32 *)p[0x44];
        if (support) {
            flags = support[0x2d] & 0x600;
            if (flags) {
                if (flags & 0x400)
                    flags = 0x08000000;
                else if (flags & 0x200)
                    flags = 0x04000000;
            }
        } else {
            flags = DAT_0045B9A0[FUN_0040F170(DAT_004A2990, p[0x1e], p[0x1f]) * 8];
        }
        if (!(flags & 0x0c000006)) {
            InitPlayerRunSkid_004270b0(p);
            return;
        }
        if (flags & 0x04000004) {
            p[0x1b] &= 0x7fffffff;
            if (!p[0x27])
                p[0x22] = 0xffff0000;
        } else if (flags & 0x08000002) {
            p[0x1b] |= 0x80000000;
            if (!p[0x27])
                p[0x22] = 0x10000;
        }
        if (++p[0x26] == 2) {
            p[0x26] = 0;
            ++p[0x15];
        }
        FUN_004213f0_GexMovementLeftandRight(p);
        if (!FUN_00421560_DrawCharacter(DAT_004A2990, p)) {
            FUN_004250B0(p);
            return;
        }
    } else {
        FUN_00427B80(p);
    }
}
