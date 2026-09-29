// Adapted from pc_decomp_backup/src/functions/FUN_00435D90.cpp
// Historical source SHA256: 7197874483f1ca6053b88ece0eabc7b944856252196606710f8d497f36f385fc
extern "C" {
extern "C" int __cdecl GOB_RunScript_00435d90(int* param_1, int* param_2, int* PointerToScript)
{
    
    
    
    if (param_2[1] != 0) {
        
        
        param_2[1] = 0;
        return (int)PointerToScript;
    }
    
    
    param_2[1] = 0;
    return (int)PointerToScript;
}
}
