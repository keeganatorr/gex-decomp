// Only the two traversed links at +0x160/+0x164 are specified by this partial view.
struct Object { unsigned char unknown[0x160]; Object* link160; Object* link164; };
extern "C" void __cdecl ResetPreviousPosition_004317b0(Object* object);
extern "C" void __cdecl GEX_Target(Object* object)
{
    if (object->link164) GEX_Target(object->link164);
    if (object->link160) GEX_Target(object->link160);
    ResetPreviousPosition_004317b0(object);
}
