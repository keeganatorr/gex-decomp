// Adapted from pc_decomp_backup/src/functions/FUN_00434260.cpp
// Historical source SHA256: ab54a73b63bbd0978e7c0648ca80d5ce1309203a14c12c04cba2b16d4658b4cf
extern "C" {
extern "C" { extern int DAT_004a27fc; }
extern "C" { extern int DAT_004a2864; }
extern "C" { extern int DAT_004a2814; }
extern "C" { extern int DAT_004a2874; }

extern "C" void __cdecl FUN_00434260(void* param1) {
    int flags;
    int val_b4;
    int result;

    flags = *(int*)((char*)param1 + 0xa4);
    if (flags == 0) return;

    val_b4 = *(int*)((char*)param1 + 0xb4);

    if ((val_b4 & 0x10) != 0 && (val_b4 & 0x80000000) == 0) {
        if (flags == 0) return;
        if (DAT_004a27fc == 0) return;
        if (*(int*)((char*)&DAT_004a27fc + 0x110) == (int)param1) goto skip_global_check;
        if (DAT_004a2864 == (int)param1) goto skip_global_check;
        if (DAT_004a2814 == (int)param1) goto skip_global_check;
        if (DAT_004a2874 != (int)param1) return;
    }

skip_global_check:
    if (flags != 0 && (val_b4 & 0x800) != 0) {
        val_b4 |= 0x80000000;
        *(int*)((char*)param1 + 0xb4) = val_b4;
    }

    val_b4 = *(int*)((char*)param1 + 0xb4);
    if ((val_b4 & 4) == 0) {
        int xPos = *(int*)((char*)param1 + 0xa0);
        int yPos = *(int*)((char*)param1 + 0x9c);
        int newY = yPos + xPos;
        *(int*)((char*)param1 + 0x9c) = newY;
        int b0Val = *(int*)((char*)param1 + 0xb0);
        if (b0Val != 0 && b0Val <= newY) {
            *(int*)((char*)param1 + 0x9c) = newY;
        }
        newY = *(int*)((char*)param1 + 0x9c);
        if (newY < 0) {
            *(int*)((char*)param1 + 0x9c) = 0;
        }

        int acVal = *(int*)((char*)param1 + 0xac);
        int temp = acVal + newY;
        *(int*)((char*)param1 + 0xac) = temp;
        int shifted = temp >> 16;
        int a8Val = *(int*)((char*)param1 + 0xa8);
        int newBits = (shifted << 16) - temp;
        *(int*)((char*)param1 + 0xac) = newBits;

        if (newBits == 0) return;

        int signByte;
        val_b4 = *(int*)((char*)param1 + 0xb4);
        if ((val_b4 & 0x800) != 0) {
            char byteParam;
            if ((val_b4 & 0x8) != 0) {
                byteParam = *(char*)((char*)param1 + 0xa5);
                signByte = (signed char)byteParam;
            } else {
                byteParam = *(char*)((char*)param1 + 0xa5);
                signByte = (signed char)byteParam;
            }
        } else {
            
            signed short sVal = *(signed short*)((char*)param1 + 0xa4);
            int b6Val = *(int*)((char*)param1 + 0xb4);
            signed char byte1 = *(char*)((char*)param1 + 0xa5);
            signed char byte2 = *(char*)((char*)param1 + 0xa4);
            signByte = byte2 + byte1;
        }

        
        int b4Val = *(int*)((char*)param1 + 0xb4);
        if ((b4Val & 4) != 0) {
            
        }
    }
}
}
