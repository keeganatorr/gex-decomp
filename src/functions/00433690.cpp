typedef struct Event {
    int eventNumber;
    void *eventToCall;
} Event;

typedef struct GXObject GXObject;
struct GXObject {
    char pad0[8];
    int type;
    char pad0c[0x60];
    unsigned int flags;
    char pad70[0x48];
    int flashTime;
    char padbc[0x24];
    unsigned int flags2;
    char pade4[0x8c];
    unsigned int *attack;
    unsigned int *defend;
    GXObject *other;
    char pad17c[0x18];
    Event events[12];
};

extern "C" {
void __cdecl SCRIPT_DoEvent_00433590(GXObject *obj, void *script, void *eventToCall, int eventNumber);
void __cdecl PlayerDamage_00417b70(GXObject *obj);
void __cdecl TracePrintf_Debug_00405390(char *, ...);
extern char gScriptEventDebug_00464278;
extern int DAT_004a023c_PowerUp_Invincibility;
extern int DAT_00455c54_DebugVar;
extern int *gEventLastCollideInfo_0045b570;
extern char s_Damage_To_GEX_0045b140[];
}

extern "C" void __cdecl GEX_Target(GXObject *gob, int *hit)
{
    unsigned int a;
    unsigned int b;
    unsigned int k;
    unsigned int f;
    int i;
    Event *event;
    if (*hit == 0)
        return;
    if (gob->flashTime > 0)
        return;
    a = *gob->attack & 0xffff;
    b = *gob->defend & 0xffff;
    k = (gob->other->flags & 0xf00) >> 8;
    if (a == 5)
        return;
    if (gob->other->type == 1 && !(gob->flags2 & 4) && k == 2 && !DAT_004a023c_PowerUp_Invincibility
        && (b == a || a == 1 || a == 7 || b == 2 || b == 6 || (b == 0 && a == 8) || (b == 8 && a == 0))) {
        if (DAT_00455c54_DebugVar > 1)
            TracePrintf_Debug_00405390(s_Damage_To_GEX_0045b140);
        PlayerDamage_00417b70(gob);
        event = gob->events;
        i = 12;
        do {
            if (event->eventNumber == 0xd)
                SCRIPT_DoEvent_00433590(gob, &gScriptEventDebug_00464278 + 8, event->eventToCall, event->eventNumber);
            event++;
        } while (--i);
        return;
    }
    if (((DAT_004a023c_PowerUp_Invincibility && k == 2) || ((a == 2 || a == 6 || b == 1 || b == 7) && k == 2)) && b != 3 || k == 5) {
        gEventLastCollideInfo_0045b570 = hit;
        {
            void **call = &gob->events[0].eventToCall;
            i = 12;
            do {
                int n = ((int *)call)[-1];
                if (n == 1 || (((k == 2 && b == 1) || DAT_004a023c_PowerUp_Invincibility) && n == 0x12))
                    SCRIPT_DoEvent_00433590(gob, &gScriptEventDebug_00464278 + 8, *call, n);
                call += 2;
            } while (--i);
        }
        gEventLastCollideInfo_0045b570 = 0;
        return;
    }
    f = gob->flags & 0xf00;
    if (f == 0xb00 && k == 3) {
        event = gob->events;
        i = 12;
        do {
            if (event->eventNumber == 0x10)
                SCRIPT_DoEvent_00433590(gob, &gScriptEventDebug_00464278 + 8, event->eventToCall, event->eventNumber);
            event++;
        } while (--i);
    } else if (f == 0x500) {
        event = gob->events;
        i = 12;
        do {
            if (event->eventNumber == 0x13)
                SCRIPT_DoEvent_00433590(gob, &gScriptEventDebug_00464278 + 8, event->eventToCall, event->eventNumber);
            event++;
        } while (--i);
    }
}
