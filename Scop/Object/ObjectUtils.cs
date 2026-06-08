using Scop.Utils;

namespace Scop.Object;

public static class ObjectUtils
{
    public static List<string> FetchObjectFiles(string path)
    {
        if (!Directory.Exists(path))
            throw new DirectoryNotFoundException($"ObjectUtils - Directory not found: \"{path}\"");

        List<string> objectFiles = [];

        foreach (var file in Directory.GetFiles(path))
        {
            var relativePath = Path.GetRelativePath(AppContext.BaseDirectory, file);

            if (!Path.GetExtension(file).Equals(".obj", StringComparison.OrdinalIgnoreCase))
            {
                Logger.Warning($"ObjectUtils - Wrong extension \"{relativePath}\", skipping");
                continue ;
            }

            Logger.Info($"ObjectUtils - Fetched \"{relativePath}\"");
            objectFiles.Add(file);
        }

        return (objectFiles);
    }
}
