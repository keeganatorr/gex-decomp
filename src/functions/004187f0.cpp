extern "C" {
extern unsigned __cdecl GOB_PutObjectBehindObject_00419bc0(...);extern unsigned DAT_0049fb94;
typedef unsigned int undefined4;
struct GXObject;
undefined4 __cdecl SCRIPT_DisplayBehindParent_004187f0(undefined4 param_1,GXObject **param_2)

{
  if (param_2[0x57] != (GXObject *)0x0) {
    GOB_PutObjectBehindObject_00419bc0(param_2,(GXObject **)param_2[0x57]);
    return param_1;
  }
  GOB_PutObjectBehindObject_00419bc0(param_2,DAT_0049fb94);
  return param_1;
}
}
