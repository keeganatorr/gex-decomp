extern "C" {
extern int FUN_004A2990;
int __cdecl FUN_00421560_DrawCharacter(int, void**);
void __cdecl FUN_00420920_ypos(void** p, int p2) {
    if (!FUN_00421560_DrawCharacter(FUN_004A2990, p)) {
        p[0x1f] = (void*)((char*)p[0x1f] + ((*(unsigned int*)(p2 + 0x24) & 0x1fffff) + 0x10000));
    }
}
}