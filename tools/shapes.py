#!/usr/bin/env python3
"""Hill-climb over semantically equivalent source shapes.

Symbol-numbering search (perturb.py, lperm.py) cannot fix a near miss whose
cause is the *shape* of an expression: CL 10.00 allocates registers and
lays out blocks differently for `if (x >= K) x = K;` and
`x = x < K ? x : K;`, for `abs(d)` and `d < 0 ? -d : d`, for `!x` and
`x == 0`, although each pair means the same thing. 004264c0 went from an
extra `push ebx` to exact by the ternary clamp alone.

Every rewrite here preserves semantics for int operands. Each is tried at
every site on its own; improvements are kept greedily and the scan repeats
until nothing improves. Prints EXACT <lang> and writes FILE.shape.cpp when a
shape matches.

    shapes.py ADDRESS FILE [--languages cpp,c] [--rounds N]
"""
import argparse, os, re, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import probe

IDENT = r'[A-Za-z_][\w.\->\[\]]*'
NUM = r'(?:0x[0-9a-fA-F]+|\d+)'


def num(text):
    return int(text, 16) if text.lower().startswith('0x') else int(text)


def fmt(value, like):
    return hex(value) if like.lower().startswith('0x') else str(value)


def rewrites(src):
    """Yield (description, new source) for each single-site rewrite."""
    # clamp: if (x >= K) x = K;  <->  x = x < K ? x : K;   (and <= / > forms)
    pat = re.compile(r'( *)if \((%s) (>=|>|<=|<) (%s)\)\n\s*\2 = \4;' % (IDENT, NUM))
    for m in pat.finditer(src):
        ind, x, op, k = m.groups()
        inverse = {'>=': '<', '>': '<=', '<=': '>', '<': '>='}[op]
        yield 'clamp-ternary', src[:m.start()] + f'{ind}{x} = {x} {inverse} {k} ? {x} : {k};' + src[m.end():]
    pat = re.compile(r'( *)(%s) = \2 (<|<=|>|>=) (%s) \? \2 : \4;' % (IDENT, NUM))
    for m in pat.finditer(src):
        ind, x, op, k = m.groups()
        inverse = {'<': '>=', '<=': '>', '>': '<=', '>=': '<'}[op]
        yield 'clamp-if', src[:m.start()] + f'{ind}if ({x} {inverse} {k})\n{ind}    {x} = {k};' + src[m.end():]
    # abs forms
    pat = re.compile(r'(%s) < 0 \? -\1 : \1' % IDENT)
    for m in pat.finditer(src):
        yield 'abs-call', src[:m.start()] + f'abs({m.group(1)})' + src[m.end():]
    pat = re.compile(r'\babs\((%s)\)' % IDENT)
    for m in pat.finditer(src):
        yield 'abs-ternary', src[:m.start()] + f'({m.group(1)} < 0 ? -{m.group(1)} : {m.group(1)})' + src[m.end():]
    # integer compare spelling: x >= K <-> x > K-1, x < K <-> x <= K-1 (and back)
    pat = re.compile(r'(%s) (>=|<|>|<=) (-?%s)\b(?!\s*[?:])' % (IDENT, NUM))
    for m in pat.finditer(src):
        x, op, k = m.groups()
        if k.startswith('-'):
            continue
        v = num(k)
        alt = {'>=': ('>', v - 1), '<': ('<=', v - 1), '>': ('>=', v + 1), '<=': ('<', v + 1)}[op]
        if alt[1] < 0:
            continue
        yield 'compare-spelling', src[:m.start()] + f'{x} {alt[0]} {fmt(alt[1], k)}' + src[m.end():]
    # operand order of == / != and of relational compares between two names
    pat = re.compile(r'\b(%s) (==|!=|<|>|<=|>=) (%s)\b' % (IDENT, IDENT))
    for m in pat.finditer(src):
        a, op, b = m.groups()
        if a in ('return', 'if', 'while') or b in ('return',):
            continue
        swapped = {'==': '==', '!=': '!=', '<': '>', '>': '<', '<=': '>=', '>=': '<='}[op]
        yield 'operand-order', src[:m.start()] + f'{b} {swapped} {a}' + src[m.end():]
    # !x <-> x == 0 inside conditions
    pat = re.compile(r'\(!(%s)\)' % IDENT)
    for m in pat.finditer(src):
        yield 'not-eq0', src[:m.start()] + f'({m.group(1)} == 0)' + src[m.end():]
    pat = re.compile(r'\((%s) == 0\)' % IDENT)
    for m in pat.finditer(src):
        yield 'eq0-not', src[:m.start()] + f'(!{m.group(1)})' + src[m.end():]
    # compound assignment <-> explicit form
    pat = re.compile(r'( *)(%s) ([+\-|&^]|<<|>>)= ([^;]+);' % IDENT)
    for m in pat.finditer(src):
        ind, x, op, e = m.groups()
        yield 'compound-explicit', src[:m.start()] + f'{ind}{x} = {x} {op} {e};' + src[m.end():]
        if op in '+|&^':
            yield 'compound-explicit-rev', src[:m.start()] + f'{ind}{x} = {e} {op} {x};' + src[m.end():]
    pat = re.compile(r'( *)(%s) = \2 ([+\-|&^]|<<|>>) ([^;?]+);' % IDENT)
    for m in pat.finditer(src):
        ind, x, op, e = m.groups()
        yield 'explicit-compound', src[:m.start()] + f'{ind}{x} {op}= {e};' + src[m.end():]
    # store then conditional overwrite <-> if/else: CL emits `if (c) m = A;
    # else m = B;` as a store of A before the test with the condition loaded
    # first, which `m = B; if (!c) m = A;` does not (0040c4d0, 004327f0)
    pat = re.compile(r'(?m)^( +)([^\n;=]+?) = ([^\n;]+);\n\1if \(([^\n]+)\)\n\1    \2 = ([^\n;]+);\n')
    for m in pat.finditer(src):
        ind, lhs, a, c, b = m.groups()
        yield 'store-if-else', src[:m.start()] + f'{ind}if ({c})\n{ind}    {lhs} = {b};\n{ind}else\n{ind}    {lhs} = {a};\n' + src[m.end():]
        neg = c[1:] if c.startswith('!') and '&&' not in c and '||' not in c else f'!({c})'
        yield 'store-if-else-neg', src[:m.start()] + f'{ind}if ({neg})\n{ind}    {lhs} = {a};\n{ind}else\n{ind}    {lhs} = {b};\n' + src[m.end():]
    # single-bit extraction: `(x & 0x200) >> 9` and `(x & 0x200) != 0` both
    # compile to and/shr, but the boolean is a different tree and changes the
    # operand order of a later compare (00421740)
    pat = re.compile(r'\((%s) & (0x[0-9a-fA-F]+)\) >> (\d+)' % IDENT)
    for m in pat.finditer(src):
        x, k, n = m.groups()
        if num(k) == 1 << int(n):
            yield 'bit-shift-bool', src[:m.start()] + f'({x} & {k}) != 0' + src[m.end():]
    pat = re.compile(r'\((%s) & (0x[0-9a-fA-F]+)\) != 0' % IDENT)
    for m in pat.finditer(src):
        x, k = m.groups()
        v = num(k)
        if v and v & (v - 1) == 0:
            yield 'bit-bool-shift', src[:m.start()] + f'({x} & {k}) >> {v.bit_length() - 1}' + src[m.end():]
    # commutative operands: with calls on both sides, CL evaluates them in an
    # order that follows the spelling (and differs between front ends)
    for desc, cand in commutative_swaps(src):
        yield desc, cand


