#!/usr/bin/env python3
"""Constrained Gex source families for reviewed assembly-derived contracts.
Generates inputs only; pc-decomp owns compilation, resolution and verification.
No flags, bindings, raw addresses, byte emitters or current source edits.
"""
import argparse, hashlib, itertools, json, pathlib


def equality_variants():
    # Opaque pointer identity or an explicit 32-bit bit-pattern hypothesis. Never
    # dereference a guessed GXObject layout. Called argument equals p on this path.
    styles = ('if', 'early', 'ternary', 'boolean', 'assign', 'else')
    locals_ = ('direct', 'pv', 'vp', 'register', 'declare-pv', 'declare-vp')
    for style, local, reverse, arg, kind, regparam in itertools.product(styles, locals_, (False, True), ('p', 'value'), ('void *', 'GXObject *', 'unsigned'), (False, True)):
        typ=kind; q='p';v='gPlayerObject_004a27fc';prefix=''
        if local!='direct':
            q='subject';v='value'
            prefix={
                'pv':f'{typ} subject=p; {typ} value=gPlayerObject_004a27fc;',
                'vp':f'{typ} value=gPlayerObject_004a27fc; {typ} subject=p;',
                'register':f'register {typ} subject=p; {typ} value=gPlayerObject_004a27fc;',
                'declare-pv':f'{typ} subject; {typ} value; subject=p; value=gPlayerObject_004a27fc;',
                'declare-vp':f'{typ} value; {typ} subject; subject=p; value=gPlayerObject_004a27fc;',
            }[local]
        lhs,rhs=(v,q) if reverse else (q,v)
        cond=f'{lhs} == {rhs}';call=f'FUN_0042cc70_Object_unk(0, {q if arg=="p" else v})'
        body={
            'if':f'if ({cond}) {call}; return 0;',
            'early':f'if ({lhs} != {rhs}) return 0; {call}; return 0;',
            'ternary':f'return ({cond}) ? ({call}, 0) : 0;',
            'boolean':f'int equal=({cond}); if(equal) {call}; return 0;',
            'assign':f'int equal; equal=({cond}); if(equal != 0) {call}; return 0;',
            'else':f'if ({lhs} != {rhs}) {{ }} else {{ {call}; }} return 0;',
        }[style]
        source=f'struct GXObject;\nextern "C" {{\nextern {typ} gPlayerObject_004a27fc;\nextern void __cdecl FUN_0042cc70_Object_unk(int, {typ});\nint __cdecl GEX_Target({"register " if regparam else ""}{typ} p) {{ {prefix} {body} }}\n}}\n'
        yield source, f'32-bit identity/cdecl call, no object dereference: {kind}; {style}/{local}; reverse={reverse}; call={arg}; register parameter={regparam}'


def accumulator_variants():
    # Hardware addition wraps mod 2^32. Keep every sum unsigned to avoid C++
    # signed-overflow UB; masked result fits signed int for signed-global variants.
    for style, local, reverse, mask, gtype, atype, regparam in itertools.product(('if','early','complement'),('current-first','argument-first','register-current','declarations'),(False,True),('and','shifts','remainder','subtract-high'),('unsigned','int'),('unsigned','int'),(False,True)):
        prefix={
            'current-first':'unsigned current=(unsigned)DAT_00456034; unsigned delta=(unsigned)amount;',
            'argument-first':'unsigned delta=(unsigned)amount; unsigned current=(unsigned)DAT_00456034;',
            'register-current':'register unsigned current=(unsigned)DAT_00456034; unsigned delta=(unsigned)amount;',
            'declarations':'unsigned result; unsigned delta; unsigned current; delta=(unsigned)amount; current=(unsigned)DAT_00456034;',
        }[local]
        summation='current + delta' if reverse else 'delta + current'
        result=f'result={summation};' if local=='declarations' else f'unsigned result={summation};'
        expr={'and':'result & 0x7fffffffu','shifts':'(result << 1) >> 1','remainder':'result % 0x80000000u','subtract-high':'result - (result & 0x80000000u)'}[mask]
        statement=f'{result} DAT_00456034={expr};'
        body={'if':f'if (current != 0xffffffffu) {{ {statement} }}',
              'early':f'if (current == 0xffffffffu) return; {{ {statement} }}',
              'complement':f'if (~current) {{ {statement} }}'}[style]
        source=f'extern "C" {{\nextern {gtype} DAT_00456034;\nvoid __cdecl GEX_Target({"register " if regparam else ""}{atype} amount) {{ {prefix} {body} }}\n}}\n'
        yield source, f'32-bit sentinel/update, unsigned modular sum, mask, no store for -1: {style}/{local}/{mask}; reverse={reverse}; global={gtype}; argument={atype}; register parameter={regparam}'


