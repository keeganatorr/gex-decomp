// Adapted from pc_decomp_backup/src/functions/FUN_004017D0.cpp
// Historical source SHA256: 4c9fad2a1600b6367c4116fc09b80c2d58775f1703e8a1ee45e71aaca40a7800
extern "C" {
extern "C" int __cdecl GEX_Target(void* buffer, unsigned int dwWriteCursor, int* readBytes, unsigned int dwWriteBytes)
{
    int hresult;
    int* lplpvAudioPtr1;
    unsigned int lpdwAudioBytes1;
    void* lplpvAudioPtr2;
    unsigned int lpdwAudioBytes2;
    int* piVar3;
    int* piVar5;
    unsigned int uVar2;
    int* puVar4;
    int* puVar6;
    int HVar1;

    hresult = (*(int(__cdecl**)(void*, unsigned int, unsigned int, int**, unsigned int*, void**, unsigned int*, unsigned int))(*(int**)buffer + 0))(buffer, dwWriteCursor, dwWriteBytes, &lplpvAudioPtr1, &lpdwAudioBytes1, &lplpvAudioPtr2, &lpdwAudioBytes2, 0);
    if (hresult == -0x7787ff6a) {
        (*(int(__cdecl**)(void*))(*(int**)buffer + 0x10))(buffer);
        hresult = (*(int(__cdecl**)(void*, unsigned int, unsigned int, int**, unsigned int*, void**, unsigned int*, unsigned int))(*(int**)buffer + 0))(buffer, dwWriteCursor, dwWriteBytes, &lplpvAudioPtr1, &lpdwAudioBytes1, &lplpvAudioPtr2, &lpdwAudioBytes2, 0);
    }
    if (hresult == 0) {
        piVar3 = readBytes;
        piVar5 = lplpvAudioPtr1;
        for (uVar2 = lpdwAudioBytes1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *piVar5 = *piVar3;
            piVar3 = piVar3 + 1;
            piVar5 = piVar5 + 1;
        }
        for (uVar2 = lpdwAudioBytes1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(char*)piVar5 = *(char*)piVar3;
            piVar3 = (int*)((int)piVar3 + 1);
            piVar5 = (int*)((int)piVar5 + 1);
        }
        if (lplpvAudioPtr2 != 0) {
            puVar4 = (int*)(lpdwAudioBytes1 + (int)readBytes);
            puVar6 = (int*)lplpvAudioPtr2;
            for (uVar2 = lpdwAudioBytes2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
                *puVar6 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar6 = puVar6 + 1;
            }
            for (uVar2 = lpdwAudioBytes2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
                *(char*)puVar6 = *(char*)puVar4;
                puVar4 = (int*)((int)puVar4 + 1);
                puVar6 = (int*)((int)puVar6 + 1);
            }
        }
        HVar1 = (*(int(__cdecl**)(void*, int*, unsigned int, void*, unsigned int))(*(int**)buffer + 0x14))(buffer, lplpvAudioPtr1, lpdwAudioBytes1, lplpvAudioPtr2, lpdwAudioBytes2);
        if (HVar1 == 0) {
            return 1;
        }
    }
    return 0;
}
}
