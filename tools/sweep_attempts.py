#!/usr/bin/env python3
"""sweep.py: probe the best recorded attempt source of every unmatched game
function (< 0x449000) and report the ones that are now exact (DB read-only)."""
import sys, json, sqlite3, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__))); import probe
W = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), '.work', 'attempts')
db = sqlite3.connect('file:' + os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), '.work', 'decomp.db') + '?mode=ro', uri=True)
rows = []
for rid, body in db.execute("select id, body from records where resource='functions'"):
    f = json.loads(body); a = f['address']['canonical']
    if f['status'] in ('ExactMatch', 'Library') or int(a, 16) >= 0x449000: continue
    hist = sorted([h for h in (f.get('attemptHistory') or []) if os.path.exists(f"{W}/{h['id']}/source.cpp")], key=lambda h: -(h.get('bestScore') or 0))
    rows.append((a, [h['id'] for h in hist[:3]]))
for a, ids in rows:
    try: p = probe.Probe(a)
    except Exception as e: print(a, 'probe error', e); continue
    for i in ids:
        src = open(f'{W}/{i}/source.cpp').read()
        for lang in ('cpp', 'c'):
            try: r = p.measure(src, lang)
            except Exception as e: continue
            if r['exact']:
                print('EXACT', a, i, lang, flush=True); break
        else: continue
        break
print('done', len(rows))
