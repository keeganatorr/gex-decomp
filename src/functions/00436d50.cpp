typedef void (__cdecl *DrawProc)(int *);
typedef struct ObjectType { DrawProc init, doit, draw, clid, unk10, unk14; } ObjectType;

extern "C" {
// Unused declarations below are compiler-state padding, not recovered source:
// VC4 orders commutative operands/registers by internal symbol numbering,
// which the original headers set. They emit no code or relocations.
// See docs/knowledge/symbol-numbering.md.
extern int decl_pad_0;
void __cdecl RezInit_00436cf0(int *);
void __cdecl FUN_0042e850(int *);
void __cdecl FUN_00436cb0_Graphics_unk(int *);
extern int FUN_0045C960[];
extern int DAT_0045c988;
extern unsigned char DAT_004642e4;
extern ObjectType obs_0045ca38[];
}

extern "C" void __cdecl GEX_Target(int *obj)
{
    int oldX, oldY;
    int savedX, savedY, savedW, savedH;
    int *parent = (int *)obj[0x57];
    RezInit_00436cf0(obj);
    int sumX, sumY;
    if (parent) {
        sumX = 0;
        sumY = 0;
        oldX = obj[0x1e];
        oldY = obj[0x1f];
        while (parent[0x57]) {
            sumX += parent[0x1e];
            sumY += parent[0x1f];
            parent = (int *)parent[0x57];
        }
        obj[0x1e] = parent[0x1e] + sumX + oldX;
        obj[0x1f] = parent[0x1f] + sumY + oldY;
    }
    int resource = FUN_0045C960[obj[0x2e]];
    if (resource) {
        if (obj[0x38] & 0x40) {
            savedX = obj[0x1e];
            savedY = obj[0x1f];
            savedW = obj[0x32];
            savedH = obj[0x33];
            FUN_0042e850(obj);
        }
        obj[0x2f] = resource;
        obj[0x30] = 0;
        FUN_00436cb0_Graphics_unk(obj);
        resource = *(&DAT_0045c988 - obj[0x2e]);
        obj[0x30] = (int)&DAT_004642e4;
        obj[0x2f] = resource;
        FUN_00436cb0_Graphics_unk(obj);
        if (obj[0x38] & 0x40) {
            obj[0x1e] = savedX;
            obj[0x1f] = savedY;
            obj[0x32] = savedW;
            obj[0x33] = savedH;
        }
        ++obj[0x2e];
    } else {
        DrawProc draw = obs_0045ca38[obj[2]].draw;
        obj[0x2f] = 0;
        obj[0x30] = 0;
        obj[0x18] = (int)draw;
        obj[0x2e] = 0;
        draw(obj);
    }
    if (parent) {
        obj[0x1e] = oldX;
        obj[0x1f] = oldY;
    }
}
