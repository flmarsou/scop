namespace Scop.Object;

public static class ObjManager
{
    private static readonly string ContextPath = Path.Combine(AppContext.BaseDirectory, "Assets", "Objects");

    private static List<string> _objectFiles = [];
    private static int          _objectIndex = 0;

    public static void Refresh()
    {
        _objectFiles = ObjUtils.FetchObjectFiles(ContextPath);
        _objectIndex = 0;
    }

    public static string? GetCurrent()
    {
        if (_objectFiles.Count == 0)
            return (null);

        return (_objectFiles[_objectIndex]);
    }

    public static string? GetNext()
    {
        if (_objectFiles.Count == 0)
            return (null);

        if (++_objectIndex >= _objectFiles.Count)
            _objectIndex = 0;

        return (_objectFiles[_objectIndex]);
    }

    public static string? GetPrev()
    {
        if (_objectFiles.Count == 0)
            return (null);

        if (--_objectIndex < 0)
            _objectIndex = _objectFiles.Count - 1;

        return (_objectFiles[_objectIndex]);
    }
}
