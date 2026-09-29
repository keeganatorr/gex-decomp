extern "C" int *gInputRecords_004a27dc;
extern "C" int (__cdecl *PTR_ARRAY_00457c48[])(int);
extern "C" void CheckIdle_0040f440(unsigned int);

extern "C" int ReadControllerNoPlayback_0040f400(int param_1)
{
  int KeyInput;
  KeyInput = PTR_ARRAY_00457c48[*(int *)(param_1 * 0x24 + (int)gInputRecords_004a27dc)](param_1);
  CheckIdle_0040f440((unsigned int)(KeyInput != 0));
  return KeyInput;
}
