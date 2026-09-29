// Adapted from pc_decomp_backup/src/functions/FUN_00427550.cpp
// Historical source SHA256: 79e78e26cb56a2f5b867318f720c8826f3e76c85fafdb8232de901306ec9bbdd
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00427390(void**);

extern "C" void __cdecl InitPlayerTurn_00427550(void** Gob)
{
    FUN_00420BC0(Gob);
    Gob[0x15] = (void*)0;
    Gob[0x26] = (void*)0;
    Gob[0x20] = (void*)0;
    Gob[0x22] = (void*)0;
    Gob[0x1c] = (void*)0x1b;  
    Gob[0x14] = (void*)0x2a;
    Gob[0x27] = (void*)6;
    FUN_00427390(Gob);
}
}
