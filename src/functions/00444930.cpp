// Adapted from pc_decomp_backup/src/functions/FUN_00444930.cpp
// Historical source SHA256: 23d4632949594b9e418357030673ff5aff2d8ec9b5c0153a49acac3d4d00afa9
extern "C" {
extern "C" void* __cdecl FUN_00444BF0(unsigned int, unsigned short*, int);

extern "C" void __cdecl GEX_Target(char* textBuffer, char* text, char** param_3)
{
    int local_18 = 0;
    int iVar7 = 0;
    char cVar1 = *text;

    do {
        if (cVar1 == 0) {
            textBuffer[local_18] = 0;
            return;
        }
        
        if (text[iVar7] == '%') {
            char cVar2;
            int iVar8 = iVar7 + 1;
            cVar1 = text[iVar8];
            
            if (cVar1 == '-') iVar8 = iVar7 + 2;
            cVar2 = text[iVar8];
            if (cVar2 == '0') iVar8 = iVar8 + 1;
            
            char local_19 = 0;
            char cVar4 = text[iVar8];
            
            while (cVar4 > '/' && text[iVar8] < ':') {
                cVar4 = text[iVar8 + 1];
                local_19 = text[iVar8] - 0x30 + local_19 * 10;
                iVar8 = iVar8 + 1;
            }
            
            while (1) {
                cVar4 = text[iVar8];
                if (cVar4 != 'N' && cVar4 != 'F' && cVar4 != 'h' && cVar4 != 'l' && cVar4 != 'L') break;
                iVar8 = iVar8 + 1;
            }
            
            cVar4 = text[iVar8];
            char* pcVar3;
            
            if (cVar4 == 'c') {
                char local_10;
                local_10 = *(char*)*param_3;
                pcVar3 = &local_10;
            } else if (cVar4 == 's') {
                pcVar3 = *(char**)(param_3);
            } else {
                int uVar5 = (cVar4 == 'x') ? 0x10 : 10;
                unsigned short local_10_short[1];
                pcVar3 = (char*)FUN_00444BF0((unsigned int)*param_3, local_10_short, uVar5);
            }
            
            param_3 = param_3 + 1;
            iVar7 = iVar8 + 1;
            
            
            int len = 0;
            char* p = pcVar3;
            while (*p) { p++; len++; }
            
            if (local_19 == 0) {
                char* src = pcVar3;
                char* dst = textBuffer + local_18;
                { int _i; for (_i = 0; _i < len; _i++) dst[_i] = src[_i]; }
                local_18 += len;
            } else if (len < (unsigned char)local_19) {
                char padChar = 0x30;
                int pad = (unsigned char)local_19 - len;
                { int _i; 
                if (cVar1 == '-') {
                    char* src = pcVar3;
                    char* dst = textBuffer + local_18;
                    for (_i = 0; _i < len; _i++) dst[_i] = src[_i];
                    local_18 += len;
                    dst = textBuffer + local_18;
                    for (_i = 0; _i < pad; _i++) dst[_i] = padChar;
                    local_18 += pad;
                } else {
                    char* dst = textBuffer + local_18;
                    for (_i = 0; _i < pad; _i++) dst[_i] = padChar;
                    local_18 += pad;
                    char* src = pcVar3;
                    dst = textBuffer + local_18;
                    for (_i = 0; _i < len; _i++) dst[_i] = src[_i];
                    local_18 += len;
                }
                }
            } else {
                char* src = pcVar3;
                char* dst = textBuffer + local_18;
                { int _i; for (_i = 0; _i < len; _i++) dst[_i] = src[_i]; }
                local_18 += len;
            }
        } else {
            textBuffer[local_18] = text[iVar7];
            local_18++;
            iVar7++;
        }
        cVar1 = text[iVar7];
    } while (1);
}
}
