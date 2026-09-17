extern "C" int DAT_004a0244;
extern "C" int __cdecl FUN_00423ab0_AirToFaceCrawl(void*);
extern "C" int __cdecl FUN_00423190_CollisionIntoJumpTailWhack(void*);
extern "C" int __cdecl FUN_004231c0_JumpTongueLash(void*);

extern "C" int __cdecl GEX_Target(void* param1) {
    if ((DAT_004a0244 == 0 && FUN_00423ab0_AirToFaceCrawl(param1)) ||
        FUN_00423190_CollisionIntoJumpTailWhack(param1) ||
        FUN_004231c0_JumpTongueLash(param1)) {
        return 1;
    }
    return 0;
}
