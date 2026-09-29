// Adapted from pc_decomp_backup/src/functions/FUN_00445140.cpp
// Historical source SHA256: 3b5bdb522452583d81ec04b8f5b5a81f696a20744c0f2acf91520be666327894
extern "C" {
extern "C" void __cdecl FUN_00444DC0(void*);

extern "C" void __cdecl FUN_00445140_InnerGraphics(void* first)
{
    unsigned int command = (unsigned int)first;
    while ((command & 0x00FFFFFF) != 0x00FFFFFF) {
        FUN_00444DC0((void*)command);
        command = *(unsigned int*)command;
    }
}
}
