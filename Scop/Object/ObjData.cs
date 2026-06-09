namespace Scop.Object;

public struct ObjVertex(float x, float y, float z)
{
    public float X = x;
    public float Y = y;
    public float Z = z;
}

public struct ObjTexCoord(float u, float v)
{
    public float U = u;
    public float V = v;
}

public struct ObjNormal(float x, float y, float z)
{
    public float X = x;
    public float Y = y;
    public float Z = z;
}

public struct ObjFaceVertex(int vertexIndex, int? textureIndex, int? normalIndex)
{
    public int  VertexIndex  = vertexIndex;
    public int? TextureIndex = textureIndex;
    public int? NormalIndex  = normalIndex;
}

public struct ObjFace()
{
    public List<ObjFaceVertex> Vertices = [];
}

public struct ObjGroup(string? name)
{
    public string?       Name  = name;
    public List<ObjFace> Faces = [];
}

public struct ObjModel()
{
    public List<ObjVertex>   Vertices  = [];
    public List<ObjTexCoord> TexCoords = [];
    public List<ObjNormal>   Normals   = [];
    public List<ObjGroup>    Groups    = [];
}
