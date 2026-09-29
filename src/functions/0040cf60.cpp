struct PlayerState {
    unsigned int words[0x1b];
    unsigned int flags;
};
extern "C" {
void __cdecl FUN_00419B80(void**, int);
void __cdecl FUN_004195D0(int, int, int, int);
extern int DAT_00456018_gex_Init_unk;
extern int FUN_004A2A7C;
extern int FUN_004A2994;
extern int DAT_004a2a04;
extern void* FUN_004A281C;
extern int CAMERA_YPos_004a2a1c;
extern int DAT_004561f8;
extern int CAMERA_XPos_004a2a38;
extern int DAT_00462c64;
extern int DAT_00462c60;
extern int DAT_00462c74;
extern int DAT_004561f4;
extern int DAT_00456208;
extern void* FUN_004A2AD4;
extern PlayerState* FUN_004A27FC;

void __cdecl ob256Init_0040cf60(void** gOb)
{
    DAT_00456018_gex_Init_unk = 1;
    FUN_004A2A7C = 1;
    FUN_004A2994 = 0;
    DAT_004a2a04 = 0;
    gOb[0x27] = 0;
    gOb[0x28] = 0;
    gOb[0x26] = (void*)1;
    gOb[0x29] = FUN_004A281C;
    gOb[0x1f] = (void*)(CAMERA_YPos_004a2a1c + DAT_004561f8 + 0x200000);
    gOb[0x1e] = (void*)(CAMERA_XPos_004a2a38 + 0xc60000);
    gOb[0x2c] = (void*)0x640000;
    gOb[0x15] = (void*)0xffffffff;
    gOb[0x2b] = 0;
    FUN_00419B80(gOb, 4);
    DAT_00462c64 = 0;
    DAT_00462c60 = 0x25;
    DAT_00462c74 = 9;
    gOb[0x2a] = 0;
    DAT_004561f4 = 0x1999;
    FUN_004195D0(1, 0x640000, DAT_00456208, (int)FUN_004A2AD4);
    FUN_004A27FC->flags |= 0x80000000u;
}
}
