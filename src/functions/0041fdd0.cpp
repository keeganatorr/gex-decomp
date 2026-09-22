extern "C" {

struct GXObject;
typedef struct GXObject GXObject;

typedef struct {
    unsigned int f0;
    GXObject *para;
    GXObject *index;
} ParaInfo;

extern ParaInfo ParaInfo_fake_ARRAY_00463a40[8];
extern int gLevelSelectSelectedIndex_00463aa0;
extern const char s_ERROR__To_many_parallaxs_in_one_l_0045a1ac[];

void GOB_SetObjectDisplayPriority_00419b80(GXObject **obj, unsigned int pri);
GXObject *PAR_LoadParallaxs_00420210(GXObject *idx, GXObject **out);
void assertfail_00405350(const char *msg);

void _GEX_Target(GXObject **param_1, int param_2);

}

void _GEX_Target(GXObject **param_1, int param_2)
{
    GXObject *pGVar1;
    ParaInfo *piVar2;
    int iVar3;
    int iStack_4;

    if (param_2 != 0)
        return;

    GOB_SetObjectDisplayPriority_00419b80(param_1, (unsigned int)param_1[0x27]);

    iVar3 = 0;
    piVar2 = ParaInfo_fake_ARRAY_00463a40;
    do {
        if (piVar2->f0 == 0) {
        lab_set_index:
            iStack_4 = iVar3;
        } else {
            if (piVar2->index == param_1[0x26]) {
                param_1[0x28] = piVar2->para;
                break;
            }
            if (piVar2->f0 == 0)
                goto lab_set_index;
        }
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + 1;
    } while (piVar2 < &ParaInfo_fake_ARRAY_00463a40[8]);

    if (7 < iVar3) {
        if (7 < iStack_4) {
            assertfail_00405350(s_ERROR__To_many_parallaxs_in_one_l_0045a1ac);
            return;
        }
        pGVar1 = PAR_LoadParallaxs_00420210(param_1[0x26], &param_1[0x29]);
        param_1[0x28] = pGVar1;
        ParaInfo_fake_ARRAY_00463a40[iStack_4].f0 = (unsigned int)param_1[0x29];
        ParaInfo_fake_ARRAY_00463a40[iStack_4].para = param_1[0x28];
        ParaInfo_fake_ARRAY_00463a40[iStack_4].index = param_1[0x26];
    }
}
