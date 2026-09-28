#!/usr/bin/env python3
"""Joint search over marked source alternatives, declaration order, local
types and extern order, scored per case by tools/casediff.py.

    tools/altsearch.py ADDRESS FILE [--lang c|cpp] [--runs N] [--fixed alt0,alt3]

FILE is an ordinary candidate with optional alternative blocks:

    /*ALT*/ p++;
            switch (op & 0x7f) {
    /*OR*/  switch (p++, op & 0x7f) {
    /*END*/

Each block is one choice; the first alternative is the default. `--runs N`
also offers every order of the first N runs of simple statements (up to four
statements; longer runs get swaps and rotations), because the order of a few
initialisations can decide the register roles of a whole function
(00427d30). The search is greedy: it keeps any single change that lowers the
per-case mismatch total, cycles through alternatives, declaration moves,
local retypes and extern moves, and stops when a full pass changes nothing.

Why joint: in a large function one choice moves register allocation
everywhere, so an alternative that fixes its own case can cost more
elsewhere until a declaration or type change compensates. 00435d90
(231 -> 2 lines) and 00427d30 (166 -> 0, exact) were found this way.
The best source is written to FILE.best.cpp (markers resolved); a search
input is not a publishable source until the markers are gone. Retypes are
not semantics-checked: read every `retype` line in the log before
publishing (an `int` narrowed to `char` can match bytes by accident).
"""
import argparse, itertools, os, re, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import casediff, probe  # noqa: E402

TYPES = ['int', 'unsigned int', 'short', 'unsigned short', 'char', 'unsigned char']
BLOCK = re.compile(r'/\*ALT\*/(.*?)/\*END\*/', re.S)
SIMPLE = re.compile(r'^(\s+)(?!if\b|else\b|for\b|while\b|do\b|return\b|switch\b|case\b|break\b|default\b|goto\b)[^{}\n]*;\s*$')


WORD = re.compile(r'[A-Za-z_]\w*')


def effects(stmt):
    """(written names, read names, has call) of one simple statement."""
    t = stmt.strip().rstrip(';')
    call = re.search(r'\w\s*\(', t) is not None
    m = re.match(r'(.*?)(\+\+|--)?\s*(=|\+=|-=|\*=|/=|&=|\|=|\^=|<<=|>>=)(?!=)(.*)$', t)
    if not m:
        names = set(WORD.findall(t))
        return names, names, call
    lhs, rhs = m.group(1), m.group(4)
    target = WORD.findall(lhs)
    written = {target[0]} if target else set()
    read = set(WORD.findall(rhs)) | set(target[1:])
    if m.group(3) != '=':
        read |= written
    return written, read, call


def keeps_dependencies(seg, perm):
    """True when perm keeps every pair of conflicting statements in order."""
    pos = {id(l): k for k, l in enumerate(perm)}
    order = [perm.index(l) for l in seg]
    eff = [effects(l) for l in seg]
    for a in range(len(seg)):
        for b in range(a + 1, len(seg)):
            wa, ra, ca = eff[a]
            wb, rb, cb = eff[b]
            if ca or cb or wa & (rb | wb) or ra & wb:
                if order[a] > order[b]:
                    return False
    return True


class Template:
    def __init__(self, text, runs=0):
        self.parts, self.alts = [], {}
        pos = 0
        for n, m in enumerate(BLOCK.finditer(text)):
            self.parts.append(text[pos:m.start()])
            self.alts[f'alt{n}'] = [a.strip('\n') + '\n' if a.strip() else '' for a in m.group(1).split('/*OR*/')]
            self.parts.append(f'alt{n}')
            pos = m.end()
        self.parts.append(text[pos:])
        base = self.render({}, None, None, raw=True)
        m = re.search(r'(GEX_Target\([^)]*\)\n\{\n)((?:    [^\n]*;\n)+)', base)
        if not m:
            raise SystemExit('no local declaration block after GEX_Target')
        self.decls = [l.strip() for l in m.group(2).splitlines()]
        em = re.search(r'extern "C" \{\n((?:(?:extern [^\n]*|//[^\n]*)\n)+)', base)
        self.externs = [l for l in em.group(1).splitlines() if l.startswith('extern ')] if em else []
        self.runs = []
        if runs:
            lines = base.split('\n')
            body = base.index(m.group(0)) + len(m.group(0))
            first = base[:body].count('\n')
            i = first
            while i < len(lines) and len(self.runs) < runs:
                mm = SIMPLE.match(lines[i])
                if mm:
                    j = i
                    while j + 1 < len(lines) and SIMPLE.match(lines[j + 1]) and SIMPLE.match(lines[j + 1]).group(1) == mm.group(1):
                        j += 1
                    if j > i:
                        seg = lines[i:j + 1]
                        if len(seg) <= 4:
                            perms = [list(p) for p in itertools.permutations(seg)]
                        else:
                            perms = [seg] + [seg[:k] + [seg[k + 1], seg[k]] + seg[k + 2:] for k in range(len(seg) - 1)]
                        perms = [p for p in perms if keeps_dependencies(seg, p)]
                        if len(perms) > 1:
                            self.runs.append(('\n'.join(seg), perms))
                    i = j + 1
                else:
                    i += 1
            for n, (seg, perms) in enumerate(self.runs):
                self.alts[f'run{n}'] = ['\n'.join(p) for p in perms]

    def render(self, choice, decls, externs, raw=False):
        text = ''.join(self.alts[p][choice.get(p, 0)] if p in self.alts and p.startswith('alt') else p for p in self.parts)
        if raw:
            return text
        for n, (seg, perms) in enumerate(self.runs):
            text = text.replace(seg, self.alts[f'run{n}'][choice.get(f'run{n}', 0)], 1)
        m = re.search(r'(GEX_Target\([^)]*\)\n\{\n)((?:    [^\n]*;\n)+)', text)
        text = text[:m.start(2)] + ''.join('    ' + d + '\n' for d in decls) + text[m.end(2):]
        if self.externs:
            em = re.search(r'extern "C" \{\n((?:(?:extern [^\n]*|//[^\n]*)\n)+)', text)
            others = [l for l in em.group(1).splitlines() if not l.startswith('extern ')]
            text = text[:em.start(1)] + ''.join(l + '\n' for l in others + externs) + text[em.end(1):]
        return text


