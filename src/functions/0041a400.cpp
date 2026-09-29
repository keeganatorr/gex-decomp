// Recovered from the pinned 0041a400 body. The previous translation used
// unrelated offsets inside GXLoadObject and treated its frame table as data.
extern "C" {
extern char DAT_00458FE8[];
extern char DAT_00459018[];
void __cdecl FUN_00405350(char *, int);

int __cdecl GOB_GetOldFrame_0041a400(int *object)
{
    int *load = reinterpret_cast<int *>(object[3]);
    if (load == 0)
        return 0;
    int index = object[0x3e]; // previous frame index at +0xf8
    int group = object[0x3d]; // previous frame group at +0xf4
    if (index < 0 || group < 0)
        return 0;
    if (load[2] != 0) {
        if (group >= load[3]) {
            FUN_00405350(DAT_00459018, object[2]);
            return 0;
        }
        if (index > reinterpret_cast<int *>(load[4])[group]) {
            FUN_00405350(DAT_00458FE8, object[2]);
            return 0;
        }
    }
    int **animations = reinterpret_cast<int **>(load[0]);
    int *frames = animations[group];
    int result = frames[index];
    return result ? result : frames[0];
}
}
