extern "C" int DAT_00455c54;
extern "C" void __cdecl FUN_00405390(const char*, ...);

struct Flags {
    unsigned int reserved : 8;
    unsigned int byteFlags : 8;
    unsigned int remaining : 16;
};

extern "C" int __cdecl GEX_Target(void* param_1)
{
    Flags* flags = (Flags*)((char*)param_1 + 0xe0);
    if ((flags->byteFlags & 0x80) != 0) {
        if (DAT_00455c54 > 1) {
            FUN_00405390((const char*)0x0045f088, *(int*)((char*)param_1 + 0x8));
            FUN_00405390((const char*)0x0045f1a8);
        }
        *(unsigned int*)((char*)param_1 + 0xe0) &= 0xffff7fff;
        return 1;
    }
    return 0;
}