def cleanup_variants(detail):
    from search_feedback import cleanup_evidence
    evidence=cleanup_evidence(detail)
    if (evidence['firstTarget'],evidence['flagAddress'],evidence['tailTarget'])!=(0x0044e7e0,0x00461138,0x0044e920):
        raise ValueError('Pinned targets differ from the reviewed Gex profile')
    # Prioritize architectural live-out preservation BEFORE cosmetic variants.
    # A 32-bit word return is a hypothesis, not recovered original C types.
    for family,style,flagtype in itertools.product(('eax-liveout','observable-byte'),('if','early','ternary'),('char','unsigned char')):
        # Both families preserve the observed return-register bits. The second
        # asks for one explicit observable byte read via a qualified lvalue; it
        # does not claim the original global was declared volatile, add accesses,
        # or infer concurrency/synchronization guarantees.
        flag='DAT_00461138' if family=='eax-liveout' else f'(*(volatile {flagtype} *)&DAT_00461138)'
        body={'if':f'if ({flag} != 0) return FUN_0044e920(); return result;',
              'early':f'if ({flag} == 0) return result; return FUN_0044e920();',
              'ternary':f'return {flag} != 0 ? FUN_0044e920() : result;'}[style]
        source=f'extern "C" {{\nextern unsigned __cdecl FUN_0044e7e0(void);\nextern unsigned __cdecl FUN_0044e920(void);\nextern {flagtype} DAT_00461138;\nunsigned __cdecl GEX_Target(void) {{ unsigned result=FUN_0044e7e0(); {body} }}\n}}\n'
        yield {'source':source,'family':family,'hypothesis':f'{family}: first helper before one byte read; preserve first/tail result bits; {style}/{flagtype}. Return and access-qualification hypotheses, not original ABI/type proof.'}


def variants(entry, limit=96, detail=None):
    if not 1<=limit<=256:raise ValueError('Candidate limit must be 1–256')
    if entry=='0044c690':
        if detail is None or detail.get('entry')!=entry:raise ValueError('Fresh detail required for live-out hypotheses')
        return [dict(v,id=f'v{i:03d}') for i,v in enumerate(itertools.islice(cleanup_variants(detail),limit))]
    if entry not in ('0042dcf0','0040bc50'):raise ValueError('No reviewed semantic family for this target')
    # Stratified deterministic selection reaches all structural families rather
    # than spending the entire budget on adjacent cosmetic variants.
    items=list(equality_variants() if entry=='0042dcf0' else accumulator_variants())
    selected=[];seen=set()
    # Odd stride is coprime to these power-of-two/three family sizes.
    stride=37
    for i in range(len(items)):
        source,hypothesis=items[(i*stride)%len(items)]
        key=hashlib.sha256(source.encode()).hexdigest()
        if key in seen:continue
        seen.add(key);selected.append({'id':f'v{len(selected):03d}','source':source,'hypothesis':hypothesis})
        if len(selected)==limit:break
    return selected


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--project',type=pathlib.Path,required=True);p.add_argument('--detail',type=pathlib.Path,required=True);p.add_argument('--output',type=pathlib.Path,required=True);p.add_argument('--limit',type=int,default=96);p.add_argument('--seconds',type=int,default=600);p.add_argument('--keep-compiler-warm',action='store_true');p.add_argument('--feedback',type=pathlib.Path,help='Retained search report.json, for exit-provenance diagnostics only');a=p.parse_args()
    if not 1<=a.limit<=256 or not 10<=a.seconds<=600:p.error('Bounds: 1–256 candidates, 10–600 seconds')
    f=json.loads(a.detail.read_text());configpath=a.project/'project.json';config=json.loads(configpath.read_text());path=a.project/'src/functions'/(f['entry']+'.cpp')
    manifest={'version':1,'functionId':f['id'],'expectedBinaryHash':config['sha256'],'expectedConfigHash':hashlib.sha256(configpath.read_bytes()).hexdigest(),'expectedSourceHash':hashlib.sha256(path.read_bytes()).hexdigest() if path.exists() else 'missing','maxSeconds':a.seconds,'candidates':variants(f['entry'],a.limit,detail=f)}
    if f['entry']=='0044c690':
        from search_feedback import cleanup_evidence, feedback
        plan={'evidence':cleanup_evidence(f),'priority':['eax-liveout','observable-byte'],'familyDuplicateLimit':2,
              'limitation':'Empirical family saturation can skip an unseen exact variant; skipped inputs stay retained, never reported as tested.'}
        manifest['familyDuplicateLimit']=2
        if a.feedback:
            import re
            report=json.loads(a.feedback.read_text());best=report['bestCandidate'];cid=best['id']
            if report['functionId']!=f['id'] or not re.fullmatch(r'[a-zA-Z0-9_-]{1,80}',cid):raise ValueError('Feedback target/identity mismatch')
            from search_feedback import instructions
            original=b''.join(row['bytes'] for row in instructions(f['originalAssembly']))
            if report['verifiedAttempt']['match']['originalBytesHash']!=hashlib.sha256(original).hexdigest():raise ValueError('Feedback original-byte basis mismatch')
            directory=a.feedback.parent/cid
            if hashlib.sha256((directory/'resolved.bin').read_bytes()).hexdigest()!=best['resolvedHash']:raise ValueError('Feedback output hash mismatch')
            from search_feedback import relocated_listing
            resolved_assembly=relocated_listing((directory/'assembly.txt').read_text(),(directory/'resolved.bin').read_bytes(),int(f['entry'],16))
            plan['feedback']=feedback(f['originalAssembly'],resolved_assembly)
            from search_feedback import require_new_liveout_hypothesis
            require_new_liveout_hypothesis(report,plan['feedback'])
            plan['feedbackReportSha256']=hashlib.sha256(a.feedback.read_bytes()).hexdigest()
        with a.output.with_suffix('.plan.json').open('x') as out:json.dump(plan,out,indent=2)
    elif a.feedback:p.error('No reviewed feedback adapter for this profile')
    if a.keep_compiler_warm:manifest['keepCompilerWarm']=True
    with a.output.open('x') as out:json.dump(manifest,out,indent=2);out.write('\n')
    print(f"Generated {len(manifest['candidates'])} bounded candidates for {f['entry']}; no compiler/provider calls or source edits")

if __name__=='__main__':main()
