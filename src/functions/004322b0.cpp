extern "C" {
void __cdecl FUN_00431730(void**);
void** __cdecl FUN_0041A380(void**);
void __cdecl FUN_0041E7C0(void**);
void __cdecl FUN_004322a0();

void __cdecl FUN_004322b0(void** param1, int param2)
{
    if (param1[0x59]) FUN_004322b0((void**)param1[0x59], param2);
    if (param1[0x58]) FUN_004322b0((void**)param1[0x58], param2);
    FUN_00431730(param1);
    param1[0x17] = 0;
    param1[0x19] = 0;
    param1[0x26] = (void*)param2;
    param1[0x27] = 0;
    param1[0x18] = (void*)FUN_004322a0;
    param1[0x28] = 0;
    void** frame = FUN_0041A380(param1);
    int left, right, top, bottom;
    right = (unsigned int)param1[0x1b] & 0x80000000;
    bottom = (unsigned int)param1[0x1b] & 0x40000000;
    left = right ? -(int)frame[2] : (int)frame[0];
    right = right ? -(int)frame[0] : (int)frame[2];
    top = bottom ? -(int)frame[3] : (int)frame[1];
    bottom = bottom ? -(int)frame[1] : (int)frame[3];
    right = (right - left + 1) >> 1;
    bottom = (bottom - top + 1) >> 1;
    param1[0x2a] = (void*)(left + right);
    param1[0x2b] = (void*)(top + bottom);
    param1[0x2c] = (void*)right;
    param1[0x2d] = (void*)bottom;
    FUN_0041E7C0(param1);
}
}
