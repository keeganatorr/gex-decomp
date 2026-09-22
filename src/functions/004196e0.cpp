typedef unsigned int Word;

extern "C" {
extern Word GOB_FreeObjectsList_004a27b0[];
extern Word FirstObjectGroup_004a2934;
extern Word obs_0045ca38[][6];
extern Word ListType_ARRAY_004a28a0[][3];
extern int gNumObjects_004a27a4;

Word *__cdecl LST_RemTail_0042cc20(Word *);
void __cdecl LST_AddTail_0042cc00(Word *, Word *);
void __cdecl CLD_CheckCollisionNormal_0041e190();
void __cdecl CLD_AddObjectCollision_0041e7e0(Word *, Word, Word, void (__cdecl *)());
void __cdecl GOB_CallInit_0040f2e0(Word *, int);
void *__cdecl memset(void *, int, unsigned int);
}

extern "C" Word *__cdecl GEX_Target(int type, int x, int y, Word group)
{
    Word *object = LST_RemTail_0042cc20(GOB_FreeObjectsList_004a27b0);
    if (object) {
        int offset = (group & 0xffffU) * 8;
        Word groupBase = FirstObjectGroup_004a2934;
        Word groupData = *(Word *)(groupBase + (offset - 8));
        Word *definition = obs_0045ca38[type];
        Word list = (definition[5] & 15U) + 1;

        memset(object, 0, 0x204);
        LST_AddTail_0042cc00(ListType_ARRAY_004a28a0[list], object);

        object[3] = groupData;
        ((int *)object)[30] = x;
        ((int *)object)[31] = y;
        ((int *)object)[53] = x;
        ((int *)object)[54] = y;
        object[55] = 0x7fffffff;
        object[27] = (definition[5] & 0xfffffff0U) | list;
        object[2] = type;
        object[50] = 0x10000;
        object[51] = 0x10000;
        object[52] = 0xc00000;
        object[22] = definition[0];
        object[25] = definition[3];
        object[23] = definition[1];
        object[24] = definition[2];

        CLD_AddObjectCollision_0041e7e0(object,
            (definition[5] & 0xf0U) >> 4,
            (definition[5] & 0xf00U) >> 8,
            CLD_CheckCollisionNormal_0041e190);

        groupBase = FirstObjectGroup_004a2934;
        Word *patch = *(Word **)(groupBase + (offset - 4));
        Word *fields = object + 26;
        while (*patch != 0) {
            fields[patch[0] & 0xffffU] = patch[1];
            patch += 2;
        }

        GOB_CallInit_0040f2e0(object, 0);
        ++gNumObjects_004a27a4;
    }
    return object;
}
