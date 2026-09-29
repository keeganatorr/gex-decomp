extern "C" {
extern "C" void* __cdecl FUN_0040B390(int, unsigned int);
extern "C" void* __cdecl FUN_0040EB70(int, unsigned int);

extern "C" void* __cdecl PAR_ResolveParallax_00420190(int param_1, unsigned int param_2)
{
    unsigned char* parallax = (unsigned char*)FUN_0040B390(param_1, param_2);
    unsigned int* layers = (unsigned int*)(parallax + 0x18);

    while (*layers != 0) {
        unsigned char* layer = (unsigned char*)FUN_0040B390(param_1, *layers);
        *layers = (unsigned int)layer;

        unsigned int* objects = (unsigned int*)(layer + 0x30);
        while (*objects != 0) {
            unsigned int old = *objects++;
            unsigned char* object = (unsigned char*)FUN_0040B390(param_1, old);
            unsigned int* field = (unsigned int*)(object + 4);
            objects[-1] = (unsigned int)object;
            *field = (unsigned int)FUN_0040EB70(param_1, *field);
        }

        ++layers;
    }
    return parallax;
}
}
