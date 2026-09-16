"""Conservative, bounded x86 EAX exit-provenance diagnostics, not ABI proofs.
Unsupported instructions, indirect control flow and cycles fail closed. No compiler
or provider is invoked. Reviewed project-specific templates consume these facts.
"""
import re

INSTRUCTION=re.compile(r'^\s*([0-9a-fA-F]+):\s+((?:[0-9a-fA-F]{2}\s+)+)\s*(\S+)([^\n]*)$',re.M)
ALIASES={'%eax','%ax','%al','%ah'}

def instructions(listing):
    if len(listing)>1024*1024:raise ValueError('Unbounded listing')
    rows=[{'address':int(m[1],16),'bytes':bytes.fromhex(m[2]),'op':m[3],'operands':m[4].split('#')[0].split('<')[0].strip()} for m in INSTRUCTION.finditer(listing)]
    if not 1<=len(rows)<=64:raise ValueError('Expected 1–64 instructions')
    for a,b in zip(rows,rows[1:]):
        if a['address']+len(a['bytes'])!=b['address']:raise ValueError('Noncontiguous or duplicate instruction listing')
    return rows

def direct(operand):
    if not re.fullmatch(r'0x[0-9a-fA-F]+',operand):raise ValueError('Indirect/unsupported transfer')
    return int(operand,16)

def eax_exits(listing):
    """Track a call-produced architectural value, including partial-register kills.
    This does NOT infer that callers consume EAX or establish callee C prototypes.
    """
    rows=instructions(listing);by_addr={r['address']:i for i,r in enumerate(rows)}
    work=[(0,'entry-eax',())];exits=[];steps=0
    while work:
        i,value,path=work.pop();steps+=1
        if steps>256 or i in path:raise ValueError('Cyclic/unbounded control flow')
        if not 0<=i<len(rows):raise ValueError('Fall-through past retained extent')
        r=rows[i];op=r['op'];args=r['operands'];path=path+(i,)
        if op in ('call','calll'):
            direct(args);value='call@'+format(r['address'],'x')
        elif op in ('ret','retl'):
            if args:raise ValueError('Unsupported stack-cleanup return')
            exits.append({'exit':'return','address':r['address'],'eax':value});continue
        elif op in ('jmp','jmpl','je','jne'):
            target=direct(args)
            if target not in by_addr:
                if op not in ('jmp','jmpl'):raise ValueError('Conditional exit outside body')
                exits.append({'exit':'tail','address':r['address'],'eax':'tail-callee','target':target});continue
            work.append((by_addr[target],value,path))
            if op in ('jmp','jmpl'):continue
        elif op in ('cmpb','cmpw','cmpl','testb','testw','testl','nop','nopl','pushl'):
            pass  # No EAX write.
        elif op in ('movb','movw','movl','xorb','xorw','xorl','andb','andw','andl','orb','orw','orl','addl','subl','incl','decl','popl'):
            if args.split(',')[-1].strip() in ALIASES:value='modified@'+format(r['address'],'x')
        else:raise ValueError('Unsupported instruction: '+op)
        work.append((i+1,value,path))
    return exits

def cleanup_evidence(detail):
    if not detail.get('extentVerified') or not detail.get('ghidraBytesEqualOriginal'):raise ValueError('Unverified/edited function detail')
    rows=instructions(detail['originalAssembly'])
    # Reviewed template only; don't apply this reconstruction to arbitrary CFGs.
    if [r['op'] for r in rows]!=['calll','cmpb','je','jmp','retl']:raise ValueError('Not the reviewed conditional-cleanup template')
    if rows[0]['address']!=int(detail['entry'],16) or sum(len(r['bytes']) for r in rows)!=detail['size']:raise ValueError('Detail extent mismatch')
    if direct(rows[2]['operands'])!=rows[4]['address']:raise ValueError('Wrong conditional destination')
    match=re.fullmatch(r'\$0x0,\s*(0x[0-9a-fA-F]+)',rows[1]['operands'])
    if not match:raise ValueError('Not a zero comparison of an absolute byte')
    exits=eax_exits(detail['originalAssembly'])
    if not any(e['exit']=='return' and e['eax']=='call@'+format(rows[0]['address'],'x') for e in exits):raise ValueError('No preserved first-call EAX exit')
    return {'kind':'architectural-exit-provenance','isAbiProof':False,'firstTarget':direct(rows[0]['operands']),
            'tailTarget':direct(rows[3]['operands']),'flagAddress':int(match[1],16),'flagBits':8,'exits':exits,
            'hypothesis':'Preserve the first helper EAX value on the zero-flag exit and the tail callee result otherwise; original C return types remain unproven.'}

def relocated_listing(listing,resolved,entry):
    """Lift direct transfers using RESOLVED bytes, never zero COFF placeholders.
    LLVM supplies extents/opcodes/register operands. Bounded diagnostics only.
    """
    rows=instructions(listing);base=rows[0]['address']
    if sum(len(r['bytes']) for r in rows)!=len(resolved):raise ValueError('Resolved/LLVM extent mismatch')
    lifted=[]
    for row in rows:
        offset=row['address']-base;size=len(row['bytes']);data=resolved[offset:offset+size];op=row['op'];args=row['operands']
        if op in ('call','calll','jmp','jmpl','je','jne'):
            if op in ('call','calll','jmp','jmpl'):
                expected=0xe8 if op in ('call','calll') else 0xe9
                if size!=5 or data[0]!=expected:raise ValueError('Unsupported resolved transfer encoding')
                displacement=int.from_bytes(data[1:5],'little',signed=True)
            elif size==2 and data[0]==(0x74 if op=='je' else 0x75):displacement=int.from_bytes(data[1:2],'little',signed=True)
            elif size==6 and data[:2]==(b'\x0f\x84' if op=='je' else b'\x0f\x85'):displacement=int.from_bytes(data[2:6],'little',signed=True)
            else:raise ValueError('Unsupported resolved conditional encoding')
            args=f'0x{(entry+offset+size+displacement)&0xffffffff:x}'
        lifted.append(f'{entry+offset:x}: '+data.hex(' ')+'  '+op+' '+args)
    return '\n'.join(lifted)+'\n'


def require_new_liveout_hypothesis(report,diagnostic):
    tried=any(report.get('families',{}).get(name,{}).get('distinctOutputs',0)>0
              for name in ('eax-liveout','observable-byte'))
    if tried or not diagnostic['lostCallResultOnReturn']:
        raise ValueError('Live-out hypothesis already explored or no call-result loss detected; no new reviewed hypothesis. Refusing a cosmetic retry.')


def feedback(original,candidate):
    before=eax_exits(original);after=eax_exits(candidate)
    preserved=lambda es:any(e['exit']=='return' and e['eax'].startswith('call@') for e in es)
    return {'isProof':False,'originalExits':before,'candidateExits':after,
            'lostCallResultOnReturn':preserved(before) and not preserved(after),
            'note':'Architectural EAX difference, not proof that the original API returned an integer.'}
