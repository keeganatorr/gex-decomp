extern "C" int * __cdecl GOB_FindWithWork0_0040c110(int, int);
extern "C" unsigned char BYTE_ARRAY_004a2540[];

extern "C" __declspec(dllexport) inline void __cdecl FUN_0042c0a0(int *param_1, int param_2, int *param_3)
{
    int *object;
    int candidate;
    int selected;
    int index;

    selected = 0;
    if (*(int *)(param_2 + 0x98) == (param_1[0x27] & 0xffff)) {
        param_1[0x27] = param_1[0x27] & 0xffff;
        return;
    }

    index = 0;
    do {
        switch (index) {
        case 0:
            candidate = *(int *)(param_2 + 0xa8);
            break;
        case 1:
            candidate = *(int *)(param_2 + 0xac);
            break;
        case 2:
            candidate = *(int *)(param_2 + 0xb0);
            break;
        case 3:
            candidate = *(int *)(param_2 + 0xb4);
            break;
        }

        if (candidate > 0) {
            object = GOB_FindWithWork0_0040c110(0xdd, candidate);
            if ((int)param_3 != object[0x27]) {
                object = GOB_FindWithWork0_0040c110(0xdc, object[0x27]);
                if ((object[0x29] & 0x200) == 0 ||
                    (BYTE_ARRAY_004a2540[object[0x27]] & 1) != 0) {
                    if (selected > 0) {
                        selected = 0;
                        goto finished;
                    }
                    selected = candidate;
                }
            }
        }

        index = index + 1;
    } while (index < 4);

finished:
    param_1[0x27] = (param_1[0x27] & 0xffff) | (selected << 16);
}
