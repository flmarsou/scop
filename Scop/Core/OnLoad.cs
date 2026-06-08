using Scop.Input;
using Scop.Object;
using Scop.Utils;
using Silk.NET.Input;

namespace Scop;

public partial class Program
{
    private static void OnLoad()
    {
        InputManager.Init(_window!.CreateInput());

        try
        {
            ObjManager.Init();
        }
        catch (Exception ex)
        {
            Logger.Error(ex.ToString());

            _window!.Close();
        }
    }
}
