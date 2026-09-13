// Adapted from pc_decomp_backup/src/functions/FUN_0041F710.cpp
// Historical source SHA256: b6250bf62246a141513f563cd4282a6930a8a2635c75334ae879c8cee67461d4
extern "C" {
extern "C" void __cdecl GEX_Target(void* param_1)
{
    int* animation = *(int**)((char*)param_1 + 0x1c);
    while (animation[0] != 0) {
        int timer = animation[3] + animation[4];
        animation[3] = timer;
        if (timer > 0x10000) {
            animation[3] = timer - 0x10000;
            int frameIndex = animation[2] + 1;
            animation[2] = frameIndex;

            
            
            
            
            int* frame = (int*)(animation[0] + frameIndex * 0x10);
            if (*(short*)frame == -1) {
                animation[2] = 0;
                frame = (int*)animation[0];
            }

            unsigned int blockId = (unsigned int)animation[1];
            int tileData = *(int*)((char*)param_1 + 0x14);
            int group = *(int*)(tileData + ((blockId & 0xffffffe7U) >> 3));
            int* destination = (int*)(group + (blockId & 0x1fU) * 0x10);
            destination[0] = frame[0];
            destination[1] = frame[1];
            destination[2] = frame[2];
            destination[3] = frame[3];
        }
        animation += 5;
    }
}
}
