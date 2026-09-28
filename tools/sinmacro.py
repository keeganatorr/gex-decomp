"""Text of the game's sine macro, for sources that use it.

The original expands a macro over the quarter-wave table gTrigTable_0045a5c8
at every use (no `#` is allowed in a source, so it has to be written out).
S(x) is sine of x in 256ths of a turn; cosine is S(x + 64). CL 10.00 turns a
test like (a >> 16) > 256 into (a & 0xffff0000) > 0x1000000, so pass the
shifted expression itself when the target compares masked values, and a local
when the target compares after `shr`/`sar` (0043d630, 00431990).

    from sinmacro import S;  src = f"s = {S('angle >> 16')};"

Used for 0041cc70, 00419c00, 00434670, 00431990, 004391d0.
"""
def Q(z, T='gTrigTable_0045a5c8'):
    return f'(({z}) > 64 ? {T}[128 - ({z})] : {T}[{z}])'
def A(y):
    m = f'(({y}) % 256)'
    return f'(({y}) > 256 ? ({m} > 128 ? -{Q(m + " - 128")} : {Q(m)}) : (({y}) > 128 ? -{Q("(" + y + ") - 128")} : {Q(y)}))'
def S(x):
    return f'(({x}) < 0 ? -{A("-(" + x + ")")} : {A(x)})'
