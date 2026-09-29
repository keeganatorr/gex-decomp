extern "C" {
extern "C" int __cdecl FUN_00423910(void**);
extern "C" int __cdecl FUN_00423960(void**);
extern "C" int __cdecl FUN_004239B0(void**);
extern "C" int __cdecl FUN_00423A00(void**);

int __cdecl FUN_00423a50_AirToFaceCrawl(void** param_1)
{
    if (FUN_00423910(param_1) && FUN_00423960(param_1) && FUN_004239B0(param_1) && FUN_00423A00(param_1))
        return 1;
    return 0;
}
}
