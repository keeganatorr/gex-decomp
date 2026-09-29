typedef unsigned int Word;

extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
extern int decl_pad_1;
extern int decl_pad_2;
extern int decl_pad_3;
extern Word DAT_0045c988;
extern unsigned char DAT_004642e4;
void __cdecl RezInit_00436cf0(Word *);
void __cdecl FUN_0042e850(Word *);
void __cdecl FUN_00436cb0_Graphics_unk(Word *);
void __cdecl RezOutDraw2_00437010(Word *);

void __cdecl RezOutDraw_00437170(Word *object)
{
    Word originalX, originalY;
    Word *parent = (Word *)object[0x57];
    Word savedX, savedY, savedC8, savedCC;
    Word frame;
    Word image;

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
        object[0x1f] = parent[0x1f] + originalY + dy;
    }

    image = (&DAT_0045c988 - 10)[object[0x2e]];
    if (image) {
        if (object[0x38] & 0x40) {
            savedX = object[0x1e];
            savedY = object[0x1f];
            savedC8 = object[0x32];
            savedCC = object[0x33];
            FUN_0042e850(object);
        }
        frame = object[0x2e];
        object[0x2f] = *(&DAT_0045c988 - frame);
        object[0x2e] = frame + 1;
        object[0x30] = 0;
        FUN_00436cb0_Graphics_unk(object);
        object[0x2f] = image;
        object[0x30] = (Word)&DAT_004642e4;
        FUN_00436cb0_Graphics_unk(object);
        if (object[0x38] & 0x40) {
            object[0x1e] = savedX;
            object[0x1f] = savedY;
            object[0x32] = savedC8;
            object[0x33] = savedCC;
        }
    } else {
        object[0x2e] = 0;
        object[0x18] = (Word)RezOutDraw2_00437010;
        if (parent != 0) {
            object[0x1e] = originalX;
            object[0x1f] = originalY;
        }
        RezOutDraw2_00437010(object);
    }

    if (parent != 0) {
        object[0x1e] = originalX;
        object[0x1f] = originalY;
    }
}
}
