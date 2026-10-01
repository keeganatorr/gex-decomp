"""Audited manual-zoom adaptations for replacement compilation only.

The baseline/probe/verifier sources stay untouched. Exact sites fail closed.
"""
PREFIX = '''extern "C" {
int __cdecl GEX_ZoomKey(unsigned int,long);
void __cdecl GEX_ZoomBeginFrame(void);
void __cdecl GEX_ZoomBeginDraw(int *);
void __cdecl GEX_ZoomEndDraw(void);
void __cdecl GEX_ZoomObjectBegin(void *);
void __cdecl GEX_ZoomObjectEnd(void);
int __cdecl GEX_ZoomRender(void *);
int __cdecl GEX_ZoomViewWidth(void);
int __cdecl GEX_ZoomViewHeight(void);
int __cdecl GEX_ZoomCullWidth(void);
int __cdecl GEX_ZoomCullHeight(void);
int __cdecl GEX_ZoomCullX(void);
int __cdecl GEX_ZoomCullY(void);
void __cdecl GEX_ZoomIntroduce(int *,int,int,int);
}
'''


def hooks(source, address, language='cpp'):
    changed = False

    def replace(old, new, count=1):
        nonlocal source, changed
        actual = source.count(old)
        if actual != count:
            raise ValueError(f'{address}: zoom hook changed: {old!r} ({actual}/{count})')
        source = source.replace(old, new)
        changed = True

    if address == '00403960':
        replace('if (GEX_SpriteViewerKey(wParam, lParam)) return 0;',
                'if (GEX_ZoomKey(wParam, lParam)) return 0;\n        if (GEX_SpriteViewerKey(wParam, lParam)) return 0;')
        replace('case 0x0101: // WM_KEYUP',
                'case 0x0101: // WM_KEYUP\n        if (GEX_ZoomKey(wParam, 0x40000000)) return 0;')
        replace('case 0x0102: // WM_CHAR',
                "case 0x0102: // WM_CHAR\n        if ((wParam == '+' || wParam == '-') &&\n            GEX_ZoomKey(wParam == '+' ? 0x6b : 0x6d, 0x40000000)) return 0;")
    elif address == '0040a010':
        # Clear the previous scene even when the sprite viewer returns early.
        replace('    M1_CurrentLevel_004a2990 = level;',
                '    M1_CurrentLevel_004a2990 = level;\n    GEX_ZoomBeginFrame();')
        replace('OBI_IntroduceObjects_0040f910(M1_ObjectIntroTrackerTable_004a2a78[i], CAMERA_XPos_004a2a38, CAMERA_YPos_004a2a1c, 0);',
                'GEX_ZoomIntroduce((int *)M1_ObjectIntroTrackerTable_004a2a78[i], CAMERA_XPos_004a2a38, CAMERA_YPos_004a2a1c, 0);')
        replace('    if (gDrawObs_004a2a24 && !gNodrawLevel_004a288c) {\n        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[0].head);',
                '    GEX_ZoomBeginDraw((int *)M1_CurrentLevel_004a2990->map);\n    if (gDrawObs_004a2a24 && !gNodrawLevel_004a288c) {\n        PTR_GOB_DrawList_00458ed8(ListType_ARRAY_004a28a0[0].head);')
        replace('    FUN_00410250_UpdateCameraBounds();',
                '    GEX_ZoomEndDraw();\n    FUN_00410250_UpdateCameraBounds();')
    elif address == '0040efa0':
        replace('            if (callback != 0 && isValidObjectCallback(callback))\n                callback(object);',
                '            if (callback != 0 && isValidObjectCallback(callback)) {\n                GEX_ZoomObjectBegin((void *)callback);\n                callback(object);\n                GEX_ZoomObjectEnd();\n            }')
    elif address == '00445140':
        replace('    unsigned int command = (unsigned int)first;',
                '    if (GEX_ZoomRender(first)) return;\n    unsigned int command = (unsigned int)first;')
    elif address == '0040fce0':
        replace('GEX_WidescreenWidth', 'GEX_ZoomCullWidth', 2)
        replace('(int)CAMERA_XPos_004a2a38', 'GEX_ZoomCullX()', 2)
        replace('(int)CAMERA_YPos_004a2a1c', 'GEX_ZoomCullY()', 2)
        replace('0xf00000', '(GEX_ZoomCullHeight() << 16)')

    if address in ('0043fb40','0043fce0','00440cb0','00444590','004432c0','00441150','0041fef0'):
        # Only command generation gets virtual extents. Rasterizers and physical
        # frame/cache reservation continue using GEX_WidescreenWidth.
        source = source.replace('GEX_WidescreenWidth','GEX_ZoomViewWidth')
        changed = True
        if address == '0043fb40':
            replace('    rows = cols + 1;',
                    '    rows = cols + 1;\n    if (GEX_ZoomViewHeight() != 240) {\n        rows = ((camY & 0xff0000) + (GEX_ZoomViewHeight() << 16) + 0xffffff) >> 24;\n        if (rows > skip) rows = skip;\n        if (rows <= 0) rows = 1;\n    }')
            replace('    skip = map->width - cols;',
                    '    if (cols <= 0) return;\n    skip = map->width - cols;')
        elif address == '0043fce0':
            replace('iVar9 + 0xf00000', 'iVar9 + (GEX_ZoomViewHeight() << 16)')
            replace('    if (iVar9 + -0x100000 <= param_4) {\n      local_20 = local_20 - (param_4 + iVar8 * -0x20000 + 0x100000 >> 0x15);\n    }',
                    '    int lastRow = (GEX_ZoomViewHeight() - 256) * 65536;\n    if (iVar9 + lastRow <= param_4) {\n      local_20 = local_20 - (param_4 + iVar8 * -0x20000 - lastRow >> 0x15);\n    }\n    if (local_24 <= 0 || local_20 <= 0) return;')
        elif address in ('00440cb0','0041fef0'):
            source = source.replace('0xf00000','(GEX_ZoomViewHeight() << 16)')
        elif address == '00444590':
            replace('0x0f00000','(GEX_ZoomViewHeight() << 16)')
        elif address == '004432c0':
            replace('local_4c < 0xf0','local_4c < GEX_ZoomViewHeight()')
        elif address == '00441150':
            replace('sVar7 < 0xf0','sVar7 < GEX_ZoomViewHeight()')
            replace('0x23fffff < iVar12','((GEX_ZoomViewWidth() + 256) << 16) <= iVar12')
            replace('0x1efffff < iVar13','((GEX_ZoomViewHeight() + 256) << 16) <= iVar13')
    prefix = PREFIX if language == 'cpp' else PREFIX.replace('extern "C" {\n','').removesuffix('}\n')
    return prefix + source if changed else source
