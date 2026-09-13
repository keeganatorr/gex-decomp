#!/usr/bin/env python3
"""Synthetic scanner/runner checks. No live service, Wine, game bytes or model calls."""
import hashlib
import json
import os
import pathlib
import shutil
import subprocess
import tempfile

SOURCE = pathlib.Path(__file__).resolve().parents[1]
with tempfile.TemporaryDirectory(prefix='gex-backup-tools-') as directory:
    root = pathlib.Path(directory)/'project'
    backup = pathlib.Path(directory)/'backup'
    (root/'scripts').mkdir(parents=True)
    (root/'src/functions').mkdir(parents=True)
    (root/'.work/ten-functions').mkdir(parents=True)
    (backup/'src/functions').mkdir(parents=True)
    for script in ['scan-backup', 'verify-backup']:
        shutil.copy2(SOURCE/'scripts'/script,root/'scripts'/script)
    samples = {
        '00401000': 'extern "C" int DAT_00402000;\nextern "C" int PDA_CDECL FUN_00401000(){ return DAT_00402000; }',
        '00401100': 'extern "C" __declspec(naked) void FUN_00401100(){__asm {ret}}',
        '00401200': 'void FUN_00401200() {}',
        '00401300': 'unknown_type FUN_00401300() {return 0;}',
        '00401400': 'int DAT_00402000=42; int FUN_00401400(){return DAT_00402000;}',
    }
    for address,body in samples.items():
        (backup/'src/functions'/f'FUN_{address}.cpp').write_text('#include "../../include/game_types.h"\n'+body+'\n')
    inventory={'atlas':[{'rows':[{'address':a,'size':64} for a in samples]}]}
    (root/'.work/ten-functions/live-rpc.json').write_text(json.dumps(inventory))
    before={p:p.read_bytes() for p in (backup/'src/functions').glob('*.cpp')}
    subprocess.run(['python3',root/'scripts/scan-backup'],check=True,capture_output=True,
                   env={**os.environ,'PC_DECOMP_BACKUP_ROOT':str(backup)})
    work=root/'.work/backup-import'; audit=json.loads((work/'audit.json').read_text())
    reasons={r['address']:r['reason'] for r in audit}
    assert reasons=={'00401000':'staged','00401100':'assembly/raw emission; reference only',
                     '00401200':'placeholder stub for nontrivial original body',
                     '00401300':'unresolved syntax/types/declarations',
                     '00401400':'global definition needs separate data reconstruction'}, reasons
    assert all(p.read_bytes()==data for p,data in before.items())
    selected=next(r for r in audit if r['reason']=='staged')
    assert selected['bindings']=={'_DAT_00402000':'00402000'}
    assert 'extern int DAT_00402000' in (root/selected['candidate']).read_text()

    # Isolated CLI peer: repeated stable IDs only query their retained result.
    (root/'project.json').write_text('{}')
    (root/'scripts/backend').write_text('#!/usr/bin/env python3\nprint(\'{"health":{"ghidra":{"analysisEpoch":"synthetic"}}}\')\n')
    (root/'scripts/verify').write_text('''#!/usr/bin/env python3
import hashlib,json,pathlib,sys
root=pathlib.Path(__file__).resolve().parents[1]
a,command=sys.argv[1:]; source=(root/'src/functions'/f'{a}.cpp').read_bytes()
path=root/'.work/fake-commands.json'; state=json.loads(path.read_text()) if path.exists() else {}
if command not in state:
 state[command]={'executions':1,'queries':0,'source':hashlib.sha256(source).hexdigest()}
else: state[command]['queries']+=1
path.write_text(json.dumps(state))
if not (root/'.work/allow-result').exists(): sys.exit(3)
failed=(root/'.work/force-failure').exists()
print('Synthetic checkpoint')
print(json.dumps({'task':{'result':{'id':'synthetic-attempt','sourceRevision':state[command]['source'],'bestScore':0 if failed else 100,'failureReason':'missing binding' if failed else '', 'compileResult':'Failed/blocked' if failed else 'ExactMatch','match':{'verifiedExact':not failed}}}}))
sys.exit(2 if failed else 0)
''')
    for name in ['backend','verify']: (root/'scripts'/name).chmod(0o700)
    call=['python3',root/'scripts/verify-backup']
    result=subprocess.run(call,capture_output=True,text=True)
    assert result.returncode!=0 and 'NO automatic new intent' in result.stderr
    commands=json.loads((root/'.work/fake-commands.json').read_text()); assert len(commands)==1
    first_id=next(iter(commands))
    (root/'.work/allow-result').touch()
    subprocess.run(call,check=True,capture_output=True)
    commands=json.loads((root/'.work/fake-commands.json').read_text())
    assert len(commands)==1 and commands[first_id]=={'executions':1,'queries':1,'source':commands[first_id]['source']}
    subprocess.run(call,check=True,capture_output=True)
    assert json.loads((root/'.work/fake-commands.json').read_text())==commands
    (root/'project.json').write_text('{"extraBinding":"changed"}')
    subprocess.run(call,check=True,capture_output=True)
    assert len(json.loads((root/'.work/fake-commands.json').read_text()))==2
    (root/'src/functions/00401000.cpp').write_text('// user edit\n')
    (root/'project.json').write_text('{"extraBinding":"changed-again"}')
    result=subprocess.run(call,capture_output=True,text=True)
    assert result.returncode!=0 and 'external edit' in result.stderr
    # A resolved missing binding is a new configuration, so even all-failed
    # selections must be reconsidered. Re-running an unchanged failure is not.
    (work/'run.json').unlink();(root/'src/functions/00401000.cpp').unlink()
    (root/'.work/fake-commands.json').unlink();(root/'.work/force-failure').touch()
    subprocess.run(call,check=True,capture_output=True)
    assert not (root/'src/functions/00401000.cpp').exists()
    failed_commands=json.loads((root/'.work/fake-commands.json').read_text())
    subprocess.run(call,check=True,capture_output=True)
    assert json.loads((root/'.work/fake-commands.json').read_text())==failed_commands
    (root/'.work/force-failure').unlink();(root/'project.json').write_text('{"missingBinding":"resolved"}')
    subprocess.run(call,check=True,capture_output=True)
    assert (root/'src/functions/00401000.cpp').exists()
    assert len(json.loads((root/'.work/fake-commands.json').read_text()))==2
print('Backup tools passed: safe adaptation, backup preservation, uncertainty query/recovery, idempotency, config refresh and external-edit refusal.')
