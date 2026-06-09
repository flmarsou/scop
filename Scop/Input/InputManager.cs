using Silk.NET.Input;

namespace Scop.Input;

public static class InputManager
{
    private static readonly bool[] _keys      = new bool[349];
    private static readonly bool[] _prevKeys  = new bool[349];

    private static readonly bool[] _mouse     = new bool[13];
    private static readonly bool[] _prevMouse = new bool[13];

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

    public static void Update()
    {
        Array.Copy(_keys,  _prevKeys,  349);
        Array.Copy(_mouse, _prevMouse, 13);
    }

    public static bool IsKeyDown(Key key)                 => _keys[(int)key];
    public static bool IsKeyPressed(Key key)              => _keys[(int)key] && !_prevKeys[(int)key];

    public static bool IsMouseDown(MouseButton button)    => _mouse[(int)button];
    public static bool IsMousePressed(MouseButton button) => _mouse[(int)button] && !_prevMouse[(int)button];
}
