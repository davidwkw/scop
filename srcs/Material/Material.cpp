#include "Material.hpp"
#include <string>

namespace Scop
{

Material::Material(const std::string &filename)
{
    parse_material_file(filename);
}

Material::~Material(){}

void Material::parse_material_file(const std::string &filename)
{
    check_valid_extension(filename);
    parse_mtl_file_to_instance(filename);
}

void Material::check_valid_extension(const std::string& filename)
{
    const std::string file_extension = get_file_extension(filename);

    if (file_extension.length() == 0)
        throw std::runtime_error("Missing extension");
    else if (file_extension != ".mtl")
        throw std::runtime_error("Expecting .mtl file");
}

void Material::parse_mtl_file_to_instance(const std::string& filename)
{
    std::ifstream   mtl_file_stream;
    std::string     line;

    mtl_file_stream.open(filename);
    if (!mtl_file_stream)
        throw std::runtime_error("Unable to open file at path given");
    while (std::getline(mtl_file_stream, line))
    {
        line = remove_comment(line);
        line = trim_ws(line);
        if (line.empty())
            continue;
        parse_mtl_file_line(line);
    }
}

void Material::parse_obj_file_line(const std::string &line)
{
    std::vector<std::string> line_tokens = tokenise_str(line);
    if (vector.size() < 2)
        throw std::runtime_error("Misconfigured .obj file");
    if (line_tokens[0] == "newmtl")
        material_name = line_tokens[1];
    else if (line_tokens[0] == "illum")
        illumination_model = string_to_type<int>(line_tokens[1]);
    else if (line_tokens[0] == "d")
        dissolve = string_to_type<float>(line_tokens[1]);
    else if (line_tokens[0] == "Ni")
        optical_density = string_to_type<float>(line_tokens[1]);
    else if (line_tokens[0] == "Ns")
        specular_exponent = string_to_type<float>(line_tokens[1]);
    else if (line_tokens[0] == "ka")
        parse_reflectivity(line_tokens, ambient_reflectivity);
    else if (line_tokens[0] == "kd")
        parse_reflectivity(line_tokens, diffuse_reflectivity);
    else if (line_tokens[0] == "ks")
        parse_reflectivity(line_tokens, specular_reflectivity);
}

void Material::parse_reflectivity(const std::vector<std::string> &line_tokens, RGB &reflectivity)
{
    reflectivity.red = string_to_type<float>(line_tokens[0]);
    reflectivity.green = reflectivity.red;
    reflectivity.blue = reflectivity.red;
    switch (line_tokens.size())
    {
        case 3:
            reflectivity.blue = string_to_type<float>(line_tokens[2]);
        case 2:
            reflectivity.green = string_to_type<float>(line_tokens[1]);
        case 1:
            break;
        default:
            throw std::runtime_error("Invalid reflectivity value");
    }
}

}