extern "C" {
extern void *PTR_ARRAY_004a23e0[4];
extern void *PTR_ARRAY_004a2400[];
extern void *DAT_004A23F0;
extern void *DAT_004A2410;

extern char s_Unknown_Data_ID__ld_00459230[];
extern char s_ERROR_Breakable_tile_for_subID___00459248[];
extern char s_ERROR_SubID__ld_for_Breakable_ti_0045927c[];

void __cdecl FUN_00405350(char *, ...);
void __cdecl FUN_00405390(char *, ...);
void __cdecl FUN_00419520(void **);

inline void __cdecl GEX_Target(void **param_1)
{
    long dataID = (long)param_1[0x26];
    long subID;
    void **slot;

    switch (dataID) {
    case 1:
        subID = (long)param_1[0x27];
        if ((subID >= 0) && (subID < 4)) {
            slot = &PTR_ARRAY_004a23e0[subID];
            if (*slot != 0) {
                FUN_00405350(s_ERROR_Breakable_tile_for_subID___00459248, subID);
                FUN_00419520(param_1);
                return;
            }
            *slot = param_1[3];
            FUN_00419520(param_1);
            return;
        }
        FUN_00405350(s_ERROR_SubID__ld_for_Breakable_ti_0045927c, subID);
        FUN_00419520(param_1);
        return;

    case 2:
        DAT_004A2410 = param_1[3];
        FUN_00419520(param_1);
        return;

    case 3:
        DAT_004A23F0 = param_1[3];
        FUN_00419520(param_1);
        return;

    case 4:
        PTR_ARRAY_004a2400[(long)param_1[0x27]] = param_1[3];
        FUN_00419520(param_1);
        return;

    default:
        FUN_00405390(s_Unknown_Data_ID__ld_00459230, dataID);
        FUN_00419520(param_1);
        return;
    }
}

static void (__cdecl * volatile GEX_Target_reference)(void **) = GEX_Target;
}