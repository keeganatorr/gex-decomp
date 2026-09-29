typedef unsigned int Word;

extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern "C" int decl_pad_0;
extern "C" int decl_pad_1;
extern "C" int decl_pad_2;
extern Word DAT_0045c988;
extern unsigned char DAT_004642e4;
void __cdecl RezInit_00436cf0(Word *);
void __cdecl FUN_0042e850(Word *);
void __cdecl FUN_00436cb0_Graphics_unk(Word *);
void __cdecl GOB_Remove_00419a80(Word *);

void __cdecl RezOutDraw2_00437010(Word *object)
{
    Word originalX, originalY;
    Word *parent = (Word *)object[0x57];
    Word savedX, savedY, savedC8, savedCC;

    RezInit_00436cf0(object);
    Word dx = 0;
    if (parent != 0) {
        Word dy = 0;
        originalX = object[0x1e];
        originalY = object[0x1f];
        while (parent[0x57] != 0) {
            dx += parent[0x1e];
            dy += parent[0x1f];
            parent = (Word *)parent[0x57];
        }
        object[0x1e] = parent[0x1e] + originalX + dx;
        object[0x1f] = (Word)((int)(parent[0x1f] + dy) + (int)originalY);
    }

    Word frame = object[0x2e];
    if (frame <= 10) {
        object[0x2f] = *(&DAT_0045c988 - frame);
        object[0x2e] = frame + 1;
        object[0x30] = (Word)&DAT_004642e4;
        if (object[0x38] & 0x40) {
            savedX = object[0x1e];
            savedY = object[0x1f];
            savedC8 = object[0x32];
            savedCC = object[0x33];
            FUN_0042e850(object);
        }
        FUN_00436cb0_Graphics_unk(object);
        if (object[0x38] & 0x40) {
            object[0x1e] = savedX;
            object[0x1f] = savedY;
            object[0x32] = savedC8;
            object[0x33] = savedCC;
        }
    } else {
        object[0x2e] = 0;
        object[0x2f] = 0;
        object[0x30] = 0;
        object[0x18] = (&DAT_0045c988 + 46)[object[2] * 6];
        if ((object[0x38] & 0x10) == 0)
            GOB_Remove_00419a80(object);
    }

    if (parent != 0) {
        object[0x1e] = originalX;
        object[0x1f] = originalY;
    }
}
}
