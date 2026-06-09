using System.Globalization;

namespace Scop.Object;

public static class ObjParser
{
    public static ObjModel? Parse(string? file)
    {
        if (file == null || !File.Exists(file))
            return (null);

        var model        = new ObjModel();
        var currentGroup = new ObjGroup(null);

        foreach (var line in File.ReadLines(file))
        {
            var parts = line.Split(' ', StringSplitOptions.RemoveEmptyEntries);

            if (parts.Length == 0 || parts[0].StartsWith('#'))
                continue ;

            switch (parts[0].ToLower())
            {
                case ("v"):
                    model.Vertices.Add(ParseVertex(parts));
                    break ;

                case ("f"):
                    var face = ParseFace(parts);
                    currentGroup.Faces.Add(face);
                    break ;
            }
        }

        model.Groups.Add(currentGroup);

        return (model);
    }

    private static ObjVertex ParseVertex(string[] parts)
    {
        return new ObjVertex(
            x: ParseFloat(parts[1]),
            y: ParseFloat(parts[2]),
            z: ParseFloat(parts[3])
        );
    }

    private static ObjFace ParseFace(string[] parts)
    {
        var face = new ObjFace();

        for (var i = 1; i < parts.Length; ++i)
            face.Vertices.Add(ParseFaceVertex(parts[i]));

        return (face);
    }

    private static ObjFaceVertex ParseFaceVertex(string token)
    {
        var indices = token.Split('/');

        var vertexIndex  = int.Parse(indices[0]);
        var textureIndex = (int?)null;
        var normalIndex  = (int?)null;

        if (indices.Length > 1 && !string.IsNullOrEmpty(indices[1]))
            textureIndex = int.Parse(indices[1]);

        if (indices.Length > 2 && !string.IsNullOrEmpty(indices[2]))
            normalIndex = int.Parse(indices[2]);

        return (new ObjFaceVertex(vertexIndex, textureIndex, normalIndex));
    }

    private static float ParseFloat(string token) => float.Parse(token, CultureInfo.InvariantCulture.NumberFormat);
}
