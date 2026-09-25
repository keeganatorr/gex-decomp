extern "C" int* __cdecl GEX_Target(unsigned int param)
{
    int* entry = (int*)0x004A28A0;
    int* end = (int*)0x004A2918;
    unsigned int key = param;
    int* node;
    do {
        node = (int*)*entry;
        if (*node != 0) {
            do {
                if (node[2] == 0x10E && ((unsigned int)node[0x27] >> 16) == key) {
                    return node;
                }
                node = (int*)*node;
            } while (*node != 0);
        }
        entry += 3;
    } while (entry < end);
    return 0;
}
