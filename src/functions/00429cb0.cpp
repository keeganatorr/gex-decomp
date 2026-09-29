extern "C" { extern unsigned char BYTE_ARRAY_004a25d0[]; }
extern "C" {
int __cdecl FUN_00429cb0_RemoteTVSelect_Unk1(int SelectedTV, int param_2)
{
  do {
    SelectedTV = SelectedTV + 1;
    if (SelectedTV >= 0x90) {
      SelectedTV = 0;
    }
    if (BYTE_ARRAY_004a25d0[SelectedTV] != 0) {
      param_2 = param_2 - 1;
    }
  } while (param_2 != 0);
  return SelectedTV;
}
}
