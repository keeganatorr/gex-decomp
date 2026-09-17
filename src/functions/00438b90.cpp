extern "C" int DAT_00455c54_DebugVar;
extern "C" char DAT_0045f088[];
extern "C" char DAT_0045f0f8[];
extern "C" void FUN_00405390(char *, ...);

struct ObjectStructPoss {
  char pad0[8];
  int ObjectType;
  char pad1[0x6c - 0xc];
  int field105_0x6c;
};

extern "C" int GEX_Target(struct ObjectStructPoss *param_1) {
  if ((param_1->field105_0x6c & 0x1f000000) == 0x5000000) {
    if (DAT_00455c54_DebugVar > 1) {
      FUN_00405390(DAT_0045f088, param_1->ObjectType);
      FUN_00405390(DAT_0045f0f8);
    }
    return 1;
  }
  return 0;
}