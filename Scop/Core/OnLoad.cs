using Scop.Input;
using Silk.NET.Input;

namespace Scop;

public partial class Program
{
    private static void OnLoad()
    {
        InputManager.Init(_window!.CreateInput());
    }
}
