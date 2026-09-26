#!/usr/bin/env bash
# solve.sh ADDR FILE: probe diff; perturb (cpp+c); local decl orders; perturb; statement hill-climb; perturb. Prints SOLVED:<file> on exact.
a=$1; f=$2; b=${f%.cpp}
python3 $(dirname $0)/probe.py $a $f -d 2>&1 | grep -v "^bindings" | head -${LINES_SHOWN:-14} | cut -c1-150
out=$(python3 $(dirname $0)/perturb.py $a $f --moves --volatile --languages cpp,c --write $b.best.cpp | tail -1); echo "perturb: $out"
case "$out" in *"100.0%"*) echo "SOLVED:$b.best.cpp"; exit 0;; esac
lp=$(python3 $(dirname $0)/lperm.py $a $f | tail -1); echo "lperm: $lp"
case "$lp" in "EXACT cpp"*) echo "SOLVED:$b.lp.cpp"; exit 0;; esac
# A C-only order usually has a C++ twin a few padding declarations away; that
# twin needs no functionOverrides entry, so look for it before settling for C.
case "$lp" in "EXACT c"*) out=$(python3 $(dirname $0)/perturb.py $a $b.lp.cpp --moves --languages cpp --write $b.lpcpp.cpp | tail -1); echo "perturb-lp-cpp: $out"
  case "$out" in *"100.0%"*) echo "SOLVED:$b.lpcpp.cpp"; exit 0;; esac; echo "SOLVED(c):$b.lp.cpp"; exit 0;; esac
out=$(python3 $(dirname $0)/perturb.py $a $b.lp.cpp --moves --languages cpp,c --write $b.best3.cpp | tail -1); echo "perturb-lp: $out"
case "$out" in *"100.0%"*) echo "SOLVED:$b.best3.cpp"; exit 0;; esac
# Save/restore runs: statement order and declaration order searched jointly.
jp=$(timeout 900 python3 $(dirname $0)/jointperm.py $a $f | tail -1); echo "jointperm: $jp"
case "$jp" in EXACT*) echo "SOLVED:$b.jp.cpp"; exit 0;; esac
# Expression shapes (ternary vs if clamps, abs(), compare spelling, operand
# order) move register allocation where padding cannot; see shapes.py.
sh=$(timeout 900 python3 $(dirname $0)/shapes.py $a $f | tail -1); echo "shapes: $sh"
case "$sh" in EXACT*) echo "SOLVED:$b.shape.cpp"; exit 0;; esac
out=$(python3 $(dirname $0)/perturb.py $a $b.shape.cpp --moves --languages cpp,c --write $b.best4.cpp | tail -1); echo "perturb-shape: $out"
case "$out" in *"100.0%"*) echo "SOLVED:$b.best4.cpp"; exit 0;; esac
st=$(python3 $(dirname $0)/stperm.py $a $f | tail -1); echo "stperm: $st"
[ "$st" = EXACT ] && { echo "SOLVED:$b.st.cpp"; exit 0; }
mv=$(timeout 600 python3 $(dirname $0)/mvperm.py $a $b.st.cpp | tail -1); echo "mvperm: $mv"
[ "$mv" = EXACT ] && { echo "SOLVED:$b.st.mv.cpp"; exit 0; }
[ -f $b.st.mv.cpp ] && cp $b.st.mv.cpp $b.st.cpp
bp=$(timeout 900 python3 $(dirname $0)/blockperm.py $a $b.st.cpp | tail -1); echo "blockperm: $bp"
[ "$bp" = EXACT ] && { echo "SOLVED:$b.st.bp.cpp"; exit 0; }
[ -f $b.st.bp.cpp ] && cp $b.st.bp.cpp $b.st.cpp
[ "$st" = EXACT ] && { echo "SOLVED:$b.st.cpp"; exit 0; }
out=$(python3 $(dirname $0)/perturb.py $a $b.st.cpp --moves --languages cpp,c --write $b.best2.cpp | tail -1); echo "perturb2: $out"
case "$out" in *"100.0%"*) echo "SOLVED:$b.best2.cpp"; exit 0;; esac
exit 2
