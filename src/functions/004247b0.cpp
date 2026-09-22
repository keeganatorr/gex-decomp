extern "C" {
extern int DAT_004A2990;
extern int DAT_004A021C;
extern int DAT_00456018_gex_Init_unk;
extern unsigned int DAT_0045B9A0[][8];
extern char DAT_004A0280;
extern char DAT_004A0281;
extern char DAT_004A0293;
extern char DAT_004A0294;
extern char DAT_004A0295;
unsigned int __cdecl FUN_0040F170(int, int, int);
void __cdecl FUN_00424290(int *);
void __cdecl InitPlayerTurn_00427550(int *);
void __cdecl FUN_00427760(int *);
void __cdecl FUN_00424B80(int *);
void __cdecl FUN_00427B80(int *);
void __cdecl FUN_004245B0(int *, int);
int __cdecl abs(int);
}

extern "C" void __cdecl GEX_Target(int *p)
{
    unsigned int *support;
    unsigned int attributes = DAT_0045B9A0[FUN_0040F170(DAT_004A2990, p[0x1e], p[0x1f])][0];

    if (DAT_004A021C == 0 && DAT_00456018_gex_Init_unk == 0) {
        support = *(unsigned int **)(p + 0x44);
        if ((support == 0 && (attributes & 0x0c000000u)) ||
            (support != 0 && (support[0x2d] & 0x600u))) {
            FUN_00424290(p);
            return;
        }
        if (DAT_004A0280 && ((unsigned int)p[0x1b] & 0x80000000u)) {
            InitPlayerTurn_00427550(p);
            return;
        }
        if (DAT_004A0281 && !((unsigned int)p[0x1b] & 0x80000000u)) {
            InitPlayerTurn_00427550(p);
            return;
        }
        if (DAT_004A0295) {
            FUN_00427760(p);
            return;
        }
        if (DAT_004A0294) {
            FUN_00424B80(p);
            return;
        }
        if (DAT_004A0293) {
            FUN_00427B80(p);
            return;
        }
    }

    p[0x27] -= abs(p[0x20]);
    if (p[0x27] < 0) {
        ++p[0x15];
        p[0x27] += 0x90000;
        if (p[0x27] < 0)
            p[0x27] = 0;
    }
    FUN_004245B0(p, 0x3000);
}
