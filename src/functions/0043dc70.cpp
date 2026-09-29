// Behavior-focused graphics command writer from the archived Ghidra translation.
// The old header and absolute-address macros are replaced with explicit symbols.
// Source types and byte identity have not been established.
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
typedef unsigned int undefined4;
extern "C" int* __cdecl FUN_0043E580(int*);
extern "C" int* __cdecl FUN_0043E920(int*);
extern "C" uint __cdecl FUN_0043ECF0(void*);
extern "C" uint __cdecl FUN_0043E2C0(uint);
extern "C" void __cdecl FUN_00445350(int, int, int, uint);
extern "C" int DAT_00460f6c;
extern "C" int* DAT_004a2ae4;
extern "C" int* DAT_004a2adc;
extern "C" int* DAT_004a2ae0;
extern "C" int* DAT_004a2b18;
extern "C" int* DAT_004a2b14;
extern "C" short DAT_004a2b20;
extern "C" {



void __cdecl
GEX_Target(char *param_1,short param_2,short param_3,uint param_4,uint param_5,uint param_6,
            short param_7,short param_8)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  short *psVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  byte local_21;
  byte local_20;
  byte local_1f;
  unsigned short local_1e;
  byte local_1c;
  int *local_18;
  ushort *local_14;
  undefined4 local_c;

  psVar7 = (short *)(param_1 + 0x14);
  bVar6 = param_1[0x10] & 3;
  bVar4 = param_1[0x10] & 0x40;
  if (bVar4 == 0) {
    if (*(short *)(param_1 + 0x1c) == 0) {
      local_18 = FUN_0043E580((int*)param_1);
    }
    else {
      local_18 = FUN_0043E920((int*)param_1);
    }
  }
  else {
    local_14 = (ushort *)(DAT_00460f6c + *(short *)(param_1 + 0x12) * 8);
  }
  if (bVar6 != 2) {
    uVar2 = FUN_0043ECF0((void*)param_4);
    local_1e = (unsigned short)uVar2;
  }
  uVar3 = FUN_0043E2C0(param_5);
  local_c = uVar3 & 0x00ffffff;
  if ((param_6 & 0xc0000000) == 0) {
    local_c = (local_c & 0x00ffffff) |
              ((((-((param_5 & 0x8080) == 0) & 0xfeU) + 0x66) & 0xff) << 24);
    if (*psVar7 != 0) {
      do {
        piVar8 = DAT_004a2ae4 + 10;
        piVar9 = DAT_004a2ae4;
        DAT_004a2ae4 = piVar8;
        if (DAT_004a2adc < piVar8) {
          piVar9 = DAT_004a2ae0;
          DAT_004a2ae4 = DAT_004a2ae0 + 10;
        }
        piVar8 = piVar9 + 5;
        piVar9[1] = local_c;
          *(unsigned short *)((int)piVar9 + 0xe) = local_1e;
        *(short *)(piVar9 + 2) = psVar7[2] + param_2;
        *(short *)((int)piVar9 + 10) = psVar7[3] + param_3;
        *(ushort *)(piVar9 + 4) = (ushort)*(byte *)(psVar7 + 1);
        *(ushort *)((int)piVar9 + 0x12) = (ushort)*(byte *)((int)psVar7 + 3);
        if (bVar4 == 0) {
          *(unsigned short *)(piVar9 + 3) = *(unsigned short *)((int)local_18 + 0x12);
          if ((param_5 & 1) == 0) {
            uVar3 = *(ushort *)(local_18 + 4) | 0x20;
          }
          else {
            uVar3 = (uint)*(ushort *)(local_18 + 4);
          }
          local_18 = (int *)local_18[1];
        }
        else {
          *(ushort *)(piVar9 + 3) = local_14[1];
          uVar3 = (uint)*local_14;
          if ((param_5 & 1) == 0) {
            uVar3 = *local_14 | 0x20;
          }
          local_14 = local_14 + 4;
        }
        piVar10 = piVar9;
        piVar11 = piVar8;
        for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar11 = *piVar10;
          piVar10 = piVar10 + 1;
          piVar11 = piVar11 + 1;
        }
        *(short *)(piVar9 + 7) = (short)piVar9[7] - param_7;
        *(short *)((int)piVar9 + 0x1e) = *(short *)((int)piVar9 + 0x1e) - param_8;
        if ((short)uVar3 == DAT_004a2b20) {
          *DAT_004a2b18 = (int)piVar9;
          DAT_004a2b18 = piVar9;
          *DAT_004a2b14 = (int)piVar8;
        }
        else {
          piVar11 = DAT_004a2ae4 + 6;
          piVar10 = DAT_004a2ae4;
          DAT_004a2ae4 = piVar11;
          if (DAT_004a2adc < piVar11) {
            piVar10 = DAT_004a2ae0;
            DAT_004a2ae4 = DAT_004a2ae0 + 6;
          }
          DAT_004a2b20 = (short)uVar3;
          FUN_00445350((int)piVar10,0,1,uVar3);
          *piVar10 = (int)piVar9;
          *DAT_004a2b18 = (int)piVar10;
          piVar11 = piVar10 + 3;
          DAT_004a2b18 = piVar9;
          *piVar11 = *piVar10;
          piVar10[4] = piVar10[1];
          piVar10[5] = piVar10[2];
          *piVar11 = (int)piVar8;
          *DAT_004a2b14 = (int)piVar11;
        }
        DAT_004a2b14 = piVar8;
        psVar7 = psVar7 + 4;
      } while (*psVar7 != 0);
      return;
    }
  }
  else {
    local_c = (local_c & 0x00ffffff) |
              ((((-((param_5 & 0x8080) == 0) & 0xfeU) + 0x2e) & 0xff) << 24);
    if (*psVar7 != 0) {
      do {
        piVar8 = DAT_004a2ae4 + 0x14;
        piVar9 = DAT_004a2ae4;
        DAT_004a2ae4 = piVar8;
        if (DAT_004a2adc < piVar8) {
          piVar9 = DAT_004a2ae0;
          DAT_004a2ae4 = DAT_004a2ae0 + 0x14;
        }
        local_21 = *(byte *)(psVar7 + 1);
        local_20 = *(byte *)((int)psVar7 + 3);
        piVar9[1] = local_c;
        *(unsigned short *)((int)piVar9 + 0xe) = local_1e;
        if (bVar4 == 0) {
          if ((param_5 & 1) == 0) {
            *(ushort *)((int)piVar9 + 0x16) = *(ushort *)(local_18 + 4) | 0x20;
          }
          else {
            *(short *)((int)piVar9 + 0x16) = (short)local_18[4];
          }
          local_1c = *(byte *)((int)local_18 + 0x12);
          local_1f = *(byte *)((int)local_18 + 0x13);
          local_18 = (int *)local_18[1];
        }
        else {
          if ((param_5 & 1) == 0) {
            uVar1 = *local_14 | 0x20;
          }
          else {
            uVar1 = *local_14;
          }
          *(ushort *)((int)piVar9 + 0x16) = uVar1;
          local_1f = *(byte *)((int)local_14 + 3);
          local_1c = (byte)local_14[1];
          local_14 = local_14 + 4;
        }
        if ((param_6 & 0x80000000) == 0) {
          *(short *)(piVar9 + 2) = psVar7[2] + param_2;
          *(short *)((int)piVar9 + 10) = param_3 - psVar7[3];
          *(ushort *)(piVar9 + 4) = psVar7[2] + (ushort)local_21 + param_2;
          *(short *)((int)piVar9 + 0x12) = param_3 - psVar7[3];
          *(short *)(piVar9 + 6) = psVar7[2] + param_2;
          *(ushort *)((int)piVar9 + 0x1a) = (param_3 - psVar7[3]) - (ushort)local_20;
          *(ushort *)(piVar9 + 8) = psVar7[2] + (ushort)local_21 + param_2;
          *(ushort *)((int)piVar9 + 0x22) = (param_3 - psVar7[3]) - (ushort)local_20;
          if (local_1f == 0) {
            local_20 = local_20 - 1;
          }
          else {
            local_1f = local_1f - 1;
          }
          if ((uint)local_1c + (uint)local_21 == 0x100) {
FUN_0043E207:
            local_21 = local_21 - 1;
          }
        }
        else {
          if ((param_6 & 0x40000000) == 0) {
            *(short *)(piVar9 + 2) = param_2 - psVar7[2];
            *(short *)((int)piVar9 + 10) = psVar7[3] + param_3;
            *(ushort *)(piVar9 + 4) = (param_2 - psVar7[2]) - (ushort)local_21;
            *(short *)((int)piVar9 + 0x12) = psVar7[3] + param_3;
            *(short *)(piVar9 + 6) = param_2 - psVar7[2];
            *(ushort *)((int)piVar9 + 0x1a) = psVar7[3] + (ushort)local_20 + param_3;
            *(ushort *)(piVar9 + 8) = (param_2 - psVar7[2]) - (ushort)local_21;
            *(ushort *)((int)piVar9 + 0x22) = psVar7[3] + (ushort)local_20 + param_3;
            if ((uint)local_1f + (uint)local_20 == 0x100) goto FUN_0043E123;
          }
          else {
            *(short *)(piVar9 + 2) = param_2 - psVar7[2];
            *(short *)((int)piVar9 + 10) = param_3 - psVar7[3];
            *(ushort *)(piVar9 + 4) = (param_2 - psVar7[2]) - (ushort)local_21;
            *(short *)((int)piVar9 + 0x12) = param_3 - psVar7[3];
            *(short *)(piVar9 + 6) = param_2 - psVar7[2];
            *(ushort *)((int)piVar9 + 0x1a) = (param_3 - psVar7[3]) - (ushort)local_20;
            *(ushort *)(piVar9 + 8) = (param_2 - psVar7[2]) - (ushort)local_21;
            *(ushort *)((int)piVar9 + 0x22) = (param_3 - psVar7[3]) - (ushort)local_20;
            if (local_1f == 0) {
FUN_0043E123:
              local_20 = local_20 - 1;
            }
            else {
              local_1f = local_1f - 1;
            }
          }
          if (local_1c == 0) {
            if (bVar6 != 1) goto FUN_0043E207;
            *(short *)((int)piVar9 + 0x16) = *(short *)((int)piVar9 + 0x16) + -1;
            local_1c = 0x7f;
          }
          else {
            local_1c = local_1c - 1;
          }
        }
        *(byte *)(piVar9 + 3) = local_1c;
        *(byte *)((int)piVar9 + 0xd) = local_1f;
        *(byte *)(piVar9 + 5) = local_21 + local_1c;
        *(byte *)((int)piVar9 + 0x15) = local_1f;
        *(byte *)(piVar9 + 7) = local_1c;
        piVar8 = piVar9 + 10;
        *(byte *)((int)piVar9 + 0x1d) = local_20 + local_1f;
        *(byte *)(piVar9 + 9) = local_21 + local_1c;
        *(byte *)((int)piVar9 + 0x25) = local_20 + local_1f;
        *DAT_004a2b18 = (int)piVar9;
        piVar10 = piVar9;
        piVar11 = piVar8;
        DAT_004a2b18 = piVar9;
        for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar11 = *piVar10;
          piVar10 = piVar10 + 1;
          piVar11 = piVar11 + 1;
        }
        if (param_7 != 0) {
          *(short *)(piVar9 + 0xc) = (short)piVar9[0xc] - param_7;
          *(short *)(piVar9 + 0xe) = (short)piVar9[0xe] - param_7;
          *(short *)(piVar9 + 0x10) = (short)piVar9[0x10] - param_7;
          *(short *)(piVar9 + 0x12) = (short)piVar9[0x12] - param_7;
        }
        if (param_8 != 0) {
          *(short *)((int)piVar9 + 0x32) = *(short *)((int)piVar9 + 0x32) - param_8;
          *(short *)((int)piVar9 + 0x3a) = *(short *)((int)piVar9 + 0x3a) - param_8;
          *(short *)((int)piVar9 + 0x42) = *(short *)((int)piVar9 + 0x42) - param_8;
          *(short *)((int)piVar9 + 0x4a) = *(short *)((int)piVar9 + 0x4a) - param_8;
        }
        psVar7 = psVar7 + 4;
        *DAT_004a2b14 = (int)piVar8;
        DAT_004a2b20 = *(short *)((int)piVar9 + 0x3e);
        DAT_004a2b14 = piVar8;
      } while (*psVar7 != 0);
    }
  }
  return;
}

}
