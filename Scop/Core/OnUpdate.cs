using Scop.Input;
using Scop.Object;
using Scop.Utils;
using Silk.NET.Input;

namespace Scop;

public partial class Program
{
    private static string? _selectedObject;

    private static void OnUpdate(double deltaTime)
    {
        if (InputManager.IsKeyDown(Key.Escape))
            _window!.Close();

        if (InputManager.IsKeyPressed(Key.R))
        {
            try
            {
                ObjManager.Refresh();
            }
            catch (Exception ex)
            {
                Logger.Error(ex.ToString());

                _window!.Close();
            }

            _selectedObject = ObjManager.GetCurrent();
        }
        else if (InputManager.IsKeyPressed(Key.Left))
            _selectedObject = ObjManager.GetPrev();
        else if (InputManager.IsKeyPressed(Key.Right))
            _selectedObject = ObjManager.GetNext();

        InputManager.Update();
    }
}
