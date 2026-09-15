extern "C" int DAT_00462270;
extern "C" void* _nh_malloc(unsigned int, int);

extern "C" void* GEX_Target(unsigned int _Size)
{
    return _nh_malloc(_Size, DAT_00462270);
}
