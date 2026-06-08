namespace Scop.Object;

public static class ObjManager
{
    private static readonly string ContextPath = Path.Combine(AppContext.BaseDirectory, "Assets", "Objects");

    private static List<string> _objectFiles = [];

    public static void Init()
    {
        _objectFiles = ObjUtils.FetchObjectFiles(ContextPath);
    }
}
