extern "C" {
extern int M1_NumIntros_004626fc;
extern int **M1_ObjectIntroTrackerTable_004a2a78;
}

typedef unsigned int undefined4;

extern "C" {
void __cdecl OIN_SetIntroDistance_00409a00(undefined4 param_1)
{
  int i;
  for (i = 0; i < M1_NumIntros_004626fc; i++) {
    *(undefined4 *)((char *)M1_ObjectIntroTrackerTable_004a2a78[i] + 0x34) = param_1;
  }
}
}
