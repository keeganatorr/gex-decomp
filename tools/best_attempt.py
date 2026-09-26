#!/usr/bin/env python3
"""dbsrc.py ADDR: copy the best attempt's source (matchAttemptId, else highest
bestScore in attemptHistory) to ADDR.db.cpp. DB opened read-only."""
import sys, json, sqlite3, os
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
a = sys.argv[1].lower().zfill(8); W = os.path.join(ROOT, '.work', 'attempts')
db = sqlite3.connect('file:' + os.path.join(ROOT, '.work', 'decomp.db') + '?mode=ro', uri=True)
for rid, body in db.execute("select id, body from records where resource='functions'"):
    f = json.loads(body)
    if f['address']['canonical'] != a: continue
    hist = [h for h in (f.get('attemptHistory') or []) if os.path.exists(f"{W}/{h['id']}/source.cpp")]
    best = f.get('matchAttemptId')
    if not best or not os.path.exists(f'{W}/{best}/source.cpp'):
        best = max(hist, key=lambda h: h.get('bestScore') or 0)['id'] if hist else None
    if not best: print(a, 'no attempt source'); break
    src = open(f'{W}/{best}/source.cpp').read(); open(f'{a}.db.cpp', 'w').write(src)
    print(f"{a} mp={f.get('matchPercent')} attempt={best} -> {a}.db.cpp"); break
