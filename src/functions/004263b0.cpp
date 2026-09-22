struct Player {
    unsigned char unknown00[0x50];
    volatile int field50;
    int field54;
    unsigned char unknown58[0x14];
    unsigned int flags;
    volatile int state;
    int unknown74;
    int x;
    int y;
    int velocityX;
    int velocityY;
    int velocityZ;
    volatile int field8c;
    unsigned char unknown90[8];
    int field98;
    unsigned char unknown9c[0x28];
    int fieldc4;
};
extern "C" {
void __cdecl FUN_00420BC0(Player*);
void __cdecl FUN_00423C80(Player*);
int __cdecl FUN_00421560_DrawCharacter(int, Player*);
void __cdecl FUN_0042E480(int, int, unsigned int, int, unsigned int);
void __cdecl FUN_00426330(Player*);
extern int FUN_004A2990;
extern int DAT_004a27f8;
extern unsigned char DAT_004a0280;
extern unsigned char DAT_004A0281;
}

static inline void InitializeFall(Player* p) {
    p->state = 0x2c;
    p->field50 = 0x28;
    p->field8c = 0;
    p->field54 = 5;
    p->velocityY = 0x90000;
    p->field98 = 3;
    FUN_00423C80(p);
    if (DAT_004a0280 == 0 && DAT_004A0281 == 0) {
        p->velocityX = 0;
        p->velocityZ = 0;
    }
}

extern "C" void __cdecl GEX_Target(Player* p) {
    FUN_00420BC0(p);
    InitializeFall(p);
    DAT_004a27f8 = 1;
    FUN_00421560_DrawCharacter(FUN_004A2990, p);
    FUN_0042E480(p->x + 0xa0000, p->y, p->flags & 0x80000000, p->fieldc4, p->flags & 0xf);
    FUN_0042E480(p->x - 0xa0000, p->y, p->flags & 0x80000000, p->fieldc4, p->flags & 0xf);
    FUN_00426330(p);
}
