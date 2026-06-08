using Silk.NET.Maths;
using Silk.NET.Windowing;

namespace Scop;

public partial class Program
{
    private static IWindow? _window;

    private static void Main()
    {
        var options = WindowOptions.Default with
        {
            Size  = new Vector2D<int>(800, 600),
            Title = "Scop - by flmarsou",
        };

        _window = Window.Create(options);

        _window.Load   += OnLoad;
        _window.Update += OnUpdate;
        _window.Render += OnRender;

        _window.Run();
    }
}
