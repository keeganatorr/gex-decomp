// Adapted from pc_decomp_backup/src/functions/FUN_0040D470.cpp
// Historical source SHA256: b604200596431f03eacee6371758e584236340558c4cff91f49de9d229afb3d6
extern "C" {
extern int DAT_004561fc;
extern int DAT_00456200;
extern int DAT_00456204;
extern unsigned int FUN_004A2660[];
extern unsigned short FUN_004577B0[];
extern unsigned int DAT_004a2678;

struct GXObject {
    int gob_node_nd_next;
    int gas_stack;
};

struct GXObjectScript {
    int gas_stack;
};

extern "C" void __cdecl FUN_00444590(GXObject **param_1);

extern "C" void __cdecl GEX_Target(GXObject **param_1)
{
    unsigned int uVar1;
    GXObject *pGVar2;
    int iVar3;
    unsigned int *puVar4;
    unsigned char local_20[24];
    GXObject *local_8;
    GXObject *local_4;

    iVar3 = 0;
    param_1[0x38] = (GXObject *)((unsigned int)param_1[0x38] | 0x1000000);
    local_8 = param_1[0x1e];
    local_4 = param_1[0x1f];
    local_20[0] = 0;
    local_20[1] = 0;
    local_20[3] = 2;
    local_20[4] = 8;
    local_20[5] = 0xe;
    local_20[6] = 1;
    local_20[7] = 7;
    local_20[8] = 0xd;
    local_20[9] = 4;
    local_20[10] = 10;
    local_20[0xb] = 0x10;
    local_20[0xc] = 5;
    local_20[0xd] = 0xb;
    local_20[0xe] = 0x11;
    local_20[2] = 0;
    local_20[0x12] = 0;
    local_20[0xf] = 3;
    local_20[0x10] = 9;
    local_20[0x11] = 0xf;
    puVar4 = &FUN_004A2660[0];
    local_20[0x13] = 6;
    local_20[0x14] = 0xc;
    param_1[0x1e] = (GXObject *)&DAT_004561fc;
    param_1[0x1f] = (GXObject *)&DAT_00456200;
    do {
        uVar1 = *puVar4;
        if ((uVar1 != 4) && (uVar1 != 3)) {
            param_1[0x15] =
                (GXObject *)
                (((int)param_1[0x2b]->gas_stack + iVar3 + -0x1c) % 0x26 +
                (unsigned int)local_20[((*(unsigned short *)(&FUN_004577B0[0] + ((uVar1 & 0xffff00) >> 8) * 8) & 0xf) * 3
                                         + ((uVar1 & 0xf000000) >> 0x18))] * 0x26);
            FUN_00444590(param_1);
            param_1[0x1e] =
                (GXObject *)((int)param_1[0x1e]->gas_stack + DAT_00456204 + -0x1c);
        }
        puVar4 = puVar4 + 1;
        iVar3 = iVar3 + 1;
    } while ((unsigned int*)puVar4 < (unsigned int*)&DAT_004a2678);
    param_1[0x15] = (GXObject *)0xffffffff;
    pGVar2 = (GXObject *)((int)&(param_1[0x2b]->gob_node_nd_next) + 1);
    param_1[0x2b] = pGVar2;
    if (0x25 < (int)pGVar2) {
        param_1[0x2b] = (GXObject *)0x0;
    }
    param_1[0x1e] = local_8;
    param_1[0x1f] = local_4;
}
}
