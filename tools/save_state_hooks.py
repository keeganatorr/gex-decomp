"""Audited replacement-build hooks; never used by probe or verifier compilation.

Resource assignment sites establish pointer provenance, not pointer-looking values.
The build refuses changed hook sites rather than silently losing coverage.
"""
import re

PREFIX = '''extern "C" {
void __cdecl GEX_StateAllocated(void *, unsigned int);
void __cdecl GEX_StateFreed(void *);
void __cdecl GEX_StatePointer(void *);
void __cdecl GEX_StateCopyKind(void *, const void *);
void __cdecl GEX_StateSwapKind(void *, void *);
void __cdecl GEX_StateHandle(void *);
void __cdecl GEX_StateClear(void *, unsigned int);
void __cdecl GEX_StateCacheSlot(void *);
void __cdecl GEX_StateFileOpened(void *, const char *);
void __cdecl GEX_StateFileClosed(void *);
void __cdecl GEX_StateResourceRead(void *, void *, unsigned int);
void __cdecl GEX_StateResourceCopy(void *, const void *, unsigned int);
int __cdecl GEX_StateKey(unsigned int, long);
int __cdecl GEX_StateBusy(void);
int __cdecl GEX_StateMutationBegin(void);
void __cdecl GEX_StateMutationEnd(void);
void __cdecl GEX_StateActivation(unsigned int);
unsigned int __cdecl GEX_StateLatestActivation(void);
void __cdecl GEX_StateDeferActivation(void);
int __cdecl GEX_StateRand(void);
void __cdecl GEX_StateSequence(unsigned int);
void __cdecl GEX_StateReturnLevel(unsigned int);
int __cdecl GEX_StateSequenceResume(int *);
int __cdecl GEX_StateFunctionValid(void *);
int __cdecl GEX_StatePoll(int);
int __cdecl GEX_StatePending(void);
void __cdecl GEX_StateDraw(void);
void __cdecl GEX_StateUITick(void);
void __cdecl GEX_StateDispatch(void);
void __cdecl GEX_StateAudioWorker(void);
void __cdecl GEX_StateMusicOpened(const char *);
void __cdecl GEX_StateAudioAsset(unsigned int,const char *,unsigned int,unsigned int);
void __cdecl GEX_StateSFXAsset(unsigned int,unsigned int);
extern int GEX_StateFont[5];
}
'''