def operand_left(src, end):
    """Start index of the atom ending just before `end` (exclusive), or None."""
    i = end
    while i > 0 and src[i - 1] == ' ':
        i -= 1
    stop = i
    if i > 0 and src[i - 1] == ')':
        depth = 0
        while i > 0:
            i -= 1
            depth += {')': 1, '(': -1}.get(src[i], 0)
            if depth == 0:
                break
        else:
            return None
    while i > 0 and (src[i - 1].isalnum() or src[i - 1] in '_.>[]' or (src[i - 1] == '-' and src[i] == '>')):
        if src[i - 1] == ']':
            depth = 0
            while i > 0:
                i -= 1
                depth += {']': 1, '[': -1}.get(src[i], 0)
                if depth == 0:
                    break
            continue
        i -= 1
    return (i, stop) if i < stop else None


def operand_right(src, start):
    i = start
    while i < len(src) and src[i] == ' ':
        i += 1
    begin = i
    while i < len(src) and (src[i].isalnum() or src[i] in '_.' or src[i:i + 2] == '->'):
        i += 2 if src[i:i + 2] == '->' else 1
    while i < len(src) and src[i] in '([':
        depth = 0
        while i < len(src):
            if src[i] in '([':
                depth += 1
            elif src[i] in ')]':
                depth -= 1
            i += 1
            if depth == 0:
                break
        while i < len(src) and (src[i].isalnum() or src[i] in '_.' or src[i:i + 2] == '->'):
            i += 2 if src[i:i + 2] == '->' else 1
    return (begin, i) if i > begin else None


