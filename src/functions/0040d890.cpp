// Adapted from pc_decomp_backup/src/functions/FUN_0040d890.cpp
// Historical source SHA256: bb59022a477a64a12eae9578bb1dc388b991ee610bcf93104cfe930eab3da98a
typedef unsigned int undefined4;
extern "C" {
void __cdecl HelpBoxGetLine_0040d890(char *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *param_1;
  for (; (cVar1 != '\0' && (*param_1 != '\\')); param_1 = param_1 + 1) {
    cVar1 = param_1[1];
  }
  if ((param_1[1] == 'C') || (uVar2 = 2, param_1[1] == 'c')) {
    uVar2 = 4;
  }
  if (*param_1 == '\0') {
    *param_2 = 1;
    return;
  }
  *param_1 = '\0';
  *param_2 = uVar2;
  return;
}
}
