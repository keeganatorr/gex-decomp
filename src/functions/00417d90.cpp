extern "C" {
extern int DAT_004A288C;
extern int DAT_004A2964;
extern int DAT_004A2AC0;
extern unsigned char DAT_004A0299;
extern unsigned char DAT_004A0287;
extern unsigned char DAT_004A028A;
extern int *DAT_004A27FC;
extern int DAT_00457210;
extern int DAT_00455C48;
extern int DAT_00455C4C;
extern int FUN_004A27E8;
extern int DAT_00459498;
extern int DAT_0045a6e0_GexPowerUpHealth;
void FUN_0041A250(void *, int, int, int);
void FUN_00416320(void *);

void GEX_Target(void)
{
  int ofs;
  if (DAT_004A288C == 0 &&
      DAT_004A2964 != 0x44 &&
      DAT_004A2AC0 == 0 &&
      DAT_004A0299 != 0 &&
      DAT_004A0287 == 0 &&
      (*(unsigned int *)((char *)&DAT_00457210 + (ofs = DAT_004A27FC[0x1c] * 4)) & 0xc) == 0 &&
      DAT_00455C48 != 0)
  {
    FUN_004A27E8 = 1;
    DAT_004A288C = (*(unsigned int *)((char *)&DAT_00457210 - 0x2D0 + ofs) == 0) ? 1 : 2;
    DAT_00455C4C = DAT_00455C4C + 1;
    DAT_004A0299 = 0;
    DAT_004A028A = 0;
    FUN_0041A250(DAT_004A27FC, 0x8b, 0x80, 0x60);
    DAT_00459498 = DAT_0045a6e0_GexPowerUpHealth;
  }
  if ((*(unsigned int *)((char *)&DAT_00457210 + DAT_004A27FC[0x1c] * 4) & 8) != 0)
  {
    FUN_00416320(DAT_004A27FC);
  }
}
}
