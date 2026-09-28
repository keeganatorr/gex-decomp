typedef struct Rect16 { unsigned short x, y, w, h; } Rect16;
typedef struct ViewPort { Rect16 area; Rect16 screen; int unk10; } ViewPort;
extern "C" {
void * __cdecl memset(void *, int, unsigned int);
ViewPort * __cdecl GEX_Target(ViewPort *view, int x, int y, int w, int h)
{
    memset(view, 0, 20);
    view->area.x = x & 0x3ff;
    view->screen.w = 0x100;
    view->area.y = y & 0x1ff;
    view->area.w = w;
    view->area.h = h;
    view->screen.h = 0xf0;
    return view;
}
}
