// Build a custom FID only from the selected scratch COFF imports.
// @category CRT.FID
import java.io.*;
import java.util.*;
import com.google.gson.*;
import ghidra.feature.fid.db.*;
import ghidra.feature.fid.service.*;
import ghidra.framework.model.DomainFile;

public class CrtFidBuild extends CrtFidSupport {
    @Override protected void run() throws Exception {
        guard("crt-library");
        onlyDatabase(false);
        FidFileManager manager = FidFileManager.getInstance();
        File destination = root.resolve("crt.fidb").toFile();
        if (destination.exists()) throw new IOException("database already exists");
        manager.createNewFidDatabase(destination);
        FidFile file = onlyDatabase(true);
        FidService service = new FidService();
        List<Map<String, Object>> libraries = new ArrayList<>();
        long total = 0;
        try (FidDB db = file.getFidDB(true)) {
            for (JsonElement element : readJson("manifest.json").getAsJsonObject().getAsJsonArray("archives")) {
                JsonObject archive = element.getAsJsonObject();
                String sha = archive.get("sha256").getAsString();
                String name = archive.get("approvedName").getAsString();
                Map<String, Set<String>> allowed = new TreeMap<>();
                List<DomainFile> programs = new ArrayList<>();
                for (JsonElement m : archive.getAsJsonArray("members")) {
                    if (!m.getAsJsonObject().has("objectFile")) continue;
                    String objectSha = m.getAsJsonObject().get("sha256").getAsString();
                    String object = objectSha + ".obj";
                    if (allowed.containsKey(object)) continue;
                    Set<String> names = new TreeSet<>();
                    for (JsonElement f : readJson("canonical/" + objectSha + ".json").getAsJsonObject().getAsJsonArray("functions"))
                        names.add(f.getAsJsonObject().get("name").getAsString());
                    allowed.put(object, names);
                    DomainFile program = state.getProject().getProjectData().getFile("/objects/" + object);
                    if (program == null) throw new IOException("missing program " + object);
                    programs.add(program);
                }
                if (programs.isEmpty()) continue;
                programs.sort(Comparator.comparing(DomainFile::getName));
                FidPopulateResult result = service.createNewLibraryFromPrograms(db, name, sha,
                    "raw-coff-canonical", programs,
                    pair -> allowed.getOrDefault(pair.first.getProgram().getName(), Set.of()).contains(pair.first.getName()),
                    currentProgram.getLanguageID(), null, List.of(), monitor);
                if (result == null) throw new IOException("no library result");
                Map<String, Object> row = new LinkedHashMap<>();
                row.put("name", name);
                row.put("archiveSha256", sha);
                row.put("attempted", result.getTotalAttempted());
                row.put("added", result.getTotalAdded());
                row.put("excluded", result.getTotalExcluded());
                Map<String, Integer> dispositions = new TreeMap<>();
                result.getFailures().forEach((k, v) -> dispositions.put(k.toString(), v));
                row.put("dispositions", dispositions);
                List<String> unresolved = new ArrayList<>();
                for (Location l : result.getUnresolvedSymbols()) unresolved.add(l.getFunctionName());
                Collections.sort(unresolved);
                row.put("unresolvedSymbols", unresolved);
                total += result.getTotalAdded();
                libraries.add(row);
            }
            if (total == 0) throw new IOException("no FID functions added");
            db.saveDatabase("isolated CRT FID", monitor);
        }
        output("generation.json", Map.of("libraries", libraries, "totalAdded", total,
            "databaseSha256", sha256(root.resolve("crt.fidb"))));
    }
}