def commutative_swaps(src):
    for m in re.finditer(r' ([+*]) ', src):
        op = m.group(1)
        left = operand_left(src, m.start())
        right = operand_right(src, m.end())
        if not left or not right:
            continue
        a, b = src[left[0]:left[1]], src[right[0]:right[1]]
        if not ('(' in a or '(' in b):
            continue  # names alone are symbol numbering's business
        before = src[:left[0]].rstrip()[-1:]
        after = src[right[1]:].lstrip()[:1]
        lower = '(=,?:' + ('+-' if op == '*' else '')
        if (before and before not in lower) or (after and after not in ');,?:' + ('+-' if op == '*' else '')):
            continue
        yield 'commute', src[:left[0]] + b + src[left[1]:right[0]] + a + src[right[1]:]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('address'); ap.add_argument('source')
    ap.add_argument('--languages', default='cpp,c'); ap.add_argument('--rounds', type=int, default=4)
    args = ap.parse_args()
    p = probe.Probe(args.address)
    langs = args.languages.split(',')
    src = open(args.source).read()
    if 'abs(' in src and not re.search(r'\babs\s*\(int', src):
        src = src.replace('extern "C" {', 'extern "C" {\nint __cdecl abs(int);', 1)

    def score(text):
        best = (-1, None)
        for lang in langs:
            r = p.measure(text, lang=lang)
            if r['exact']:
                return 101, lang
            if r['compiled'] and r['percent'] is not None and r['percent'] > best[0]:
                best = (r['percent'], lang)
        return best

    cur, (cur_score, cur_lang) = src, score(src)
    print(f'baseline {cur_score:.1f} {cur_lang}')
    for rnd in range(args.rounds):
        improved = False
        for desc, cand in rewrites(cur):
            if 'abs(' in cand and 'abs(int' not in cand:
                cand = cand.replace('extern "C" {', 'extern "C" {\nint __cdecl abs(int);', 1)
            s, lang = score(cand)
            if s > cur_score:
                cur, cur_score, cur_lang, improved = cand, s, lang, True
                print(f'round {rnd} {desc}: {min(s, 100):.1f} {lang}')
                if s == 101:
                    out = args.source.replace('.cpp', '.shape.cpp')
                    open(out, 'w').write(cur if lang == 'cpp' else probe.to_c(cur))
                    print('EXACT', lang, out)
                    return 0
        if not improved:
            break
    out = args.source.replace('.cpp', '.shape.cpp')
    open(out, 'w').write(cur)
    print(f'best {min(cur_score, 100):.1f} {cur_lang} {out}')
    return 2


if __name__ == '__main__':
    sys.exit(main())
