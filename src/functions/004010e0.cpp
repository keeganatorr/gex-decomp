struct IDirectDraw;
struct IDirectDrawVtbl
{
    long (__stdcall *QueryInterface)(IDirectDraw *, void *, void **);
    unsigned long (__stdcall *AddRef)(IDirectDraw *);
    unsigned long (__stdcall *Release)(IDirectDraw *);
};
struct IDirectDraw
{
    IDirectDrawVtbl *lpVtbl;
};

extern "C" IDirectDraw *gDirectDraw_00451030;

extern "C" void GEX_Target(void)
{
    if (gDirectDraw_00451030 != 0)
    {
        gDirectDraw_00451030->lpVtbl->Release(gDirectDraw_00451030);
        gDirectDraw_00451030 = 0;
    }
}
