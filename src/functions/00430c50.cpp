typedef struct GXNode { unsigned int nd_next; } GXNode;
typedef struct GXObject GXObject;
struct GXObject {
    unsigned char _pad0[0x6c];
    unsigned int gob_flags;      /* 0x6c */
    unsigned char _pad70[0x98 - 0x70];
    int gob_state;               /* 0x98 */
    unsigned char _pad9c[0xa0 - 0x9c];
    int gob_hidden;              /* 0xa0 */
    unsigned char _pada4[0xb8 - 0xa4];
    int gob_health;              /* 0xb8 */
    unsigned char _padbc[0x170 - 0xbc];
    GXNode *gob_a;               /* 0x170 */
    GXNode *gob_b;               /* 0x174 */
    GXObject *gob_other;         /* 0x178 */
};
extern "C" {
extern GXObject *gPlayerObject_004a27fc;
extern int DAT_00455c54_DebugVar;
extern int DAT_004a023c_PowerUp_Invincibility;
extern int DAT_00463d78;
extern int PTR_0049fb98;
extern int DAT_00463f00;
extern int DAT_00463f04;
extern int DAT_00463f08;
extern int DAT_00463f0c;
extern char s_Damage_To_GEX_0045b140[];
void __cdecl TracePrintf_Debug_00405390(const char *format, ...);
void __cdecl PlayerDamage_00417b70(GXObject *gob);
int __cdecl FUN_00430b40(GXObject *gob);
void __cdecl GEX_Target(GXObject *gob, int *hit)
{
    unsigned int a;
    unsigned int b;
    unsigned int kind;
    if (*hit != 0 && gob->gob_hidden == 0 && gob->gob_state == 0x40) {
        a = gob->gob_a->nd_next & 0xffff;
        b = gob->gob_b->nd_next & 0xffff;
        kind = (gob->gob_other->gob_flags & 0xf00) >> 8;
        if (a == 5) {
            if (FUN_00430b40(gob))
                PlayerDamage_00417b70(gob);
            DAT_00463f08 = 0;
            DAT_00463f00 = 0;
            DAT_00463f0c = 0;
            DAT_00463f04 = 0;
            return;
        }
        if (kind == 2 && DAT_004a023c_PowerUp_Invincibility == 0 && (b == a || a == 1)) {
            if (DAT_00455c54_DebugVar > 1)
                TracePrintf_Debug_00405390(s_Damage_To_GEX_0045b140);
            PlayerDamage_00417b70(gob);
            return;
        }
        if (kind == 5 && gob->gob_health <= 0) {
            PTR_0049fb98 = DAT_00463d78;
            return;
        }
    } else if (*hit != 0 && gob->gob_hidden == 0 && (gob->gob_flags >> 8 & 0xf) == 4 && gob->gob_other == gPlayerObject_004a27fc) {
        PlayerDamage_00417b70(gob);
    }
}
}
