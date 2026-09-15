#!/usr/bin/env python3
"""Synthetic safety tests; optional read-only validation of retained integration reports."""
import argparse
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import tempfile
import unittest
from unittest.mock import patch, Mock

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location("crt_fid_tool", ROOT / "tools/crt_fid.py")
fid = importlib.util.module_from_spec(spec)
spec.loader.exec_module(fid)


def ar_member(name, data):
    header = name.encode().ljust(16) + b"0".ljust(12) + b"0".ljust(6) + b"0".ljust(6)
    header += b"100644".ljust(8) + str(len(data)).encode().ljust(10) + b"`\n"
    return header + data + (b"\n" if len(data) & 1 else b"")


def coff():
    # One executable section and two symbols: raw external function and undefined import.
    header = struct.pack("<HHIIIHH", 0x14c, 1, 0, 64, 2, 0, 0)
    section = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, 4, 60, 0, 0, 0, 0, 0x60000020)
    function = struct.pack("<8sIhHBB", b"\0\0\0\0\4\0\0\0", 0, 1, 0x20, 2, 0)
    undefined = struct.pack("<8sIhHBB", b"_other", 0, 0, 0x20, 2, 0)
    names = b"__canonical@4\0"
    return header + section + b"\x90\x90\x90\xc3" + function + undefined + struct.pack("<I", 4 + len(names)) + names


