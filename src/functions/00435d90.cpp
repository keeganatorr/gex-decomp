// Reconstructed from the pinned 00435d90 body. Script bytes come from game
// assets; the dispatch table in image_data.s is rebound to source functions.
extern "C" {
extern int SCRIPT_Register_004642bc;
extern unsigned char SCRIPT_CF_004642b4;
extern unsigned char SCRIPT_OF_004642b8;
extern unsigned char SCRIPT_ZF_004642c0;
extern unsigned char SCRIPT_SF_004642c4;
extern int DAT_004642c8;
extern int SCRIPT_WorkRegister_0049fb90;
extern int *DAT_0049fb94;
extern void __cdecl SCRIPT_ExitScriptError_00436c90(char *);
extern char s_SPAWN_0045b984[];
extern int __cdecl GOB_AddObject_004195d0(int, int, int, int);
extern int __cdecl GOB_AddObjectByIndex_004196e0(int, int, int, int);
extern void __cdecl GOB_PutObjectInfrontOfObject_00419be0(int *, int *);
}
typedef unsigned char *(__cdecl *ScriptNative)(unsigned char *, int *);
static unsigned int u32(const unsigned char *p) {
    return (unsigned int)p[0] | ((unsigned int)p[1] << 8) |
           ((unsigned int)p[2] << 16) | ((unsigned int)p[3] << 24);
}
static short s16(const unsigned char *p) {
    return (short)((unsigned int)p[0] | ((unsigned int)p[1] << 8));
}
static void nz(int value) {
    SCRIPT_ZF_004642c0 = value == 0;
    SCRIPT_SF_004642c4 = value < 0;
}
static void cmp(unsigned int a, unsigned int b) {
    unsigned int neg = 0U - b;
    unsigned int r = a + neg;
    nz((int)r);
    SCRIPT_CF_004642b4 = a < neg;
    SCRIPT_OF_004642b8 = (~(a ^ neg) & (a ^ r) & 0x80000000U) != 0;
}
extern "C" unsigned char * __cdecl GOB_RunScript_00435d90(
    int *gob, int *state, unsigned char *script)
{
    if (state[1]) { --state[1]; return script; }
    for (int steps = 0; steps < 4096; ++steps) {
        unsigned int op = *script;
        if (!(op & 0x80)) {
            unsigned int x = script[0], y = script[1];
            gob[0x1e] += ((int)(x << 25)) >> 9;
            gob[0x1f] += ((int)(y << 25)) >> 9;
            script += 2;
            if (!(y & 0x80)) return script;
            continue;
        }
        unsigned char *next = script + 1;
        unsigned int value;
        int index;
        short offset;
        switch (op & 0x7f) {
        case 1: return 0;
        case 2: state[1] = *next; return next + 1;
        case 3:
            gob[0x14] = next[0]; gob[0x15] = next[1];
            return next + 2;
        case 4:
            gob[0x14] = next[0]; gob[0x15] = next[1];
            next += 2; break;
        case 5:
            offset = s16(next); next += offset; break;
        case 10:
            offset = s16(next); next += 2;
            ++state[2]; state[state[2] + 3] = (int)next;
            next += offset - 2; break;
        case 11: next = (unsigned char *)state[state[2] + 3]; --state[2]; break;
        case 12: --state[2]; break;
        case 13: {
            index = (unsigned short)s16(next);
            ScriptNative fn = ((ScriptNative *)0x00458cd0)[index];
            SCRIPT_WorkRegister_0049fb90 = SCRIPT_Register_004642bc;
            next = fn(next + 2, gob);
            SCRIPT_Register_004642bc = SCRIPT_WorkRegister_0049fb90;
            nz(SCRIPT_Register_004642bc);
            SCRIPT_CF_004642b4 = SCRIPT_OF_004642b8 = 0;
            break;
        }
        case 14:
            SCRIPT_ExitScriptError_00436c90(s_SPAWN_0045b984);
            break;
        case 15: case 16:
            gob[0x1e] = (unsigned short)s16(next) << 16;
            gob[0x1f] = (unsigned short)s16(next + 2) << 16;
            next += 4; break;
        case 17: {
            index = (unsigned short)s16(next);
            int parent = next[2]; next += 3;
            DAT_0049fb94 = gob;
            int *created = parent ?
                (int *)GOB_AddObjectByIndex_004196e0(
                    index, gob[0x1e], gob[0x1f], gob[parent + 0x1a]) :
                (int *)GOB_AddObject_004195d0(
                    index, gob[0x1e], gob[0x1f], gob[3]);
            if (created) { GOB_PutObjectInfrontOfObject_00419be0(created, gob); gob = created; }
            nz((int)created); SCRIPT_CF_004642b4 = SCRIPT_OF_004642b8 = 0;
            break;
        }
        case 19: ++next; break;
        case 20:
            SCRIPT_Register_004642bc = *((int **)0x0045b808)[*next++];
            nz(SCRIPT_Register_004642bc);
            SCRIPT_CF_004642b4 = SCRIPT_OF_004642b8 = 0; break;
        case 21:
            offset = s16(next); next += 2;
            SCRIPT_Register_004642bc = *(int *)(next + offset - 4);
            nz(SCRIPT_Register_004642bc);
            SCRIPT_CF_004642b4 = SCRIPT_OF_004642b8 = 0; break;
        case 22:
            offset = s16(next); next += 2;
            *(int *)(next + offset - 4) = SCRIPT_Register_004642bc; break;
        case 23:
            SCRIPT_Register_004642bc = gob[*next++ + 0x1a];
            nz(SCRIPT_Register_004642bc);
            SCRIPT_CF_004642b4 = SCRIPT_OF_004642b8 = 0; break;
        case 24: SCRIPT_Register_004642bc = (int)u32(next); next += 4; break;
        case 25:
            SCRIPT_Register_004642bc &= (int)u32(next);
            nz(SCRIPT_Register_004642bc); next += 4; break;
        case 26:
            SCRIPT_Register_004642bc |= (int)u32(next);
            nz(SCRIPT_Register_004642bc); next += 4; break;
        case 27: {
            unsigned int old = (unsigned int)SCRIPT_Register_004642bc;
            unsigned int rhs = u32(next), result = old + rhs;
            SCRIPT_Register_004642bc = (int)result; nz((int)result);
            SCRIPT_CF_004642b4 = result < old;
            SCRIPT_OF_004642b8 = (~(old ^ rhs) & (old ^ result) & 0x80000000U) != 0;
            next += 4; break;
        }
        case 28: {
            unsigned int old = (unsigned int)SCRIPT_Register_004642bc;
            unsigned int rhs = 0U - u32(next), result = old + rhs;
            SCRIPT_Register_004642bc = (int)result; nz((int)result);
            SCRIPT_CF_004642b4 = rhs > old;
            SCRIPT_OF_004642b8 = (~(old ^ rhs) & (old ^ result) & 0x80000000U) != 0;
            next += 4; break;
        }
        case 29:
            SCRIPT_Register_004642bc *= (int)u32(next);
            nz(SCRIPT_Register_004642bc); next += 4; break;
        case 30: cmp((unsigned int)SCRIPT_Register_004642bc, u32(next)); next += 4; break;
        case 31: case 32: case 33: case 34: case 35: case 36:
        case 49: case 50: case 51: case 52: case 53: case 54: {
            offset = s16(next); next += 2;
            int jump = 0;
            switch (op & 0x7f) {
            case 31: jump = SCRIPT_ZF_004642c0 != 0; break;
            case 32: jump = SCRIPT_ZF_004642c0 == 0; break;
            case 33: jump = SCRIPT_SF_004642c4 == 0; break;
            case 34: jump = SCRIPT_SF_004642c4 != 0; break;
            case 35: jump = SCRIPT_CF_004642b4 != 0; break;
            case 36: jump = SCRIPT_CF_004642b4 == 0; break;
            case 49: jump = !SCRIPT_ZF_004642c0 &&
                            SCRIPT_SF_004642c4 == SCRIPT_OF_004642b8; break;
            case 50: jump = SCRIPT_SF_004642c4 == SCRIPT_OF_004642b8; break;
            case 51: jump = SCRIPT_SF_004642c4 != SCRIPT_OF_004642b8; break;
            case 52: jump = SCRIPT_ZF_004642c0 ||
                            SCRIPT_SF_004642c4 != SCRIPT_OF_004642b8; break;
            case 53: jump = !SCRIPT_ZF_004642c0 && SCRIPT_CF_004642b4; break;
            case 54: jump = SCRIPT_ZF_004642c0 || !SCRIPT_CF_004642b4; break;
            }
            if (jump) next += offset - 2;
            break;
        }
        case 37:
            value = (unsigned int)gob[0x1b] & u32(next);
            nz((int)value); next += 4; break;
        case 38: *((int **)0x0045b808)[*next++] = SCRIPT_Register_004642bc; break;
        case 39: gob[*next++ + 0x1a] = SCRIPT_Register_004642bc; break;
        case 40: {
            unsigned int rhs = 0U - (unsigned int)SCRIPT_Register_004642bc;
            unsigned int lhs = u32(next), result = lhs + rhs;
            SCRIPT_Register_004642bc = (int)result; nz((int)result);
            SCRIPT_CF_004642b4 = lhs < rhs;
            SCRIPT_OF_004642b8 = (~(lhs ^ rhs) & (lhs ^ result) & 0x80000000U) != 0;
            next += 4; break;
        }
        case 41: ++gob[0x15]; return next;
        case 42: ++gob[0x15]; break;
        case 43:
            index = next[0]; offset = s16(next + 1); next += 3;
            gob[index * 8 + 4] = (int)(next + offset - 2); break;
        case 44:
            value = SCRIPT_Register_004642bc;
            SCRIPT_Register_004642bc = DAT_004642c8;
            DAT_004642c8 = value; break;
        case 45: cmp((unsigned int)SCRIPT_Register_004642bc,
                     (unsigned int)DAT_004642c8); break;
        case 55:
            SCRIPT_Register_004642bc ^= (int)u32(next);
            nz(SCRIPT_Register_004642bc); next += 4; break;
        case 56: next += (unsigned int)next[0] + 1; break;
        case 57: {
            for (int i = 0; i < 12; ++i) gob[0x65 + i * 2] = 0;
            break;
        }
        case 58:
            index = next[0]; value = next[1]; offset = s16(next + 2);
            next += 4; gob[0x65 + index * 2] = value;
            gob[0x66 + index * 2] = (int)(next + offset - 2); break;
        case 59: gob[0x65 + *next++ * 2] = 0; break;
        case 61: gob = DAT_0049fb94; break;
        default: break;
        }
        script = next;
        if (!script) return 0;
    }
    return script;
}