_WORKER = {}


def _init(path, runs, address, lang):
    _WORKER.update(t=Template(open(path).read(), runs), address=address, lang=lang)


def _score(state):
    ch, dc, ex = state
    t = _WORKER['t']
    try:
        r, rows = casediff.compare(_WORKER['address'], t.render(dict(ch), list(dc), list(ex)), _WORKER['lang'])
        return sum(casediff.mismatches(x, y) for _, x, y in rows), r['exact']
    except SystemExit:
        return 10 ** 9, False


def neighbours(t, choice, decls, externs, fixed, retype):
    """Every single change from the current state, labelled."""
    for k, alts in t.alts.items():
        if k not in fixed:
            for i in range(len(alts)):
                if i != choice.get(k, 0):
                    yield f'{k}={i}', {**choice, k: i}, decls, externs
    for i in range(len(decls)):
        for j in range(len(decls)):
            if i != j:
                d = decls[:]; d.insert(j, d.pop(i))
                yield f'move {i}->{j}', choice, d, externs
    for i, dcl in enumerate(decls):
        m = re.match(r'((?:unsigned )?(?:int|short|char)) (\w+);$', dcl)
        if m and (retype == '*' or m.group(2) in retype.split(',')):
            for ty in TYPES:
                if ty != m.group(1):
                    d = decls[:]; d[i] = f'{ty} {m.group(2)};'
                    yield f'retype {m.group(2)} {ty}', choice, d, externs
    for i in range(len(externs)):
        for j in range(len(externs)):
            if i != j:
                e = externs[:]; e.insert(j, e.pop(i))
                yield f'extern {i}->{j}', choice, decls, e


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('address')
    ap.add_argument('file')
    ap.add_argument('--lang', choices=['c', 'cpp'])
    ap.add_argument('--runs', type=int, default=0)
    ap.add_argument('--fixed', default='')
    ap.add_argument('--retype', default='*', help="locals whose type may change: '*' (all), '' (none) or a comma list")
    ap.add_argument('--jobs', type=int, default=1, help='score each neighbourhood in parallel and take its best change')
    a = ap.parse_args()
    address = a.address.lower().zfill(8)
    _init(a.file, a.runs, address, a.lang)
    t = _WORKER['t']
    fixed = set(filter(None, a.fixed.split(',')))
    choice, decls, externs = {}, list(t.decls), list(t.externs)
    cache = {}

    def key(ch, dc, ex):
        return tuple(sorted(ch.items())), tuple(dc), tuple(ex)

    out = re.sub(r'(\.alt)?\.cpp$', '', a.file) + '.best.cpp'
    best, exact = _score(key(choice, decls, externs))
    print('base', best, flush=True)

    if a.jobs > 1:
        from concurrent.futures import ProcessPoolExecutor
        with ProcessPoolExecutor(a.jobs, initializer=_init, initargs=(a.file, a.runs, address, a.lang)) as pool:
            while not exact:
                cands = [(w, ch, dc, ex) for w, ch, dc, ex in neighbours(t, choice, decls, externs, fixed, a.retype)
                         if key(ch, dc, ex) not in cache]
                keys = [key(ch, dc, ex) for _, ch, dc, ex in cands]
                for k, sc in zip(keys, pool.map(_score, keys, chunksize=4)):
                    cache[k] = sc
                top = min(((cache[k], w, ch, dc, ex) for k, (w, ch, dc, ex) in zip(keys, cands)),
                          key=lambda r: (r[0][0], not r[0][1]), default=None)
                if not top or not (top[0][0] < best or (top[0][1] and not exact)):
                    break
                (best, exact), w, choice, decls, externs = top
                open(out, 'w').write(t.render(choice, decls, externs))
                print(w, best, 'EXACT' if exact else '', flush=True)
    else:
        while not exact:
            improved = False
            for w, ch, dc, ex in neighbours(t, choice, decls, externs, fixed, a.retype):
                k = key(ch, dc, ex)
                if k not in cache:
                    cache[k] = _score(k)
                s, e = cache[k]
                if s < best or (e and not exact):
                    best, exact, choice, decls, externs = s, e, ch, dc, ex
                    open(out, 'w').write(t.render(choice, decls, externs))
                    print(w, best, 'EXACT' if exact else '', flush=True)
                    improved = True
                    break
            if not improved:
                break
    open(out, 'w').write(t.render(choice, decls, externs))
    print(('EXACT ' if exact else 'best ') + str(best), out)


if __name__ == '__main__':
    main()