class SyntheticTests(unittest.TestCase):
    def setUp(self):
        base = ROOT / ".work/fid"
        self.assertFalse(base.is_symlink())
        base.mkdir(parents=True, exist_ok=True)
        self.temp = tempfile.TemporaryDirectory(prefix="synthetic-", dir=base)
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def test_short_and_long_names_duplicate_and_traversal(self):
        names = b"..\\build\\intel\\st_obj\\fpinit.obj\0../../escape.obj\0"
        second = names.index(b"../../")
        data = b"!<arch>\n" + ar_member("/", b"index") + ar_member("//", names)
        data += ar_member("/0", b"abc") + ar_member(f"/{second}", b"defg")
        data += ar_member("fpinit.obj/", b"abc") + ar_member("fpinit.obj/", b"xyz")
        rows = fid.archive_members(data)
        self.assertEqual(len(rows), 4)
        self.assertEqual(rows[0]["originalName"], "..\\build\\intel\\st_obj\\fpinit.obj")
        self.assertEqual(rows[1]["originalName"], "../../escape.obj")
        self.assertEqual(rows[0]["sha256"], rows[2]["sha256"])
        self.assertNotEqual(rows[2]["headerOffset"], rows[3]["headerOffset"])
        self.assertEqual(rows[3]["originalName"], "fpinit.obj")
        self.assertEqual(list(self.root.iterdir()), [])

    def test_gnu_long_names(self):
        rows = fid.archive_members(b"!<arch>\n" + ar_member("//", b"some/long.obj/\n") + ar_member("/0", b"x"))
        self.assertEqual(rows[0]["originalName"], "some/long.obj")

    def test_invalid_archives(self):
        good = b"!<arch>\n" + ar_member("x/", b"abc")
        bad = [b"!<thin>\n", good[:-1], good[:-3], b"!<arch>\nx", good[:66] + b"xx" + good[68:],
               b"!<arch>\n" + ar_member("/0", b"x"),
               b"!<arch>\n" + ar_member("#1/5", b"abcde"),
               b"!<arch>\n" + ar_member("//", b"hello\0") + ar_member("/2", b"x"),
               b"!<arch>\n" + ar_member("//", b"hello") + ar_member("/0", b"x"),
               b"!<arch>\n" + ar_member("//", b"x\0") + ar_member("//", b"x\0")]
        for data in bad:
            with self.subTest(data=data), self.assertRaises(ValueError):
                fid.archive_members(data)

    def test_raw_canonical_coff_name(self):
        self.assertEqual(fid.coff_symbols(coff()), ["__canonical@4"])

    def test_bad_coff_bounds_and_aux(self):
        original = coff()
        bad = [b"", original[:19], original[:-1], b"\x64\x86" + original[2:]]
        aux = bytearray(original)
        aux[64 + 17] = 255
        bad.append(bytes(aux))
        pointer = bytearray(original)
        struct.pack_into("<I", pointer, 8, 0xffffffff)
        bad.append(bytes(pointer))
        for data in bad:
            with self.subTest(data=data), self.assertRaises(ValueError):
                fid.coff_symbols(data)

    def test_extents_normalize_only_true_and_overlap(self):
        rows = [{"entry": "0x00400010", "size": 8, "extentVerified": False},
                {"entry": "00400000", "size": 32, "extentVerified": True}]
        normalized = fid.validate_extents(rows)
        self.assertEqual(normalized[1], {"entry": "00400010", "size": 8, "extentVerified": False})
        rows[0]["extentVerified"] = True
        with self.assertRaisesRegex(ValueError, "overlapping"):
            fid.validate_extents(rows)

    def test_bad_extents(self):
        base = {"entry": "00400000", "size": 8, "extentVerified": True}
        bad = [None, {}, [dict(base, extentVerified="true")], [dict(base, extentVerified=1)],
               [dict(base, size=True)], [dict(base, size=0)], [dict(base, size=-1)],
               [dict(base, size=2**32)], [dict(base, entry="../foo")], [dict(base, entry=0x400000)],
               [dict(base, extra=1)], [base, base]]
        for value in bad:
            with self.subTest(value=value), self.assertRaises(ValueError):
                fid.validate_extents(value)

    def test_output_scope_and_no_overwrite(self):
        run = fid.fresh_run("safe_1", self.root)
        self.assertEqual(run, self.root / ".work/fid/safe_1")
        with self.assertRaises(FileExistsError):
            fid.fresh_run("safe_1", self.root)
        for name in ("../escape", "a/b", ".hidden", "", "a b", "a" * 81):
            with self.assertRaises(ValueError):
                fid.fresh_run(name, self.root)
        (run.parent / "link").symlink_to(run, target_is_directory=True)
        with self.assertRaises(ValueError):
            fid.fresh_run("link", self.root)
        fid.write_json(run / "report.json", {"proof": False})
        with self.assertRaises(FileExistsError):
            fid.write_json(run / "report.json", {})

    def test_symlink_output_parent(self):
        (self.root / ".work").symlink_to(self.root, target_is_directory=True)
        with self.assertRaises(ValueError):
            fid.fresh_run("nope", self.root)

    def test_unapproved_archive_fails_before_launch_or_output(self):
        archive = self.root / "libc.lib"
        archive.write_bytes(b"!<arch>\n" + ar_member("fpinit.obj/", coff()))
        args = argparse.Namespace(archive=[archive])
        with patch.object(fid, "fresh_run") as create, patch.object(fid, "run_headless") as launch:
            with self.assertRaisesRegex(ValueError, "not approved"):
                fid.execute(args)
            create.assert_not_called()
            launch.assert_not_called()

    def test_target_pin_fails_before_launch(self):
        archive = self.root / "synthetic.lib"
        archive.write_bytes(b"!<arch>\n" + ar_member("fpinit.obj/", coff()))
        target = self.root / "wrong.exe"
        target.write_bytes(b"wrong")
        args = argparse.Namespace(archive=[archive], member=["fpinit.obj"], all_members=False,
                                  max_members=1, target=target)
        with patch.dict(fid.APPROVED_ARCHIVES, {fid.digest(archive.read_bytes()): "synthetic.lib"}), \
             patch.object(fid, "run_headless") as launch:
            with self.assertRaisesRegex(ValueError, "target SHA256"):
                fid.execute(args)
            launch.assert_not_called()

    def test_headless_isolation_and_timeout(self):
        run = fid.fresh_run("headless", self.root)
        proc = Mock(pid=123, wait=Mock(side_effect=[subprocess.TimeoutExpired("fake", 1), 0]))
        with patch.object(fid.subprocess, "Popen", return_value=proc) as popen, \
             patch.object(fid.os, "killpg") as kill:
            with self.assertRaises(subprocess.TimeoutExpired):
                fid.run_headless(run, Path("/opt/ghidra"), Path("/fake/java"),
                                 ["crt-target", "-readOnly", "-noanalysis"], "timeout", 1)
            kwargs = popen.call_args.kwargs
            self.assertEqual(kwargs["cwd"], run)
            self.assertTrue(kwargs["start_new_session"])
            self.assertEqual(kwargs["env"]["HOME"], str(run / "home"))
            self.assertIn(f"-Duser.home={run}/home", kwargs["env"]["_JAVA_OPTIONS"])
            self.assertNotIn("BASH_ENV", kwargs["env"])
            self.assertNotIn("GHIDRA_JAVA_OPTIONS", kwargs["env"])
            self.assertEqual(popen.call_args.args[0][1], "/proc/self/cwd/projects")
            kill.assert_called_once_with(123, fid.signal.SIGKILL)


