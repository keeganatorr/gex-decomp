extern "C" {
extern int FUN_004A27B0;
extern int FUN_004A27A4;
extern int FUN_004A28A0;
extern int FUN_0045CA38;
extern int FUN_004A2934;
extern int FUN_004A2A78;
extern char s_Error__Object_type__ld_has_too_h_00458ee0[];
void *__cdecl memset(void *, int, unsigned int);
void *__cdecl FUN_0042CC20(int *);
void __cdecl FUN_0042CC00(int *, int);
void __cdecl FUN_00405350(char *, int, int);
void __cdecl FUN_0041E7E0(int *, int *, int *, int *);
void __cdecl FUN_0040F2E0(int *, int);
int __cdecl FUN_0041E190(void **, void *);

void __cdecl GEX_Target(int *objectType, int *param_2)
{
    int *loaded_gOb;
    unsigned int uVar6;
    unsigned int priority;
    int pGVar2;
    int pGVar5;
    int *puVar4;
    int *objectType_00;
    int *fields;
    int *tracker;
    int *obs_entry;

    loaded_gOb = (int *)FUN_0042CC20(&FUN_004A27B0);
    if (loaded_gOb != 0) {
        memset(loaded_gOb, 0, 0x204);
        priority = ((objectType[2] & 0xf000000) >> 0x18) + 1;
        if (priority >= 9) {
            FUN_00405350(s_Error__Object_type__ld_has_too_h_00458ee0, objectType[1] & 0x3fff, (int)priority);
            FUN_0042CC00(&FUN_004A27B0, (int)loaded_gOb);
            FUN_004A27A4 = FUN_004A27A4 - 1;
            return;
        }
        FUN_0042CC00(&FUN_004A28A0 + priority * 3, (int)loaded_gOb);
        pGVar2 = objectType[1] & 0x3fff;
        loaded_gOb[2] = pGVar2;
        obs_entry = &FUN_0045CA38 + pGVar2 * 6;
        uVar6 = objectType[2] & 0xffff;
        if (uVar6 != 0) {
            loaded_gOb[3] = *(int *)(FUN_004A2934 + uVar6 * 8 - 8);
        }
        loaded_gOb[0x1e] = objectType[0] & 0xffff0000;
        loaded_gOb[0x1f] = (unsigned int)objectType[0] << 0x10;
        loaded_gOb[0x35] = loaded_gOb[0x1e];
        loaded_gOb[0x36] = loaded_gOb[0x1f];
        loaded_gOb[0x37] = 0x7fffffff;
        pGVar5 = (obs_entry[5] & 0xfffffff0) | priority;
        loaded_gOb[0x1b] = pGVar5;
        loaded_gOb[0x1b] = (objectType[2] & 0xc0000000) | pGVar5;
        loaded_gOb[0x32] = 0x10000;
        loaded_gOb[0x33] = 0x10000;
        loaded_gOb[0x34] = param_2[0x0e];
        loaded_gOb[0x16] = obs_entry[0];
        loaded_gOb[0x19] = obs_entry[3];
        loaded_gOb[0x17] = obs_entry[1];
        loaded_gOb[0x18] = obs_entry[2];
        loaded_gOb[99] = (int)objectType;
        loaded_gOb[100] = (int)param_2;
        objectType[1] = objectType[1] | 0x8000;
        FUN_0041E7E0(loaded_gOb,
            (int *)(((unsigned int)obs_entry[5] & 0xf0) >> 4),
            (int *)(((unsigned int)obs_entry[5] & 0xf00) >> 8),
            (int *)&FUN_0041E190);
        if (uVar6 != 0) {
            int *groupFields;
            int *groupValues;
            groupValues = (int *)*(int *)(FUN_004A2934 + uVar6 * 8 - 4);
            groupFields = loaded_gOb + 0x1a;
            while (*groupValues != 0) {
                groupFields[*groupValues & 0xffff] = groupValues[1];
                groupValues += 2;
            }
        }
        puVar4 = (int *)objectType[3];
        fields = loaded_gOb + 0x1a;
        while (*puVar4 != 0) {
            unsigned int fieldCode = *puVar4;
            pGVar2 = puVar4[1];
            if ((fieldCode & 0x10000000) != 0) {
                tracker = ((int **)FUN_004A2A78)[(unsigned int)pGVar2 >> 0x10];
                objectType_00 = (int *)(tracker[0] + ((unsigned int)pGVar2 & 0xffff) * 16);
                if ((objectType_00[1] & 0x8000) == 0) {
                    GEX_Target(objectType_00, tracker);
                }
            } else {
                fields[fieldCode & 0xffff] = pGVar2;
            }
            puVar4 += 2;
        }
        FUN_0040F2E0(loaded_gOb, 0);
        FUN_004A27A4 = FUN_004A27A4 + 1;
    }
}
}
