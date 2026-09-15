// Prepare only freshly imported scratch programs. FID analyzer always disabled.
// @category CRT.FID
import java.io.*;
import java.nio.file.*;
import java.util.*;
import com.google.gson.*;
import ghidra.feature.fid.service.FidService;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class CrtFidPrepare extends CrtFidSupport {
    @Override protected void run() throws Exception {
        String mode = getScriptArgs()[0];
        boolean library = mode.equals("library");
        guard(library ? "crt-library" : "crt-target");
        onlyDatabase(false);
        setAnalysisOption(currentProgram, "Function ID", "false");
        var options = getCurrentAnalysisOptionsAndValues(currentProgram);
        for (String option : List.of("Demangler Microsoft", "Demangler GNU", "PDB", "PDB Universal"))
            if (options.containsKey(option)) setAnalysisOption(currentProgram, option, "false");
        if (!mode.equals("library") && !mode.equals("target")) throw new IOException("unknown preparation mode");
        if (currentProgram.getOptions(Program.ANALYSIS_PROPERTIES).getBoolean("Function ID", true))
            throw new IOException("could not disable FID analyzer");
        // Headless is always -noanalysis: failures before here cannot enable a default analyzer run.
        analyzeAll(currentProgram);
        if (library) canonical();
        else extents();
    }

    private void canonical() throws Exception {
        String object = currentProgram.getName();
        if (!object.matches("[0-9a-f]{64}\\.obj")) throw new IOException("non-content-addressed object");
        String sha = object.substring(0, 64);
        if (!sha256(root.resolve("objects/" + object)).equals(sha) ||
            !currentProgram.getExecutableSHA256().equals(sha)) throw new IOException("object hash mismatch");
        JsonArray names = readJson("manifest.json").getAsJsonObject().getAsJsonObject("objects")
            .getAsJsonObject(sha).getAsJsonArray("canonicalSymbols");
        Map<Address, List<String>> byAddress = new TreeMap<>();
        List<String> missing = new ArrayList<>();
        for (JsonElement n : names) {
            String name = n.getAsString();
            List<Symbol> symbols = currentProgram.getSymbolTable().getGlobalSymbols(name);
            List<Symbol> local = new ArrayList<>();
            for (Symbol s : symbols) {
                if (!s.isExternal() && currentProgram.getMemory().contains(s.getAddress()) &&
                    currentProgram.getMemory().getBlock(s.getAddress()).isExecute()) local.add(s);
            }
            if (local.size() != 1) { missing.add(name); continue; }
            byAddress.computeIfAbsent(local.get(0).getAddress(), k -> new ArrayList<>()).add(name);
        }
        List<Map<String, Object>> functions = new ArrayList<>();
        FidService service = new FidService();
        for (var item : byAddress.entrySet()) {
            Address address = item.getKey();
            Collections.sort(item.getValue());
            String name = item.getValue().get(0); // deterministic primary; preserve other aliases
            Function f = getFunctionAt(address);
            if (f == null) {
                disassemble(address);
                f = createFunction(address, name);
            }
            if (f == null) throw new IOException("could not define canonical symbol " + name);
            f.setName(name, SourceType.IMPORTED);
            Map<String, Object> row = new LinkedHashMap<>();
            row.put("entry", address.toString());
            row.put("name", name);
            row.put("aliases", item.getValue());
            row.put("bodySize", f.getBody().getNumAddresses());
            row.put("hash", hash(service.hashFunction(f)));
            functions.add(row);
        }
        if (!missing.isEmpty()) throw new IOException("unresolved canonical symbols: " + missing);
        output("canonical/" + sha + ".json", Map.of("objectSha256", sha, "functions", functions,
            "analysisOptions", getCurrentAnalysisOptionsAndValues(currentProgram)));
    }

    private void extents() throws Exception {
        List<Map<String, Object>> applied = new ArrayList<>();
        // Only explicitly true extents are allowed to alter function definitions.
        // Do this after analysis; never let analysis expand supplied bodies afterward.
        for (JsonElement element : readJson("extents.json").getAsJsonArray()) {
            JsonObject row = element.getAsJsonObject();
            if (!row.get("extentVerified").getAsBoolean()) continue;
            Address start = toAddr(row.get("entry").getAsString());
            long size = row.get("size").getAsLong();
            Address end = start.addNoWrap(size - 1);
            AddressSet body = new AddressSet(start, end);
            if (!currentProgram.getMemory().getLoadedAndInitializedAddressSet().contains(body))
                throw new IOException("extent is not loaded initialized memory: " + start);
            var block = currentProgram.getMemory().getBlock(start);
            if (block == null || !block.isExecute() || !block.contains(end))
                throw new IOException("extent not in one executable block: " + start);
            Function existing = getFunctionAt(start);
            var overlapping = currentProgram.getFunctionManager().getFunctionsOverlapping(body);
            while (overlapping.hasNext()) {
                Function other = overlapping.next();
                if (existing == null || !other.equals(existing))
                    throw new IOException("verified extent overlaps another function: " + start);
            }
            // Disassemble constrained to this range; do not infer a function extent from flow.
            var cmd = new ghidra.app.cmd.disassemble.DisassembleCommand(start, body, true);
            if (!cmd.applyTo(currentProgram, monitor)) throw new IOException("extent disassembly failed");
            Address cursor = start;
            while (cursor.compareTo(end) <= 0) {
                Instruction instruction = getInstructionAt(cursor);
                if (instruction == null || instruction.getMaxAddress().compareTo(end) > 0)
                    throw new IOException("extent contains gaps or partial instructions: " + cursor);
                if (instruction.getMaxAddress().equals(end)) break;
                cursor = instruction.getMaxAddress().next();
            }
            if (existing != null) existing.setBody(body);
            else currentProgram.getFunctionManager().createFunction(null, start, body, SourceType.USER_DEFINED);
            applied.add(Map.of("entry", start.toString(), "size", size, "extentVerified", true));
        }
        output("target-prepared.json", Map.of("appliedExtents", applied,
            "functionCount", currentProgram.getFunctionManager().getFunctionCount(),
            "targetSha256", currentProgram.getExecutableSHA256(), "fidAnalyzerEnabled", false,
            "analysisOptions", getCurrentAnalysisOptionsAndValues(currentProgram)));
    }
}
