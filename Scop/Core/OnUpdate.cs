using Scop.Input;
using Silk.NET.Input;

namespace Scop;

public partial class Program
{
    private static void OnUpdate(double deltaTime)
    {
        if (InputManager.IsKeyDown(Key.Escape))
            _window!.Close();
    }
}
