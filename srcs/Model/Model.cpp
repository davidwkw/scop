#include "../include/Model.hpp"
#include <string>
#include <vector>

namespace Scop
{

Model::Model(const std::string &filename): model_name(), vertices(), smooth_shading(), faces(), material_filename(), material_name()
{
    parse_object_file(filename);
}

Model::~Model(){}

void Model::parse_object_file(const std::string& filename)
{
    check_valid_extension(filename);
    parse_obj_file_to_instance(filename);
}

void Model::check_valid_extension(const std::string& filename)
{
    const std::string file_extension = get_file_extension(filename);

    if (file_extension.length() == 0)
    {
        throw std::runtime_error("Missing extension");
    }
    else if (file_extension != ".obj")
    {
        throw std::runtime_error("Expecting .obj file");
    }
}

void Model::parse_obj_file_to_instance(const std::string& filename)
{
    std::ifstream   model_file_stream;
    std::string     line;

    model_file_stream.open(filename);
    if (!model_file_stream)
    {
        throw std::runtime_error("Unable to path given");
    }
    while (std::getline(model_file_stream, line))
    {
        line = remove_comment(line);
        line = trim_ws(line);
        if (line.empty())
            continue;
        parse_obj_file_line(line);
    }
}

void Model::parse_obj_file_line(const std::string &line)
{
    std::vector<std::string> line_tokens = tokenise_str(line);
    if (vector.size() < 2)
        throw std::runtime_error("Misconfigured .obj file");
    if (line_tokens[0] == "v")
        parse_vertex(line_tokens);
    else if (line_tokens[0] == "f")
        parse_face(line_tokens);
    else if (line_tokens[0] == "s")
        smooth_shading = (line_tokens[1] == "on");
    else if (line_tokens[0] == "o")
        model_name = line_tokens[1];
    else if (line_tokens[0] == "mtllib")
        material_name = line_tokens[1];
    else if (line_tokens[0] == "usemtl")
        material_filename = line_tokens[1];
}

void Model::parse_vertex(const std::vector<std::string> &line_tokens)
{
    if (line_tokens < 4)
        throw std::runtime_error("Invalied vertex format in .obj file");
    Vertex vertex;

    vertex.x = string_to_type<float>(line_tokens[1]);
    vertex.y = string_to_type<float>(line_tokens[2]);
    vertex.z = string_to_type<float>(line_tokens[3]);
    if (line_tokens > 4)
        vertex.w = string_to_type<float>(line_tokens[4]);
    vertices.push_back(vertex);
}

void Model::parse_face(const std::vector<std::string> &line_tokens)
{
    if (line_tokens < 4)
        throw std::runtime_error("Face has to form a triangle at minimum in .obj file");

    Face face;

    for (std::vector<std::string>::iterator it = line_tokens.begin(); it != line.end(); it++)
    {
        std::vector<std::string>    tokens;
        FaceData                    face_data;
        
        tokens = tokenise_str(*it);
        switch (tokens.size())
        {
            case 3:
                face_data.vertex_normal_index == string_to_type<int>(tokens[2]);
            case 2:
                face_data.texture_vertex_index == string_to_type<int>(tokens[1]);
            case 1:
                face_data.vertex_index == string_to_type<int>(tokens[0]);
                break;
            default:
                throw std::runtime_error("Invalid face format");
        }
        face.data.push_back(face_data);
    }
    faces.push_back(face);
}

}