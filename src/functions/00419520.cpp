// Adapted from pc_decomp_backup/src/functions/FUN_00419520.cpp
// Historical source SHA256: 50c95282fd79ad09aa716a0dc9dcd52b6ee41af64e89bfe091a6f43230699543
extern "C" {
extern "C" { extern void* FUN_004A2888; }
extern "C" { extern void* FUN_004A2864; }
extern "C" { extern void* PTR_004a27f0; }
extern "C" { extern void* PTR_004a2874; }
extern "C" { extern void* PTR_004a2814; }
extern "C" { extern void* PTR_004a2838; }
extern "C" void __cdecl FUN_0040F2E0(void*, int);
extern "C" void __cdecl FUN_0041E7C0(void*);

extern "C" void __cdecl GEX_Target(void* gOb)
{
    do {
        if (((*(int*)gOb & 0x800000) != 0)) {
            FUN_0040F2E0(gOb, 1);
        }
        FUN_0041E7C0(gOb);
        if (FUN_004A2888 == gOb) FUN_004A2888 = 0;
        if (FUN_004A2864 == gOb) FUN_004A2864 = 0;
        if (PTR_004a27f0 == gOb) PTR_004a27f0 = 0;
        if (PTR_004a2874 == gOb) PTR_004a2874 = 0;
        if (PTR_004a2814 == gOb) PTR_004a2814 = 0;
        if (PTR_004a2838 == gOb) PTR_004a2838 = 0;
        *(int*)gOb |= 0x100000;
        if (*(void**)((char*)gOb + 0x160) != 0) {
            GEX_Target(*(void**)((char*)gOb + 0x160));
        }
        gOb = *(void**)((char*)gOb + 0x164);
    } while (gOb != 0);
}
}
