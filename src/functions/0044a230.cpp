// Adapted from pc_decomp_backup/src/functions/FUN_0044A230.cpp
// Historical source SHA256: f26dcbd0de8cce65fc2b77a96f1ff79ce92d2ba2a47c9b430efd40ae94256d2f
extern "C" {
extern "C" int __cdecl FUN_0044CB50(void*, char*);
extern "C" int __cdecl FUN_0044CB90(void*, char*);

extern "C" void __cdecl FUN_0044a230_fpMathInnerInner(int param_1, void* param_2, char* param_3)
{
    int local_8[2];
    int local_c[1];

    if (param_1 != 0) {
        FUN_0044CB50(local_8, param_3);
        *(int*)param_2 = local_8[0];
        *(int*)((int)param_2 + 4) = local_8[1];
        return;
    }
    FUN_0044CB90(local_c, param_3);
    *(int*)param_2 = local_c[0];
}
}
