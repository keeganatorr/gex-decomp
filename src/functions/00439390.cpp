extern "C" int CAMERA_YPos_004a2a1c;
extern "C" int DAT_0045fb14[];
extern "C" int DAT_00464630;
extern "C" int DAT_00464634;
extern "C" int DAT_00464658;
extern "C" int __cdecl rand(void);

extern "C" void __cdecl FUN_00439390_HuntDiveInner(int *param_1, int *param_2, int *param_3, int *param_4)
{
  int hi;
  int lo;
  int cnt;
  int val;
  int *in;
  int *out;
  int r1;
  int r2;

  lo = (CAMERA_YPos_004a2a1c >> 0x15) - 1;
  hi = lo + 8;
  cnt = 0;
  in = DAT_0045fb14;
  out = &DAT_00464630;
  do {
    val = *in;
    if (hi < val) break;
    if (lo <= val && out < &DAT_00464658) {
      out = out + 2;
      *out = 0;
      *out = 0;
      cnt = cnt + 1;
      out[-2] = in[-1];
      out[-1] = val;
    }
    in = in + 2;
  } while (in < DAT_0045fb14 + 200);

  if (1 < cnt) {
    r1 = rand() % cnt;
    do {
      r2 = rand() % cnt;
    } while (r2 == r1);
    *param_1 = (&DAT_00464630)[r1 * 2];
    *param_2 = (&DAT_00464634)[r1 * 2];
    *param_3 = (&DAT_00464630)[r2 * 2];
    *param_4 = (&DAT_00464634)[r2 * 2];
    return;
  }
  *param_1 = -1;
  *param_2 = -1;
  *param_3 = -1;
  *param_4 = -1;
}
