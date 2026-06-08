namespace Scop.Object;

public static class ObjectManager
{
    private static readonly string ContextPath = Path.Combine(AppContext.BaseDirectory, "Assets", "Objects");

    private static List<string> _objects = [];

    public static void Init()
    {
        _objects = ObjectUtils.FetchObjectFiles(ContextPath);
    }
}
