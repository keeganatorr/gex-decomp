extern "C" int DAT_004a27d4;

typedef void (__cdecl *ObjectCallback)(int*, int*);

extern "C" void __cdecl GEX_Target(int* objectSet)
{
    int index = 0;
    int* object = (int*)objectSet[0];
    DAT_004a27d4 = 1;

    if (objectSet[2] > 0) {
        do {
            if ((object[1] & 0x4000) != 0) {
                ((ObjectCallback)objectSet[1])(object, objectSet);
            }
            object += 4;
            ++index;
        } while (objectSet[2] > index);
    }

    DAT_004a27d4 = 0;
}