def hooks(source: str, address: str, language: str = 'cpp') -> str:
    changed = False

    def replace(old, new):
        nonlocal source, changed
        if source.count(old) != 1:
            raise ValueError(f'{address}: save-state hook changed: {old}')
        source = source.replace(old, new)
        changed = True

    if address == '004096c0':
        replace('return allocatedMemory;', 'GEX_StateAllocated(allocatedMemory, allocationSize);\n    return allocatedMemory;')
    elif address == '00409740':
        replace('GlobalFree(memory);', 'GEX_StateFreed(memory);\n            GlobalFree(memory);')
    elif address == '004097b0':
        replace('GlobalFree((void*)*ptr);', 'GEX_StateFreed((void*)*ptr);\n            GlobalFree((void*)*ptr);')
    elif address == '00409170':
        replace('return file;', 'GEX_StateFileOpened(file, filename);\n    return file;')
    elif address == '00409200':
        replace('CloseHandle(pHandle);', 'GEX_StateFileClosed(pHandle);\n            CloseHandle(pHandle);')
    elif address == '00409250':
        replace('    unsigned long read;', '    unsigned long read;')
        replace('        WinShowError_004063d0(1, DAT_00487a10_FileAccessErrorString);','        WinShowError_004063d0(1, DAT_00487a10_FileAccessErrorString);\n    GEX_StateResourceRead(file,buffer,read);')
    elif address == '004094f0':
        replace('memcpy(buffer, gIDL_0047f000 + file->offset, bytes);', 'memcpy(buffer, gIDL_0047f000 + file->offset, bytes); GEX_StateResourceCopy(buffer,gIDL_0047f000+file->offset,bytes);')
    elif address == '004195d0':
        replace('memset(GexObject, 0, 0x204);','memset(GexObject, 0, 0x204); GEX_StateClear(GexObject,0x204);')
    elif address == '00418bb0':
        replace('fields[field] = DAT_0049fb94;', 'fields[field] = DAT_0049fb94; GEX_StateCopyKind(fields+field,&DAT_0049fb94);')
    elif address == '004182f0':
        replace('p[idx + 0x1a] = v;', 'p[idx + 0x1a] = v; GEX_StateCopyKind(p+idx+0x1a,param_2+idx+0x1a);')
    elif address == '004183d0':
        replace('((void**)parent)[idx + 0x1a] = value;', '((void**)parent)[idx + 0x1a] = value; GEX_StateCopyKind((void **)parent+idx+0x1a,param_2+idx+0x1a);')
    elif address == '00418390':
        replace('int value = gob->gob_fields[field];', 'int value = gob->gob_fields[field]; int *origin=gob->gob_fields+field;')
        replace('gob->gob_fields[field] = value;', 'gob->gob_fields[field] = value; GEX_StateCopyKind(gob->gob_fields+field,origin);')
    elif address == '00418040':
        replace('SCRIPT_WorkRegister_0049fb90 = fields[field];','SCRIPT_WorkRegister_0049fb90 = fields[field]; GEX_StateCopyKind(&SCRIPT_WorkRegister_0049fb90,fields+field);')
    elif address == '00418fa0':
        replace('DAT_0049FB90 = obj[i + 0x1a][j + 0x1a];','DAT_0049FB90 = obj[i + 0x1a][j + 0x1a]; GEX_StateCopyKind(&DAT_0049FB90,obj[i+0x1a]+j+0x1a);')
    elif address == '00418fd0':
        replace('param_2[index + 0x1a][offset + 0x1a] = DAT_0049FB90;', 'param_2[index + 0x1a][offset + 0x1a] = DAT_0049FB90; GEX_StateCopyKind(param_2[index+0x1a]+offset+0x1a,&DAT_0049FB90);')
    elif address == '004187c0':
        replace('DAT_0049FB90 = table[index + 0x1a];','DAT_0049FB90 = table[index + 0x1a]; GEX_StateCopyKind(&DAT_0049FB90,table+index+0x1a);')
    elif address in ('00418cb0','00418080'):
        replace('return param_1;', 'GEX_StatePointer((void *)0x0049fb90); return param_1;')
    elif address == '00418f50':
        replace('((GXObject *)gob->gob_fields[link])->gob_fields[field] = value;', '((GXObject *)gob->gob_fields[link])->gob_fields[field] = value; GEX_StateClear(((GXObject *)gob->gob_fields[link])->gob_fields+field,4);')
    elif address == '00435d90':
        for field,origin in (('SCRIPT_WorkRegister_0049fb90','SCRIPT_Register_004642bc'),('SCRIPT_Register_004642bc','SCRIPT_WorkRegister_0049fb90')):
            replace(f'{field} = {origin};',f'{field} = {origin}; GEX_StateCopyKind(&{field},&{origin});')
        replace('SCRIPT_Register_004642bc = *((int **)0x0045b808)[*next++];', '{ int *field=((int **)0x0045b808)[*next++]; SCRIPT_Register_004642bc=*field; GEX_StateCopyKind(&SCRIPT_Register_004642bc,field); }')
        replace('SCRIPT_Register_004642bc = *(int *)(next + offset - 4);','SCRIPT_Register_004642bc = *(int *)(next + offset - 4); GEX_StateCopyKind(&SCRIPT_Register_004642bc,next+offset-4);')
        replace('*(int *)(next + offset - 4) = SCRIPT_Register_004642bc; break;', '*(int *)(next + offset - 4) = SCRIPT_Register_004642bc; GEX_StateCopyKind(next+offset-4,&SCRIPT_Register_004642bc); break;')
        replace('SCRIPT_Register_004642bc = gob[*next++ + 0x1a];', '{ int *field=gob+*next+++0x1a; SCRIPT_Register_004642bc=*field; GEX_StateCopyKind(&SCRIPT_Register_004642bc,field); }')
        replace('case 24: SCRIPT_Register_004642bc = (int)u32(next);', 'case 24: GEX_StateClear(&SCRIPT_Register_004642bc,4); SCRIPT_Register_004642bc = (int)u32(next);')
        replace('case 38: *((int **)0x0045b808)[*next++] = SCRIPT_Register_004642bc; break;', 'case 38: { int *field=((int **)0x0045b808)[*next++]; *field=SCRIPT_Register_004642bc; GEX_StateCopyKind(field,&SCRIPT_Register_004642bc); break; }')
        replace('case 39: gob[*next++ + 0x1a] = SCRIPT_Register_004642bc; break;', 'case 39: { int *field=gob+*next+++0x1a; *field=SCRIPT_Register_004642bc; GEX_StateCopyKind(field,&SCRIPT_Register_004642bc); break; }')
        replace('            value = SCRIPT_Register_004642bc;', '            GEX_StateSwapKind(&SCRIPT_Register_004642bc,&DAT_004642c8);\n            value = SCRIPT_Register_004642bc;')
        for op in (25,26,29,40,55):
            if op==40:
                replace('        case 40: {', '        case 40: { GEX_StateClear(&SCRIPT_Register_004642bc,4);')
            else:
                replace(f'        case {op}:', f'        case {op}: GEX_StateClear(&SCRIPT_Register_004642bc,4);')
    elif address == '00420210':
        replace('*list = PAR_ResolveParallax_00420190(base, *list);', '*list = PAR_ResolveParallax_00420190(base, *list); GEX_StatePointer(list);')
    elif address == '00409430':
        replace('    return 1;', '    GEX_StatePointer(&file->data); GEX_StateHandle(&file->handle);\n    return 1;')
    elif address == '00409350':
        replace('    return 1;', '    GEX_StatePointer(&file->data); GEX_StateHandle(&file->handle);\n    return 1;')
    elif address == '00437e90':
        replace('*(int*)((int)fileHandle + 0x44) = (int)fileHandle;', '*(int*)((int)fileHandle + 0x44) = (int)fileHandle; GEX_StatePointer((char *)fileHandle+0x44);')
    elif address in ('0040ef40','0040efa0'):
        replace('return (section > 0x40 && section < 0x44) ||\n           (section == 0x40 && offset >= 0x1000) ||\n           (section == 0x44 && offset < 0xbd54);', 'return GEX_StateFunctionValid((void *)callback);')
    elif address == '0040b3b0':
        replace('*list->blocks = data;', '{ *list->blocks = data; GEX_StatePointer(list->blocks); }')
        replace('(*list->blocks)[request->index] = (int)data;', '(*list->blocks)[request->index] = (int)data; GEX_StatePointer(*list->blocks + request->index);')
        replace('*list->end = (int)(*list->blocks + list->max + 1);', '{ *list->end = (int)(*list->blocks + list->max + 1); GEX_StatePointer(list->end); }')
    elif address == '004019d0':
        replace('                CloseHandle(hFile);', '                GEX_StateAudioAsset(1,filename,0,fileSize);\n                CloseHandle(hFile);')
    elif address == '00401b50':
        replace('        PTR_ARRAY_0049fb30[nextSlot - 1] = savedBuffer;', '        PTR_ARRAY_0049fb30[nextSlot - 1] = savedBuffer; GEX_StateSFXAsset(nextSlot-1,soundIndex);')
    elif address == '00401f20':
        replace('gSFXTable_0049fb54 = (unsigned char *)GlobalAlloc(0, bytes);', 'gSFXTable_0049fb54 = (unsigned char *)GlobalAlloc(0, bytes); GEX_StateAllocated(gSFXTable_0049fb54, bytes);')
    elif address == '00401f90':
        replace('GlobalFree(gSFXTable_0049fb54);', 'GEX_StateFreed(gSFXTable_0049fb54); GlobalFree(gSFXTable_0049fb54);')
    elif address == '0040b0a0':
        source = source.replace('Sleep(0);', 'GEX_StatePoll(-1); Sleep(0);').replace('Sleep(100);', 'GEX_StatePoll(-1); Sleep(100);')
        changed = True
    elif address == '0040b000':
        replace('int loadedLevel[5];', 'int *loadedLevel = GEX_StateFont;')
    elif address == '00403960':
        replace('if (GEX_SpriteViewerKey(wParam, lParam)) return 0;',
                'if (GEX_StateKey(wParam, lParam)) return 0;\n        if (GEX_StateBusy()) return 0;\n        if (GEX_SpriteViewerKey(wParam, lParam)) return 0;')
        replace('case 0x0102: // WM_CHAR', 'case 0x0102: // WM_CHAR\n        if (wParam>=\'0\' && wParam<=\'9\') return 0;\n        if (GEX_StateBusy()) return 0;')
        replace('case 0x0101: // WM_KEYUP', 'case 0x0101: // WM_KEYUP\n        if (GEX_StateKey(wParam,0x40000000)) return 0;\n        if (GEX_StateBusy()) return 0;')
        replace('long __stdcall WndProc_00403960(', 'long __stdcall GEX_StateWindowBody(')
        source += '''
extern "C" long __stdcall WndProc_00403960(HWND window,UINT message,UINT wParam,long lParam)
{
    long result;
    if(message==0x001c) GEX_StateActivation(wParam);
    if(message==0x8002) { message=0x001c; wParam=GEX_StateLatestActivation(); }
    if(!GEX_StateMutationBegin()) {
        if(message==0x0100) GEX_StateKey(wParam,lParam);
        if(message==0x001c) GEX_StateDeferActivation();
        if(message==0x000f || message==0x000c || message==0x000d || message==0x000e || message==0x0085) return DefWindowProcA(window,message,wParam,lParam);
        return 0;
    }
    result=GEX_StateWindowBody(window,message,wParam,lParam);
    GEX_StateMutationEnd();
    return result;
}
'''
    elif address == '00404ab0':
        replace('    JOYINFOEX info;', '    JOYINFOEX info;\n    GEX_StateUITick();\n    if (GEX_StateBusy()) return;')
        replace('void __stdcall FUN_00404ab0_timeSetEvent(', 'void __stdcall GEX_StateTimerBody(')
        source += '''
void __stdcall FUN_00404ab0_timeSetEvent(unsigned int id,unsigned int message,unsigned long user,unsigned long dw1,unsigned long dw2)
{
    if(!GEX_StateMutationBegin()) return;
    GEX_StateTimerBody(id,message,user,dw1,dw2);
    GEX_StateMutationEnd();
}
'''
    elif address == '00402c00':
        replace('        start = GetTickCount();', '        GEX_StateAudioWorker();\n        start = GetTickCount();')
        source = source.replace('Sleep(0);', 'GEX_StateAudioWorker(); Sleep(0);')
    elif address == '00402a00':
        replace('        DAT_0049a058 = 0xe000;', '        GEX_StateMusicOpened(fileName);\n        DAT_0049a058 = 0xe000;')
    elif address == '0040a010':
        replace('    M1_CurrentLevel_004a2990 = level;',
                '    M1_CurrentLevel_004a2990 = level;\n    if (GEX_StatePoll(1)) return 0;')
        replace('    FUN_0043f310_InitializeGraphicsVariables();',
                '    GEX_StateDraw();\n    FUN_0043f310_InitializeGraphicsVariables();')
    elif address == '0040a660':
        replace('    M1_CurrentLevel_004a2990 = map;', '    if (GEX_StatePending()) return;\n    M1_CurrentLevel_004a2990 = map;')
    elif address == '0040aa60':
        replace('    GEX_SpriteViewerReset();', '    if (GEX_StatePending()) return;\n    GEX_SpriteViewerReset();')
    elif address == '0040ad40':
        replace('    int levelOffset;', '    int levelOffset;\n    blockAnims=PTR_M1_00455b80; zero=0; levelDone=0;\n    if(GEX_StateSequenceResume(&levelOffset)) goto restoredLevel;')
        replace('        DAT_00455C3C = 4;', '        GEX_StateSequence(levelOffset);\n        DAT_00455C3C = 4;')
        replace('        do {\n            playResult = FUN_0040A010(blockAnims);', 'restoredLevel:\n        do {\n            playResult = FUN_0040A010(blockAnims);')
        replace('        FUN_0040A660(blockAnims);', '        if(GEX_StatePending()) return;\n        FUN_0040A660(blockAnims);')
    elif address == '0040af60':
        replace('            level = level_004a2964;', '            level = level_004a2964; GEX_StateReturnLevel(level);')
        replace('            level_004a2964 = level;', '            if (GEX_StatePending()) break;\n            level_004a2964 = level;')
        replace('        case 0:', '        case 6:\n            GEX_StateDispatch();\n            break;\n        case 0:')
    elif address == '00420300':
        replace('        GEX_SpriteViewerMenu();',
                '        GEX_SpriteViewerMenu();\n        if (GEX_StatePoll(0)) { done = 1; break; }\n        GEX_StateDraw();')
        replace('    gHitpoints_004a281c = 3;', '    if (GEX_StatePending()) return;\n    gHitpoints_004a281c = 3;')
    elif address == '0040b2d0':
        replace('            Sleep(0);', '            if (GEX_StatePoll(1)) break;\n            Sleep(0);')
    elif address == '0040b860':
        replace('        *(FUN_0046271C + FUN_00462734) = *levelDataArray++;',
                '        GEX_StateClear(*levelDataArray, 0x2000);\n        *(FUN_0046271C + FUN_00462734) = *levelDataArray++;')
    elif address == '0043ecf0':
        replace('    // The pinned 0043ecf7', '    GEX_StateCacheSlot((char *)tileSelectPtr-2);\n    // The pinned 0043ecf7')
    elif address == '0043e580':
        replace('    _alloca(0);', '    GEX_StateCacheSlot(image+18);\n    _alloca(0);')
    elif address == '0043e920':
        replace('    puVar4 = Image->cdu_data;', '    GEX_StateCacheSlot(&Image->cdu_image.cacheSlot);\n    puVar4 = Image->cdu_data;')
    elif address == '00420190':
        for lhs, rhs in (('*layers','(unsigned int)layer'), ('objects[-1]','(unsigned int)object'),
                         ('*field','(unsigned int)FUN_0040EB70(param_1, *field)')):
            replace(f'{lhs} = {rhs};', f'{lhs} = {rhs}; GEX_StatePointer((void *)&({lhs}));')

    # These loaders rewrite tagged on-disk references into live pointers. Mark
    # exactly those destination fields after the assignment, preserving if bodies.
    if address in ('0041f2d0', '0040eb70'):
        assignment = re.compile(r'^([ \t]*)([^;=\n]+?) = ([^;\n]+);$', re.M)

        def mark(match):
            nonlocal changed
            indent, lhs, rhs = match.groups()
            if not ('Resolve(' in rhs or 'LINK_RESOLVE_' in rhs or
                    'GOB_ResolveLoadObject_' in rhs or
                    (address == '0040eb70' and rhs == 'value + glob->scripts[i]') or
                    (address == '0041f2d0' and rhs in ('root','tile','chain','(unsigned int)groups',
                     '(unsigned int)group','(int)strings','(unsigned int)row','(unsigned int)objects','(unsigned int)strings'))):
                return match[0]
            if not ('->' in lhs or '[' in lhs or lhs.startswith('*')):
                return match[0]  # locals aren't persistent fields
            changed = True
            return f'{indent}{{ {lhs} = {rhs}; GEX_StatePointer((void *)&({lhs})); }}'
        source = assignment.sub(mark, source)

    if (language != 'c' and 'SCRIPT_' in source and address not in ('00435d90',) and
        re.search(r'(?:DAT|FUN)_0049[Ff][Bb]90|SCRIPT_WorkRegister_0049fb90', source) and
        re.search(r'(?:(?:DAT|FUN)_0049[Ff][Bb]90|SCRIPT_WorkRegister_0049fb90)\s*(?:=(?!=)|[+*/%&|^-]=|>>=|<<=)',source)):
        # Copy/lookup natives re-establish the reference kind after this clear.
        pattern=re.compile(r'(SCRIPT_\w+\([^{};]*\)\s*\{)')
        source,n=pattern.subn(r'\1 GEX_StateClear((void *)0x0049fb90,4);',source,count=1)
        changed=changed or bool(n)

    source,n=re.subn(r'\brand\b','GEX_StateRand',source)
    changed=changed or bool(n)
    prefix = PREFIX if language == 'cpp' else PREFIX.replace('extern "C" {\n', '').removesuffix('}\n')
    return prefix + source if changed else source
