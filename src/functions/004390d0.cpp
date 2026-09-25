extern "C" {
extern "C" void __cdecl FUN_00438470_MoveGuillotine(void*, int);

extern "C" void __cdecl GEX_Target(int* p)
{
    int a = p[0x25];
    int b = p[0x23];
    int sum = b + a;
    int bound = p[0x24];
    p[0x23] = sum;
    if (sum > bound) {
        p[0x23] = bound;
    } else if (sum < -bound) {
        p[0x23] = -bound;
    }
    FUN_00438470_MoveGuillotine(p, p[0x23]);
}
}