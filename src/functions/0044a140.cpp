extern "C" int tolower(int);
extern "C" int _isctype(int, int);
extern "C" int DAT_004613a4;
extern "C" unsigned short *PTR_DAT_00461198;
extern "C" char DAT_004613a8;

extern "C" void GEX_Target(char *param_1)
{
  char cVar1;
  int iVar2;
  unsigned int uVar3;
  char cVar4;
  int one = 1;

  iVar2 = tolower(*param_1);
  if (iVar2 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (one >= DAT_004613a4) {
        uVar3 = PTR_DAT_00461198[*param_1] & 4;
      } else {
        uVar3 = _isctype(*param_1, 4);
      }
    } while (uVar3 != 0);
  }
  cVar4 = *param_1;
  *param_1 = DAT_004613a8;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar4;
    if (cVar4 == '\0') {
      break;
    }
    cVar4 = cVar1;
  } while (1);
}
