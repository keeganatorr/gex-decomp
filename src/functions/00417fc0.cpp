extern "C" int GOB_GetHotSpot_00419c00(int* obj, unsigned int a, unsigned int b, int* o1, int* o2);

extern "C" unsigned char* SCRIPT_MoveToHotSpot_00417fc0(unsigned char* p, int* obj)
{
    int dx;
    int dy;
    unsigned int a = *p++;
    unsigned int b = *p++;
    if (GOB_GetHotSpot_00419c00(obj, a, b, &dx, &dy)) {
        obj[0x1e] += dx;
        obj[0x7e] = obj[0x1e];
        obj[0x1f] += dy;
        obj[0x7f] = obj[0x1f];
    }
    return p;
}
