typedef unsigned int uint;
struct GXObject;

extern "C" {
void __cdecl FUN_00419B80(GXObject **, uint);
void __cdecl FUN_00419BC0(GXObject **, GXObject **);
void __cdecl FUN_00422500_pStateUnk_Lash_Inner(GXObject **);
extern GXObject **PTR_004a2838;
extern unsigned char DAT_00400000;
}

extern "C" void __cdecl GEX_Target(GXObject ***param_1, GXObject **param_2)
{
    GXObject **ppGVar1;
    int iVar2;
    uint uVar3;

    FUN_00419B80(param_2, (uint)param_1[27] & 15U);
    FUN_00419BC0(param_2, (GXObject **)param_1);
    param_2[33] = (GXObject *)0x7fffffffU;
    param_2[36] = (GXObject *)0x7fffffffU;

    switch ((uint)param_1[28]) {
    default:
        uVar3 = (uint)param_1[27];
        uVar3 &= 0x80000000U;
        uVar3 >>= 8;
        param_2[49] = (GXObject *)uVar3;
        ppGVar1 = param_1[27];
        param_2[35] = 0;
        param_2[32] = (GXObject *)((((((uint)ppGVar1 & 0x80000000U) < 1U) ? 0xffffffffU : 0U) & 0xfffe0000U) + 0x10000U);
        FUN_00422500_pStateUnk_Lash_Inner(param_2);
        ((uint *)param_2)[32] += (uint)param_1[32];
        if (param_2 == PTR_004a2838) {
            param_2[37] = (GXObject *)0x14000U;
            return;
        }
        break;

    case 0x14:
    case 0x27:
        param_2[49] = (GXObject *)&DAT_00400000;
        param_2[32] = 0;
        param_2[35] = (GXObject *)0xffff0000U;
        FUN_00422500_pStateUnk_Lash_Inner(param_2);
        return;

    case 0x2f:
        ppGVar1 = param_1[49];
        param_2[49] = (GXObject *)((uint)(ppGVar1 + 0x100000) & 0x00ff0000U);
        iVar2 = ((int)((uint)ppGVar1 & 0xffc7ffffU)) >> 19;
        param_2[32] = *(GXObject **)(&DAT_00400000 + 0x5aa10 + iVar2);
        param_2[35] = *(GXObject **)(&DAT_00400000 + 0x5aa14 + iVar2);
        FUN_00422500_pStateUnk_Lash_Inner(param_2);
        return;

    case 0x3a:
        uVar3 = (uint)param_1[27];
        iVar2 = (int)param_1[49];
        iVar2 >>= 21;
        uVar3 &= 0x80000000U;
        uVar3 >>= 28;
        uVar3 |= (uint)iVar2;
        iVar2 = (int)(uVar3 * 12U);
        param_2[32] = *(GXObject **)(&DAT_00400000 + 0x5a890 + uVar3 * 12U);
        param_2[35] = *(GXObject **)(&DAT_00400000 + 0x5a894 + iVar2);
        param_2[49] = *(GXObject **)(&DAT_00400000 + 0x5a898 + iVar2);
        FUN_00422500_pStateUnk_Lash_Inner(param_2);
        return;

    case 0x3b:
        uVar3 = (uint)param_1[27];
        iVar2 = (int)param_1[49];
        iVar2 >>= 21;
        uVar3 &= 0x80000000U;
        uVar3 >>= 28;
        uVar3 |= (uint)iVar2;
        iVar2 = (int)(uVar3 * 12U);
        param_2[32] = *(GXObject **)(&DAT_00400000 + 0x5a950 + uVar3 * 12U);
        param_2[35] = *(GXObject **)(&DAT_00400000 + 0x5a954 + iVar2);
        param_2[49] = *(GXObject **)(&DAT_00400000 + 0x5a958 + iVar2);
        FUN_00422500_pStateUnk_Lash_Inner(param_2);
        break;
    }
}
