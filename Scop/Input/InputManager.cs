using Silk.NET.Input;

namespace Scop.Input;

public static class InputManager
{
    private static readonly bool[] _keys  = new bool[349];
    private static readonly bool[] _mouse = new bool[13];

    public static void Init(IInputContext input)
    {
        foreach (var keyboard in input.Keyboards)
        {
            keyboard.KeyDown += (_, key, _) => _keys[(int)key] = true;
            keyboard.KeyUp   += (_, key, _) => _keys[(int)key] = false;
        }

        foreach (var mouse in input.Mice)
        {
            mouse.MouseDown += (_, mouse) => _mouse[(int)mouse] = true;
            mouse.MouseUp   += (_, mouse) => _mouse[(int)mouse] = false;
        }
    }

    public static bool IsKeyDown(Key key)              => _keys[(int)key];
    public static bool IsMouseDown(MouseButton button) => _mouse[(int)button];
}