def validate_report(path):
    report = json.loads(path.read_text())
    assert report["schemaVersion"] == 1 and report["kind"] == "crt-fid-candidates"
    assert report["status"] == "completed" and report["proof"] is False
    query = report["query"]
    assert query["targetSha256"] == fid.TARGET_SHA256
    assert query["fidAnalyzerEnabled"] is False and query["programUnchanged"] is True
    assert query["activeDatabases"] == [report["database"]["path"]]
    assert report["database"]["sha256"] == query["databaseSha256"] == report["generation"]["databaseSha256"]
    for item in report["artifacts"] + [report["target"], report["database"]]:
        actual = fid.identity(Path(item["path"]))
        assert actual["sha256"] == item["sha256"] and actual["size"] == item["size"], item["path"]
    for script in report["scripts"]:
        assert fid.digest((path.parent / "scripts" / script["name"]).read_bytes()) == script["sha256"]
    for archive in report["archives"]:
        assert archive["sha256"] in fid.APPROVED_ARCHIVES
        assert fid.identity(Path(archive["path"]))["sha256"] == archive["sha256"]
        for member in archive["members"]:
            assert member["objectFile"] == f"objects/{member['sha256']}.obj"
            assert fid.digest((path.parent / member["objectFile"]).read_bytes()) == member["sha256"]
    for row in query["results"]:
        assert row["classification"] == "candidate"
        assert row["tiny"] == (row["hash"]["codeUnitSize"] < 24)
        for match in row["matches"]:
            assert match["classification"] == "candidate" and match["provenance"]
            assert "callees" in match["corroboration"] and "parents" in match["corroboration"]
    semantic = {"generation": {k: v for k, v in report["generation"].items() if k != "databaseSha256"},
                "query": {k: v for k, v in query.items() if k not in ("databaseSha256", "activeDatabases")},
                "extents": report["extents"]["normalized"]}
    assert report["semanticSha256"] == fid.digest(json.dumps(semantic, sort_keys=True, separators=(",", ":")).encode())
    return report


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--report", type=Path)
    parser.add_argument("--compare", type=Path, help="same-input independent run report")
    args = parser.parse_args()
    if args.compare and not args.report:
        parser.error("--compare requires --report")
    result = unittest.TextTestRunner(verbosity=2).run(unittest.defaultTestLoader.loadTestsFromTestCase(SyntheticTests))
    if not result.wasSuccessful():
        raise SystemExit(1)
    if args.report:
        report = validate_report(args.report)
        print(f"Validated report: {args.report}")
        if args.compare:
            other = validate_report(args.compare)
            assert report["semanticSha256"] == other["semanticSha256"], "semantic results differ"
            assert report["scripts"] == other["scripts"], "scripts differ"
            assert report["tools"] == other["tools"], "tools differ"
            print(f"Independent-run semantic identity agrees: {report['semanticSha256']}")
