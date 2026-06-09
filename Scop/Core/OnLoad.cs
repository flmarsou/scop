using System.Drawing;
using Scop.Input;
using Scop.Object;
using Scop.Utils;
using Silk.NET.Input;
using Silk.NET.OpenGL;

namespace Scop;

public partial class Program
{
    private static GL?  _gl;
    private static uint _vao;
    private static uint _vbo;
    private static uint _program;
    private static int  _vertexCount;

    private static ObjModel? _selectedModel;

    private static void OnLoad()
    {
        // --- Input ---
        InputManager.Init(_window!.CreateInput());

        // --- OpenGL ---
        _gl = _window.CreateOpenGL();

        // --- Object ---
        ObjManager.Refresh();

        _selectedModel = ObjParser.Parse(ObjManager.GetCurrent());
    }
}
