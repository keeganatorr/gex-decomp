typedef struct Offset {
    int dx;
    int dy;
} Offset;

extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern int decl_pad_4;
extern int decl_pad_5;
extern int decl_pad_6;
extern int decl_pad_7;
extern int decl_pad_8;
extern int decl_pad_9;
extern int decl_pad_10;
extern int decl_pad_11;
extern int decl_pad_12;
extern int decl_pad_13;
extern int decl_pad_14;
extern int decl_pad_15;
extern int decl_pad_16;
extern int decl_pad_17;
extern int decl_pad_18;
extern int decl_pad_19;
extern int decl_pad_20;
extern int decl_pad_21;
extern int decl_pad_22;
extern int decl_pad_23;
extern int decl_pad_24;
extern int decl_pad_25;
extern void *M1_CurrentLevel_004a2990;
extern unsigned char DAT_0045B9A0[];
extern Offset DAT_00459118[];
extern void *PTR_ARRAY_004a23e0[];
extern int DAT_00459178[];
extern int DAT_004591a0[];
extern int DAT_004591C4;
extern int DAT_004591c8;
extern char s_Error_no_breakable_object_004591cc[];
extern char s_Error_Breakable_center_004591fc[];
unsigned short *__cdecl GOB_GetBlockAddress_00419fe0(void *, int, int);
int __cdecl M1_GetContourDataFromID_0040f100(void *, int, int);
int __cdecl M1_GetBlockAttributeIDAtPos_0040f170(void *, int, int);
void __cdecl assertfail_00405350(char *, ...);
void __cdecl SND_PlaySoundNoPosition_0041a360(int, int);
void __cdecl SetTileToAlternate_0041b0e0(int, int);
int *__cdecl GOB_AddObject_004195d0(int, int, int, void *);
void __cdecl GOB_SetObjectDisplayPriority_00419b80(int *, int);

int __cdecl GEX_Target(int x, int y)
{
    int rows;
    int cols;
    unsigned short *block;
    int c;
    int type;
    int kind;
    int i;
    int bx;
    int *obj;
    block = GOB_GetBlockAddress_00419fe0(M1_CurrentLevel_004a2990, x, y);
    if (block[1] && (c = M1_GetContourDataFromID_0040f100(M1_CurrentLevel_004a2990, block[1], x)) != 0
        && (y & 0x1f0000) < c - 0x10000)
        return 0;
    type = block[3];
    if (*(int *)(DAT_0045B9A0 + type * 32) & 0x10000000) {
        type -= 0x40;
        if (type > 0xb) {
            if ((y & 0x1f0000) < 0x100000)
                return 0;
            type -= 0x38;
        }
        x &= 0xffe00000;
        y &= 0xffe00000;
        x += DAT_00459118[type].dx;
        y += DAT_00459118[type].dy;
        kind = M1_GetBlockAttributeIDAtPos_0040f170(M1_CurrentLevel_004a2990, x + 0x200000, y + 0x200000) - 0x48;
        if (kind < 0 || kind >= 4) {
            assertfail_00405350(s_Error_Breakable_center_004591fc, x / 0x200000 + 1, y / 0x200000 + 1);
            return 1;
        }
        if (!PTR_ARRAY_004a23e0[kind]) {
            assertfail_00405350(s_Error_no_breakable_object_004591cc, kind);
            return 1;
        }
        SND_PlaySoundNoPosition_0041a360(0x83, 0x80);
        i = 0;
        for (rows = 3; rows; rows--) {
            bx = x;
            for (cols = 3; cols; cols--) {
                SetTileToAlternate_0041b0e0(bx, y);
                obj = GOB_AddObject_004195d0(0x5c, bx + 0x100000, y + 0x100000, PTR_ARRAY_004a23e0[kind]);
                if (obj) {
                    obj[0x1b] |= 0xc000;
                    obj[0x21] = 0x7fff0000;
                    obj[0x20] = DAT_00459178[i];
                    obj[0x22] = 0;
                    obj[0x24] = 0x7fff0000;
                    obj[0x23] = DAT_004591a0[i];
                    obj[0x25] = DAT_004591C4;
                    obj[0x26] = DAT_004591c8;
                    obj[0x1c] = 0x30;
                    GOB_SetObjectDisplayPriority_00419b80(obj, 4);
                }
                i++;
                bx += 0x200000;
            }
            y += 0x200000;
        }
        return 1;
    }
    return 0;
}
}
