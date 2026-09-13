// Adapted from pc_decomp_backup/src/functions/FUN_0040F520.cpp
// Historical source SHA256: 1ba796fcaa9e1ed8cd3bbc0a3299fe87b849500668aafc3ef5112ff28497f745
extern "C" {
extern "C" void __cdecl GEX_Target(int* param_1)
{
    if (param_1[3] > 1) { param_1[3]--; return; }
    do {
        unsigned char cmd = *(unsigned char*)param_1[2];
        param_1[2] = (int)((unsigned char*)param_1[2] + 1);
        if ((cmd & 0x80) == 0) {
            if (cmd == 1) {
                unsigned char* p = (unsigned char*)param_1[2];
                param_1[3] = p[0];
                param_1[4] = ((int)p[1] << 24) | ((int)p[2] << 16) | ((int)p[3] << 8) | p[4];
                param_1[2] = (int)(p + 5); return;
            }
            if (cmd == 2) {
                unsigned char* p = (unsigned char*)param_1[2];
                param_1[3] = p[0];
                param_1[5] = p[1];
                param_1[2] = (int)(p + 2); return;
            }
            if (cmd == 3) { param_1[0] = 0; return; }
        } else {
            int (*handler)(int) = ((int(**)(int))param_1[1])[cmd & 0x7f];
            param_1[2] = handler(param_1[2]);
        }
    } while (1);
}
}
