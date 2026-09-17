extern "C" void __cdecl FUN_00423760(void);
extern "C" void __cdecl FUN_00423350(void* p);
extern "C" void __cdecl FUN_00423200(void* p, void* q);
extern "C" void* PTR_004a2874;
extern "C" void* PTR_004a2814;

extern "C" void __cdecl GEX_Target(void* p)
{
    FUN_00423760();
    FUN_00423350(p);
    void* other = PTR_004a2874;
    if (other) {
        FUN_00423200(p, other);
    }
    other = PTR_004a2814;
    if (other) {
        FUN_00423200(p, other);
    }
}
