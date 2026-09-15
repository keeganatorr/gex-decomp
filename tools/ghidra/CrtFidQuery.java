// Read-only FidService query. Never invokes ApplyFidEntriesCommand or an analyzer.
// @category CRT.FID
import java.io.*;
import java.util.*;
import com.google.gson.*;
import ghidra.feature.fid.db.*;
import ghidra.feature.fid.hash.FidHashQuad;
import ghidra.feature.fid.service.*;
import ghidra.program.model.listing.*;

public class CrtFidQuery extends CrtFidSupport {
    private static final String TARGET = "e1fd63ecb09fca29d63286e22447752dcb120d7e682f8759d1021776f7698b86";

    private List<Map<String, Object>> relations(Function f, FunctionRecord record,
            FidService service, FidQueryService query, boolean children) throws Exception {
        List<Function> relatives = children ? FidProgramSeeker.getChildren(f, true) : FidProgramSeeker.getParents(f, true);
        relatives.sort(Comparator.comparing(r -> r.getEntryPoint().toString()));
        List<Map<String, Object>> evidence = new ArrayList<>();
        for (Function relative : relatives) {
            monitor.checkCancelled();
            FidHashQuad q = service.hashFunction(relative);
            Map<String, Object> row = new LinkedHashMap<>();
            row.put("entry", relative.getEntryPoint().toString());
            row.put("hash", hash(q));
            row.put("fullRelationInCustomDatabase", q != null && (children ?
                query.getSuperiorFullRelation(record, q) : query.getInferiorFullRelation(q, record)));
            evidence.add(row);
        }
        return evidence;
    }

    @Override protected void run() throws Exception {
        guard("crt-target");
        if (!sha256(root.resolve("target.exe")).equals(TARGET) ||
            !currentProgram.getExecutableSHA256().equals(TARGET)) throw new IOException("wrong target");
        if (currentProgram.getOptions(Program.ANALYSIS_PROPERTIES).getBoolean("Function ID", true))
            throw new IOException("FID analyzer enabled");
        onlyDatabase(true);
        float threshold = Float.parseFloat(getScriptArgs()[0]);
        if (!Float.isFinite(threshold) || threshold < 0) throw new IOException("invalid score threshold");
        String beforeDb = sha256(root.resolve("crt.fidb"));
        long beforeModifications = currentProgram.getModificationNumber();
        Map<String, Long> verified = new TreeMap<>();
        for (JsonElement e : readJson("extents.json").getAsJsonArray()) {
            JsonObject r = e.getAsJsonObject();
            if (r.get("extentVerified").getAsBoolean()) verified.put(r.get("entry").getAsString(), r.get("size").getAsLong());
        }
        FidService service = new FidService();
        List<Map<String, Object>> results = new ArrayList<>();
        int unhashable = 0;
        try (FidQueryService query = service.openFidQueryService(currentProgram.getLanguage(), false)) {
            FidProgramSeeker seeker = service.getProgramSeeker(currentProgram, query, threshold);
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                monitor.checkCancelled();
                FidSearchResult found = seeker.searchFunction(f, monitor);
                if (found == null) { unhashable++; continue; }
                if (found.matches == null || found.matches.isEmpty()) continue;
                List<Map<String, Object>> matches = new ArrayList<>();
                Set<String> names = new TreeSet<>();
                for (FidMatch match : found.matches) {
                    FunctionRecord record = match.getFunctionRecord();
                    LibraryRecord library = query.getLibraryForFunction(record);
                    Map<String, Object> row = new LinkedHashMap<>();
                    row.put("name", record.getName());
                    row.put("libraryFamily", library.getLibraryFamilyName());
                    row.put("libraryVersion", library.getLibraryVersion());
                    row.put("libraryVariant", library.getLibraryVariant());
                    row.put("domainPath", record.getDomainPath());
                    row.put("libraryEntry", String.format("%08x", record.getEntryPoint()));
                    row.put("hash", hash(record));
                    row.put("score", match.getOverallScore());
                    row.put("primaryScore", match.getPrimaryFunctionCodeUnitScore());
                    row.put("matchMode", match.getPrimaryFunctionMatchMode().toString());
                    row.put("corroboration", Map.of(
                        "calleeScore", match.getChildFunctionCodeUnitScore(),
                        "parentScore", match.getParentFunctionCodeUnitScore(),
                        "calleePositive", match.getChildFunctionCodeUnitScore() > 0,
                        "parentPositive", match.getParentFunctionCodeUnitScore() > 0,
                        "callees", relations(f, record, service, query, true),
                        "parents", relations(f, record, service, query, false),
                        "meaning", "FidService aggregate relation scores, not independent verification"));
                    row.put("classification", "candidate");
                    names.add(record.getName());
                    matches.add(row);
                }
                matches.sort(Comparator.comparing(r -> r.get("name") + "|" + r.get("libraryVersion") + "|" + r.get("domainPath")));
                List<FunctionRecord> collisions = query.findFunctionsByFullHash(found.hashQuad.getFullHash());
                Set<String> collisionNames = new TreeSet<>();
                if (collisions != null) for (FunctionRecord r : collisions) collisionNames.add(r.getName());
                Map<String, Object> row = new LinkedHashMap<>();
                String entry = f.getEntryPoint().toString();
                row.put("entry", entry);
                row.put("observedName", f.getName());
                row.put("bodySize", f.getBody().getNumAddresses());
                row.put("extentVerified", verified.containsKey(entry));
                row.put("extentSource", verified.containsKey(entry) ? "supplied-verified-manifest" : "scratch-auto-analysis");
                row.put("hash", hash(found.hashQuad));
                row.put("tiny", found.hashQuad.getCodeUnitSize() < 24);
                row.put("classification", "candidate");
                row.put("matches", matches);
                row.put("ambiguity", Map.of("returnedRecords", matches.size(), "returnedNames", names,
                    "multipleNames", names.size() > 1, "fullHashRecords", collisions == null ? 0 : collisions.size(),
                    "fullHashNames", collisionNames, "scope", "selected-custom-database-only; FID service culls lower scores"));
                results.add(row);
            }
        }
        if (beforeModifications != currentProgram.getModificationNumber()) throw new IOException("query mutated program");
        if (!beforeDb.equals(sha256(root.resolve("crt.fidb")))) throw new IOException("query mutated database");
        output("query.json", Map.of("targetSha256", TARGET, "databaseSha256", beforeDb,
            "activeDatabases", List.of(root.resolve("crt.fidb").toString()), "fidAnalyzerEnabled", false,
            "programUnchanged", true, "scoreThreshold", threshold, "unhashableFunctions", unhashable,
            "functionCount", currentProgram.getFunctionManager().getFunctionCount(), "results", results));
    }
}
