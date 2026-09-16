extern "C" void __cdecl GEX_Target(void* param_1)
{
    unsigned int* p = (unsigned int*)param_1;
    p[0x14] = 0x1D;
    p[0x34] = 0x00200000;
    p[0x37] = 0xFFF60000;
    p[0x28] = 2;
}