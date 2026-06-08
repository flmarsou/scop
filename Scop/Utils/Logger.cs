namespace Scop.Utils;

public enum LogLevel
{
    None,
    Success,
    Info,
    Warning,
    Error,
}

public static class Logger
{
    private static string Timestamp => DateTime.Now.ToString("HH:mm:ss.fff");

    public static void Log(string message, LogLevel level)
    {
        var (label, color) = level switch
        {
            LogLevel.Success => (" [  OK  ] ", ConsoleColor.Green),
            LogLevel.Info    => (" [ INFO ] ", ConsoleColor.Cyan),
            LogLevel.Warning => (" [ WARN ] ", ConsoleColor.Yellow),
            LogLevel.Error   => (" [  KO  ] ", ConsoleColor.Red),
            _                => ("", ConsoleColor.White)
        };

        Console.Write(Timestamp);

        Console.ForegroundColor = color;
        Console.Write(label);
        Console.ResetColor();

        Console.WriteLine(message);
    }

    public static void Success(string message) => Log(message, LogLevel.Success);
    public static void Info(string message)    => Log(message, LogLevel.Info);
    public static void Warning(string message) => Log(message, LogLevel.Warning);
    public static void Error(string message)   => Log(message, LogLevel.Error);
}
