#include "App.hpp"

namespace Scop
{

void App::run(const std::string model_filename)
{
    _parse_object_file(model_filename);
}

void App::_parse_object_file(const std::string& model_filename)
{
    _check_valid_extension(model_filename);
}

void _check_valid_extension(const std::string& model_filename)
{
    const std::string file_extension = get_file_extension(model_filename);

    if (file_extension.length() == 0)
    {
        throw std::runtime_error("Missing extension");
    }
    else if (file_extension != "obj")
    {
        throw std::runtime_error("Expecting .obj file");
    }
}

}
