// Adapted from pc_decomp_backup/src/functions/FUN_00420190.cpp
// Historical source SHA256: 203e8629de8355f45554b99e0f7c9dd94317c2a646afb6e5a23246411e60c0c7
extern "C" {
extern "C" void* __cdecl FUN_0040B390(int, unsigned int);
extern "C" void* __cdecl FUN_0040EB70(int, unsigned int);

extern "C" void* __cdecl GEX_Target(int param_1, unsigned int param_2)
{
    unsigned char* parallax = (unsigned char*)FUN_0040B390(param_1, param_2);
    unsigned int* layers = (unsigned int*)(parallax + 0x18);

    while (*layers != 0) {
        unsigned char* layer = (unsigned char*)FUN_0040B390(param_1, *layers);
        *layers = (unsigned int)layer;

        unsigned int* objects = (unsigned int*)(layer + 0x30);
        while (*objects != 0) {
            unsigned char* object = (unsigned char*)FUN_0040B390(param_1, *objects);
            *objects = (unsigned int)object;
            *(unsigned int*)(object + 4) =
                (unsigned int)FUN_0040EB70(param_1, *(unsigned int*)(object + 4));
            ++objects;
        }

        ++layers;
    }
    return parallax;
}
}
