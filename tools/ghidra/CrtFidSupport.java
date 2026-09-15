// Shared scratch-only helpers for CRT FID scripts. No live project access.
// @category CRT.FID
import java.io.*;
import java.nio.file.*;
import java.security.MessageDigest;
import java.util.*;
import com.google.gson.*;
import ghidra.app.script.GhidraScript;
import ghidra.feature.fid.db.*;
import ghidra.feature.fid.hash.FidHashQuad;

public abstract class CrtFidSupport extends GhidraScript {
    protected Path root;
    protected final Gson gson = new GsonBuilder().setPrettyPrinting().serializeNulls().create();

    protected void guard(String project) throws Exception {
        String property = System.getProperty("crt.fid.run");
        if (property == null) throw new IOException("missing isolated run property");
        root = Path.of(property).toRealPath();
        var locator = state.getProject().getProjectLocator();
        if (!Path.of(locator.getLocation()).toRealPath().equals(root.resolve("projects")) ||
            !locator.getName().equals(project)) {
            throw new IOException("not the expected scratch project");
        }
        if (!Path.of(System.getProperty("user.home")).toRealPath().equals(root.resolve("home"))) {
            throw new IOException("nonisolated preferences");
        }
    }

    protected JsonElement readJson(String name) throws Exception {
        try (Reader reader = Files.newBufferedReader(root.resolve(name))) {
            return JsonParser.parseReader(reader);
        }
    }

    protected void output(String name, Object value) throws Exception {
        try (Writer writer = Files.newBufferedWriter(root.resolve(name), StandardOpenOption.CREATE_NEW)) {
            gson.toJson(value, writer);
        }
    }

    protected String sha256(Path path) throws Exception {
        return HexFormat.of().formatHex(MessageDigest.getInstance("SHA-256").digest(Files.readAllBytes(path)));
    }

    // Called BEFORE analysis and AGAIN immediately before opening any query service.
    // Settings writes stay in this run's isolated JVM user/settings directories.
    protected FidFile onlyDatabase(boolean enableCustom) throws Exception {
        FidFileManager manager = FidFileManager.getInstance();
        for (FidFile file : manager.getFidFiles()) file.setActive(false);
        FidFile custom = null;
        if (enableCustom) {
            custom = manager.addUserFidFile(root.resolve("crt.fidb").toFile());
            if (custom == null || custom.isInstalled()) throw new IOException("invalid custom FID");
            custom.setActive(true);
        }
        List<String> active = new ArrayList<>();
        for (FidFile file : manager.getFidFiles()) {
            if (!file.isActive()) continue;
            if (file.isInstalled() || !Path.of(file.getPath()).toRealPath().equals(root.resolve("crt.fidb"))) {
                throw new IOException("foreign FID active: " + file.getPath());
            }
            active.add(file.getPath());
        }
        if (active.size() != (enableCustom ? 1 : 0)) throw new IOException("FID isolation failed");
        return custom;
    }

    protected Map<String, Object> hash(FidHashQuad q) {
        if (q == null) return null;
        Map<String, Object> result = new LinkedHashMap<>();
        result.put("full", String.format("%016x", q.getFullHash()));
        result.put("specific", String.format("%016x", q.getSpecificHash()));
        result.put("codeUnitSize", q.getCodeUnitSize());
        result.put("specificHashAdditionalSize", q.getSpecificHashAdditionalSize());
        return result;
    }
}
