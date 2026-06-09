using Scop.Input;
using Scop.Object;
using Silk.NET.Input;

namespace Scop;

public partial class Program
{
    private static ObjModel? _selectedModel;

    private static void OnUpdate(double deltaTime)
    {
        if (InputManager.IsKeyDown(Key.Escape))
            _window!.Close();

        if (InputManager.IsKeyPressed(Key.R))
        {
            ObjManager.Refresh();

            _selectedModel = ObjParser.Parse(ObjManager.GetCurrent());
        }
        else if (InputManager.IsKeyPressed(Key.Left))
            _selectedModel = ObjParser.Parse(ObjManager.GetPrev());
        else if (InputManager.IsKeyPressed(Key.Right))
            _selectedModel = ObjParser.Parse(ObjManager.GetNext());

        InputManager.Update();
    }
}
